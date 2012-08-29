/* Amil - assembleur miniature pour l'informatique de licence
 *        (Toy assembly langage interpreter)
 *
 * Copyright 2008, 2009 Pierre Boudes
 *
 * This file is part of Amil.
 *
 * Amil is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Amil is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Amil.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h> /* pour memcpy */
#include "moteur.h"
#include "ordre.h"

void trace(instruction_t *mem, int len, FILE *f);

void usage(int argc, char *argv[]);



extern int errno;

void
myperror(char *s)
{
  if (errno) {
  perror(s);
  }
  else {
    fprintf(stderr, s);
  }
}

int
main(int argc, char *argv[])
{
  instruction_t *mem = NULL;
  int len = 0;
  FILE *out = NULL;

  usage(argc, argv);

  /** Initialisation **/
  /* On parse le programme (premier argument) */
  printf("Parsing %s\n", argv[1]);
  mem = parse_fichier(argv[1], &len);
  if (!mem) {
    myperror("erreur de fichier (entree)\n");
    return EXIT_FAILURE;
  }
  printf(" done\n");

  /* On crée le fichier de sortie */
  printf("Creating %s\n", argv[2]);
  out = fopen(argv[2], "w");
  if (!out) {
    myperror("erreur de fichier (sortie)\n");
    return EXIT_FAILURE;
  }

  /** Execution  et trace **/
  trace(mem, len, out);
  fclose(out);
  return EXIT_SUCCESS;
}


void
usage(int argc, char *argv[])
{
  if (argc < 3) {
    fprintf(stderr, "usage: %s <programme.txt> <sortie.tex>\n", argv[0]);    
    exit(EXIT_FAILURE);
  }
}

#define NOMBRE_REGS 8

void
trace(instruction_t *mem, int len, FILE *f)
{
  processeur_t *proc;
  int modif;
  int i;
  int cp;
  int run = 1;
  int cycle = 0;
  char s[128];     /* buffer ligne de sortie */
  size_t sz = 128; /* largeur de la sortie */
  ordre_t *o;
  instruction_t *mem2;
  processeur_t *proc2;
  int dcols;

  proc2 = init_processeur();

  /****************************************************************
      Une première simulation complète construit les colonnes
  *****************************************************************/

  mem2 = malloc(len * sizeof(instruction_t));
  memcpy(mem2, mem, len * sizeof(instruction_t));

  o = ordre_creer(NOMBRE_REGISTRES + len + 2);

  /* modif = 0...NOMBRE_REGISTRES - 1 --> registre[modif]
     modif = NOMBRE_REGISTRES --> CP
     modif > NOMBRE_REGISTRES --> mem[modif - NOMBRE_REGISTRES - 1]
  */
  while (0 < run) {
    /* Dans la trace, on attrape aussi les lectures (greffon moche). */
    switch (mem2[proc2->cp].type) {
    case _ACTION_LECTURE_M2R: 
      ordre_inserer_element(o, mem2[proc2->cp].arg1 + NOMBRE_REGISTRES + 1);
      break;
    case _ACTION_LECTURE_P2R: 
      ordre_inserer_element(o, proc2->reg[mem2[proc2->cp].arg1]
			    + NOMBRE_REGISTRES + 1);
      break;
    default:
      ; /* rien */
    }
    run = execute_instruction_suivante(mem2, proc2, NULL, 0, &modif);
    if ((0 <= modif)  && (NOMBRE_REGISTRES != modif)) {
      ordre_inserer_element(o, modif);
    }
  }

  free(mem2);
  free(proc2);

   /****************************************************************
      Construction et écriture de la trace
  *****************************************************************/
  
  proc = init_processeur();

  /* On saute le noop initial */
  run = execute_instruction_suivante(mem, proc, s, sz, &modif);
  
  dcols = ordre_get_taille(o);

  printf("dcols = %d\n", dcols);

  /* Début du tableau  (déclaration des colonnes) */
  fprintf(f, "\\begin{tabular}[c]{l||");
  for (i = 0; i < dcols + 2; i++) {
    fprintf(f, "c|");
  }
  fprintf(f, "}\n");

  /* Titraille du tableau */
  fprintf(f, "\\hline\n \\emph{Instructions} & Cycles & CP");
  for (i = 0; i < dcols; i++) {
    int x;
    x = ordre_get_element(o, i);
    if (x < NOMBRE_REGISTRES) {
      fprintf(f, "& r%d", x);
    }
    else {
      fprintf(f, "& %d", x - NOMBRE_REGISTRES - 1);
    }
  }
  fprintf(f, "\\\\ \\hline\n");

  /* ligne 'initialisation' */
  fprintf(f, "\\hfill Initialisation & 0 & 1 ");

  for (i = 0; i < dcols; i++) {
    int x;
    x = ordre_get_element(o, i);
    if (x < NOMBRE_REGISTRES) {
      fprintf(f, "& ? ");
    }
    else {
      instruction2texte(mem + x - NOMBRE_REGISTRES - 1, s, sz);
      fprintf(f, "& %s ", s);
    }
  }
  fprintf(f, "\\\\ \\hline");

  /* La trace */
  while (0 < run) {
    /* execution de l'instruction et recuperation des infos */
    cp = proc->cp;
    run = execute_instruction_suivante(mem, proc, s, sz, &modif);
    cycle++;

    /* La variable cp contient l'adresse de l'instruction exécutée,
       cycle le numéro de cycle, proc->cp le cp courant, s un
       commentaire d'exécution, modif le code de la colonne ayant été
       modifiée ou -1 */

    /* instruction */
    fprintf(f, " \\commentaire{%s} ", s);
    instruction2texte(mem + cp, s, sz);
    fprintf(f, "\\C{%s}", s);

    /* cycle */
    fprintf(f, " & %d", cycle);

    /* cp */
    if (NOMBRE_REGISTRES == modif) {
      fprintf(f, " & \\textbf{%d}", proc->cp);
    } else {
      fprintf(f, " & %d ", proc->cp);      
    }

    /* registres et mémoires */
    for (i = 0; i < dcols; i++) {
      int x;
      x = ordre_get_element(o, i);
      if (x == modif) {
	if (x < NOMBRE_REGISTRES) {
	  fprintf(f, " & %d", proc->reg[x]);
	}
	else {
	  instruction2texte(mem + x - NOMBRE_REGISTRES - 1, s, sz);
	  fprintf(f, " & %s", s);
	}
      }
      else {
	fprintf(f, " &");
      }
    }

    /* fin de ligne */
    fprintf(f, "\\\\ \\hline\n");
  } 
  /* fin du tableau */
  fprintf(f, "\\end{tabular}");

  free(proc);
}
