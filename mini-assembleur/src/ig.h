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
/* ig.h */
#ifndef _ig_h
#define _ig_h
#include <gtk/gtk.h>
#include "moteur.h"

/* Le grand struct */
typedef struct {
  GtkWidget *fenetre_principale;
  GtkWidget *dialogue_quitter;
  GtkWidget *dialogue_charger;
  GtkWidget *dialogue_enregistrer;
  GtkWidget *cp;  
  GtkWidget *reg[NOMBRE_REGISTRES];
  GtkWidget *console;
  GtkTextBuffer *buffer_console;
  /*  GtkWidget *pasapas; */
  GtkWidget *horloge;
  int cycles;
  /* La vue memoire */
  GtkWidget *fenetre_memoire;
  GtkWidget *memoire;
  GtkTextBuffer *memoire_buffer;
  GtkTextTag *tagy;
  GtkTextTag *tagg;
} ig_t;


void ig_faire_fenetre_principale();
void ig_faire_fenetre_memoire();
void ig_maj_registre(mot_t, registre_t);
void ig_maj_cp(mot_t);
void ig_maj_console(gchar *);
void ig_raz_registres();
void ig_maj_cycles(int);
void ig_inc_cycles();
void ig_fermer_fenetre_memoire();
void ig_ouvrir_fenetre_memoire();
void ig_maj_memoire(instruction_t *mem, int len, int l, int cp, int flag_num);
void ig_no_emph_proc();
void ig_emph_cp();
void ig_enlumine_memoire(int ligne, int flag_num);

#endif
