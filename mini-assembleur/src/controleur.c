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
/* -*- coding: utf-8 -*- */
/* controleur.c */
#include <stdlib.h>
#include <stdio.h>
#include "controleur.h"
#include "moteur.h"
#include "ig.h"

instruction_t *mem = NULL;
processeur_t *proc = NULL;
int len = 0;
int stopped = 0;
#define LARGEUR_LIGNE_SORTIE 128
char buffer_sortie[LARGEUR_LIGNE_SORTIE];

void 
ig_charger(GtkWidget *w, gpointer p)
{
  gchar *fichier;

  instruction_t *mem_bkp;
  int len_bkp;


  switch(gtk_dialog_run(GTK_DIALOG(p))){
  case GTK_RESPONSE_ACCEPT:
    fichier = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(p));
    gtk_widget_hide(p);
    break;
  case GTK_RESPONSE_CANCEL:
  case GTK_RESPONSE_NONE:
  default:
    gtk_widget_hide(p);
    return;
  }


  /* Parse le fichier et le charge en mémoire */
  len_bkp = len;
  mem_bkp = mem;
  mem = parse_fichier(fichier, &len);
  if (!mem) {
    ig_maj_console("Erreur de fichier\n");
    mem  = mem_bkp;
    len = len_bkp;
    return;
  }
  free(mem_bkp);

  /* Crée un processeur ou remet à zéro le CP du processeur existant */

  if (!proc) {
    proc = init_processeur();
  } else {
    proc->cp = 0;
  }
  ig_maj_cp(0);
  ig_maj_cycles(0);  

  stopped = 0;

  /* Affichage de la mémoire */
  ig_maj_memoire(mem, len, 0, proc->cp, 1);

  ig_maj_console("Programme lu, processeur prêt.\n");
}

void
ig_dump(GtkWidget *w, gpointer p)
{
  if (!mem) {
    ig_maj_console("*Pas de programme*\n");
    return;
  }

  /* Affichage dans le terminal */

  ig_maj_console("*Affichage dans le terminal*\n");
  printf("----- Contenu de la memoire ---------\n");  
  mem2texte(mem, len, stdout);
  printf("----- Fin                   ---------\n");  

  /* Enregistrement dans un fichier */
  ig_enregistrer(w, p);
}

void
ig_enregistrer(GtkWidget *w, gpointer p)
{
  gchar *fichier;
  FILE *f;

  switch(gtk_dialog_run(GTK_DIALOG(p))){
  case GTK_RESPONSE_ACCEPT:
    fichier = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(p));
    gtk_widget_hide(p);
    break;
  case GTK_RESPONSE_CANCEL:
  case GTK_RESPONSE_NONE:
  default:
    gtk_widget_hide(p);
    return;
  }

  f = fopen(fichier,"w");
  mem2texte(mem, len, f);
  fclose(f);

  ig_maj_console("Fichier enregistré");
}

void
ig_maj_processeur(int modif)
{
  ig_no_emph_proc(modif);    
  
  /* Maj CP */
  ig_maj_cp(proc->cp);

  /* Maj horloge (cycles) */
  ig_inc_cycles();

  if (est_un_registre(modif)) {
    ig_maj_registre(proc->reg[modif], modif);
  } 
  if (NOMBRE_REGISTRES == modif) {
    ig_emph_cp();    
  }
}

void
ig_pas_a_pas(GtkWidget *w, gpointer p)
{
  int r;
  int line;
  int modif;
 if (!mem) {
    ig_maj_console("Charger un programme !\n");
    return;
  }
  if (stopped) {
    ig_maj_console("Exécution terminée !\n");
    return;
  }

  line = proc->cp;

  r = execute_instruction_suivante(mem, proc, 
				   buffer_sortie, 
				   LARGEUR_LIGNE_SORTIE, 
				   &modif);

  if (1 > r) {
    stopped = 1;
  }

  if (-1 == r) {
    snprintf(buffer_sortie,
	     LARGEUR_LIGNE_SORTIE, 
	     "opération interdite -- fin anormale !\n");
  }

  /* Affichage dans la console */
  ig_maj_console(buffer_sortie);

  /* Affichage de la mémoire */
  ig_maj_memoire(mem, len, line, proc->cp, 1);

  if (NOMBRE_REGISTRES < modif) {
    ig_enlumine_memoire(modif - NOMBRE_REGISTRES - 1, 1);
  }

 /* Affichage du processeur */
  else {
    ig_maj_processeur(modif);
  } 
}

gboolean
ig_execution_auto(gpointer p)
{
  if (stopped) {
    return FALSE;
  }
  ig_pas_a_pas(NULL, p);
  return TRUE;
}

void
ig_stop(GtkWidget *w, gpointer p)
{
  stopped = 1;
}

void
ig_executer(GtkWidget *w, gpointer p)
{
  if (!mem) {
    ig_maj_console("Charger un programme !\n");
    return;
  }
  if (stopped) {
    ig_maj_console("Exécution terminée !\n");
    return;
  }

  g_timeout_add(1000, ig_execution_auto, NULL);
  return;
}

void 
ig_quitter(GtkWidget *w, gpointer p)
{
  switch (gtk_dialog_run(GTK_DIALOG(p))) {
  case GTK_RESPONSE_OK:
    gtk_main_quit();
    break;
  case GTK_RESPONSE_CANCEL:
  case GTK_RESPONSE_NONE:
  default:
    gtk_widget_hide(p);  
  }
}

void
ig_raz_proc(GtkWidget *w, gpointer p)
{
  ig_raz_registres();
  ig_raz_cp(w, p);
}

void
ig_raz_cp(GtkWidget *w, gpointer p)
{
  if (proc) {
    proc->cp = 0;
    ig_maj_cp(0);
    stopped = 0;
    if (mem) {
      ig_maj_memoire(mem, len, 0, proc->cp, 1);
    }
  }
  ig_maj_cycles(0);
}

void
ig_raz_cycles(GtkWidget *w, gpointer p)
{
  ig_maj_cycles(0);
}

void ig_voir_memoire(GtkWidget *w, gpointer p)
{
  ig_ouvrir_fenetre_memoire();
  if (mem) {
    ig_maj_memoire(mem, len, 0, proc->cp, 1);
  }
}

void ig_masquer_memoire(GtkWidget *w, gpointer p)
{
  ig_fermer_fenetre_memoire();
}
