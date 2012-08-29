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
/* ordre.c */
#include <stdlib.h>
#include "ordre.h"


ordre_t *
ordre_creer(unsigned int taillemax)
{
  ordre_t *o;
  o = malloc(sizeof(ordre_t)); 
  o->t = calloc(taillemax, sizeof(element_t));
  o->taille = 0;
  return o;
}


int
ordre_get_indice(ordre_t *o, element_t x)
{
  int i;
  /* Recherche par parcours naif */
  for (i = 0; i < o->taille; i++) {
    if (o->t[i] == x) {
      return i;
    }
  }
  return -1; /* L'element x ne se trouve pas dans l'ordre */
}

element_t
ordre_get_element(ordre_t *o, unsigned int i)
{
  if (i < o->taille) {
    return o->t[i];
  }
  return -1;
}

unsigned int 
ordre_get_taille(ordre_t *o)
{
  return o->taille;
}


unsigned int
ordre_inserer_element(ordre_t *o, element_t x)
{
  int i;
  if (0 <= ordre_get_indice(o, x)) {
    /* L'entrée x existe déjà */
    return -1;
  }
  /* Decalage des elements plus grands que x */
  for (i = o->taille - 1; i >= 0; i--) {
    if (o->t[i] > x) {
      o->t[i + 1] = o->t[i];
    }
    else break;
  }
  /* insertion de x a sa place */
  o->t[i + 1] = x;
  o->taille++;
  return i + 1;
}

ordre_t *
ordre_detruire(ordre_t *o)
{
  free(o->t);
  free(o);
  return NULL;
}

