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
#include <stdio.h>
#include <gtk/gtk.h>
#include "moteur.h"
#include "ig.h"

void
usage(int argc, char *argv[]);

int
main(int argc, char *argv[])
{
  /*
  instruction_t *mem;
  processeur_t *proc;
  int len;
  */

  gtk_init(&argc, &argv);

  ig_faire_fenetre_principale();
  ig_faire_fenetre_memoire();

  /* Boucle principale */
  gtk_main();
  
  return EXIT_SUCCESS;
}

