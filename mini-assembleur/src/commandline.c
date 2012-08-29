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
#include "moteur.h"

void
usage(int argc, char *argv[]);


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
  instruction_t *mem;
  processeur_t *proc;
  int len;
  char s[81];     /* buffer ligne de sortie */
  size_t sz = 81; /* largeur de la sortie */

  usage(argc, argv);

  /* Initialisation */
  printf("Parsing %s\n", argv[1]);
  mem = parse_fichier(argv[1], &len);
  if (!mem) {
    myperror("erreur de fichier\n");
    return EXIT_FAILURE;
  }
  printf(" done\n");

  proc = init_processeur();
  printf("*** Programme lu ****\n");
  /* Sortie */
  mem2texte(mem, len, stdout);

  /* Execution */
  while (0 < execute_instruction_suivante(mem, proc, s, sz, NULL)) {
    printf("**Instruction executee**\n");
    printf("%s", s);
    printf("**Nouvel etat**\n");
    printf("***Processeur\n");
    /* Sortie */
    proc2texte(proc);
    printf("***Memoire\n");
    mem2texte(mem, len, stdout);    
  }
  return EXIT_SUCCESS;
}


void
usage(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "usage: %s <programme.txt>\n", argv[0]);    
    exit(EXIT_FAILURE);
  }
}

