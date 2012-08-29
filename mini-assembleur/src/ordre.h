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
/* ordre.h */
#ifndef _ordre_h
#define _ordre_h


typedef int element_t;

typedef struct {
  unsigned int taille;
  element_t *t;
} ordre_t;

ordre_t * ordre_creer(unsigned int taillemax);
int ordre_get_indice(ordre_t *o, element_t x);
element_t ordre_get_element(ordre_t *o, unsigned int i);
unsigned int ordre_get_taille(ordre_t *o);
unsigned int ordre_inserer_element(ordre_t *o, element_t x);
ordre_t * ordre_detruire(ordre_t *o);
#endif
