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
/* controleur.h */
#ifndef _controleur_h
#define _controleur_h
#include "ig.h"
#include "moteur.h"

void ig_charger(GtkWidget *, gpointer);
void ig_dump(GtkWidget *, gpointer);
void ig_pas_a_pas(GtkWidget *, gpointer);
void ig_executer(GtkWidget *, gpointer);
void ig_stop(GtkWidget *, gpointer);
void ig_quitter(GtkWidget *, gpointer);
void ig_enregistrer(GtkWidget *, gpointer);
void ig_voir_memoire(GtkWidget *, gpointer);
void ig_masquer_memoire(GtkWidget *, gpointer);
void ig_raz_proc(GtkWidget *, gpointer);
void ig_raz_cp(GtkWidget *, gpointer);
void ig_raz_cycles(GtkWidget *, gpointer);


#endif
