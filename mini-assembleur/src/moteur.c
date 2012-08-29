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
#include <stdlib.h>
#include <stdio.h>
#include <string.h> /* pour memset() ?? */
#include <strings.h> /* pour strncasecmp() */
#include <ctype.h> /* pour isspace() */
#include "moteur.h"

void myperror(char *);

/* parse_fichier()

   parse le fichier et l'encode dans la mémoire. Renvoie NULL si
   erreur, adresse de la mémoire sinon */

instruction_t *
parse_fichier(char *path, int *len)
{
  FILE *fl;
  instruction_t *mem;
  int lines = 0;
  int i;
  char s[128];


  if (NULL == (fl = fopen(path, "r"))) {
    myperror("Échec à l'ouverture du fichier !\n");
    return NULL;
  }

  /* décompte des lignes du fichier */
  while (fgets(s, 127, fl)){
    ++lines;
  }
  
 
  /* Allocation du tableau d'instructions */
  if (NULL == (mem = malloc( (lines + 2) * sizeof(instruction_t)))) {
    myperror("Echec malloc !\n");
    return NULL;
  }

  /* Retour au début du fichier */
  rewind(fl);

  /* Parse le fichier ligne à ligne */
  for (i = 1; i <= lines; i++) {
    if  (!fgets(s, 127, fl)) {
      myperror("Erreur fgets");
      return NULL;      
    }
    if (-1 == parse_ligne(mem + i, s)) {
      char str_err[81];  
      snprintf(str_err, 81, "Parse error line %d\n", i);
      myperror(str_err);
      return NULL;
    } 
  }

  mem[0].type = _ACTION_NOOP;
  mem[lines + 1].type = _ACTION_EOM;

  *len = lines + 1; 
  return mem;
}

/* parse_ligne() 

   Renvoie -1 si peut pas parser, 1 sinon. 
   Encode l'instruction lue dans ins.*/

int
parse_ligne(instruction_t *ins, char *s)
{
  return parse_instruction(ins, s);
}


/* action_match()


 Renvoie 1+strlen(action) si match */

int
action_match(const char *name, const char *s)
{
  if (0 == strncasecmp(name, s, strlen(name)) ) {
    return 1 + strlen(name);
  }
  return 0;
}

/* Renvoie 1 si succes, 0 sinon */
int
donnee_match(mot_t *x, char *s)
{
  return sscanf(s, "%hd", x);
}

int
unsigned_match(mot_t *x, char *s)
{
  return sscanf(s, "%hu", x);
}

int
adresse_match(mot_t *x, char *s)
{
  return sscanf(s, _MEM_PREFIXE"%hu", x) 
    || 
    sscanf(s, _MEM_PREFIXE_CAP"%hu", x);
}

int
registre_match(mot_t *x, char *s)
{
  return sscanf(s, _REG_PREFIXE"%hu", x) 
    || 
    sscanf(s, _REG_PREFIXE_CAP"%hu", x);
}

int
pointeur_match(mot_t *x, char *s)
{
  return sscanf(s, _POINT_PREFIXE"%hu", x) 
    || 
    sscanf(s, _POINT_PREFIXE_CAP"%hu", x);
}


int
est_ligne_vide(char *s)
{
  while (isspace(*s) && ('\0' != *s)) {
      s++;
  }
  return ('\n' == *s) 
    || ('\r'  == *s)  
    || ('\0'  == *s);   
}

char *
mot_suivant(char *s)
{
  while (!isspace(*s) && ('\0' != *s)) {
      s++;
  }
  while ((',' == *s) || isspace(*s)) {
    s++;
  }
  return s;
}

/* parse_instrution() 

   sous-routine de parse_ligne() parsant l'instruction. */


int
parse_instruction(instruction_t *ins, char *s)
{
  char *arg1;
  char *arg2;

  memset(ins, 0, sizeof ins);

  /* NOOP */
  if (action_match(_NOOP_STR, s)) {
    ins->type = _ACTION_NOOP;
  } 
  /* INIT */
  else if (action_match(_INIT_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (donnee_match(&(ins->arg1), arg1) 
	&& registre_match(&(ins->arg2), arg2)) {
      ins->type = _ACTION_INIT;
    }
    else {
      return -1;
    }
  }
  /* LECTURE */
  else if (action_match(_LECTURE_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (adresse_match(&(ins->arg1), arg1) 
	&& registre_match(&(ins->arg2), arg2)) {
      ins->type = _ACTION_LECTURE_M2R;
    }
    else if (pointeur_match(&(ins->arg1), arg1) 
	&& registre_match(&(ins->arg2), arg2)) {
      ins->type = _ACTION_LECTURE_P2R;      
    }
    else {
      return -1;
    }
  }
  /* ECRITURE */
  else if (action_match(_ECRITURE_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg1), arg1) 
	&& adresse_match(&(ins->arg2), arg2)) {
      ins->type = _ACTION_ECRITURE_R2M;
    }
    else if (registre_match(&(ins->arg1), arg1) 
	&& pointeur_match(&(ins->arg2), arg2)) {
      ins->type = _ACTION_ECRITURE_R2P;      
    }
    else {
      return -1;
    }
  }
  /* ADDITION */
  else if (action_match(_ADD_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg2), arg2)) {
      if (donnee_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_ADD_V2R;
      }
      else if (registre_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_ADD_R2R;	
      }
      else return -1;
    }
    else return -1;
  }
  /* SOUSTRACTION */
  else if (action_match(_SUBS_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg2), arg2)) {
      if (donnee_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_SUBS_V2R;
      }
      else if (registre_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_SUBS_R2R;	
      }
      else return -1;
    }
    else return -1;
  }
  /* MULTIPLICATION */
  else if (action_match(_MULT_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg2), arg2)) {
      if (donnee_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_MULT_V2R;
      }
      else if (registre_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_MULT_R2R;	
      }
      else return -1;
    }
    else return -1;
  }
  /* DIVISION */
  else if (action_match(_DIV_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg2), arg2)) {
      if (donnee_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_DIV_V2R;
      }
      else if (registre_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_DIV_R2R;	
      }
      else return -1;
    }
    else return -1;
  }
  /* ET */
  else if (action_match(_AND_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg2), arg2)) {
      if (donnee_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_AND_V2R;
      }
      else if (registre_match(&(ins->arg1), arg1)) {
	ins->type = _ACTION_AND_R2R;	
      }
      else return -1;
    }
    else return -1;
  }
  /* INVERSE */
  else if (action_match(_INVERT_STR, s)) {
    if (registre_match(&(ins->arg1), mot_suivant(s))) {
      ins->type = _ACTION_INVERT;
    }
    else return -1;
  }
  /* SAUT CONDITIONNEL */
  else if (action_match(_CONDJUMP_STR, s)) {
    arg1 = mot_suivant(s);
    arg2 = mot_suivant(arg1);
    if (registre_match(&(ins->arg1), arg1)
	&& 
	unsigned_match (&(ins->arg2), arg2)) {
      ins->type = _ACTION_CONDJUMP;
    }
    else return -1;    
  }
  /* SAUT */
  else if (action_match(_JUMP_STR, s)) {
    if (pointeur_match(&(ins->arg1), mot_suivant(s))) {
      ins->type = _ACTION_JUMP_P;
    } 
    else if (unsigned_match(&(ins->arg1), mot_suivant(s))) {
      ins->type = _ACTION_JUMP;
    }
    else return -1;
  }
  /* STOP */
  else if (action_match(_STOP_STR, s)) {
    ins->type = _ACTION_STOP;
  }
  else {
    if (!est_ligne_vide(s) && donnee_match(&(ins->arg1), s)) {
      ins->type = _ACTION_DATA;
    }
    else {
      ins->type = _ACTION_INCONNUE;      
    }
  }
  return 1;
}

/* initialisation du processeur */
processeur_t *
init_processeur()
{
  processeur_t *p;
  p = malloc(sizeof(processeur_t));
  if (NULL == p) {
    perror("Malloc !!");
    exit(EXIT_FAILURE);
  }
  memset(p, 0, sizeof(processeur_t));
  return p;
}

/* Renvoie 1 si l'instruction ins est une donnée, 0 sinon */
int
est_une_donnee(instruction_t *ins)
{
  return (_ACTION_DATA == ins->type);
}

/* Renvoie 0 si l'instruction ins est une véritable instruction, 0 si
   c'est une donnée */
int
est_une_instruction(instruction_t *ins)
{
  return ((_ACTION_DATA != ins->type) 
	  && (_ACTION_INCONNUE != ins->type)
	  && (_ACTION_EOM != ins->type));
}

int
est_une_adresse(mot_t x)
{
  return ( (0 < x) ); /* TODO COMPLETER PAR x < len... */
}

int
est_un_registre(registre_t x)
{
  return ((0 <= x) && (x < NOMBRE_REGISTRES));
}

int
execute_instruction_suivante(instruction_t mem[], 
			     processeur_t *p, 
			     char *s, size_t sz, 
			     int *modif)
{
  instruction_t ins = mem[p->cp];

  p->cp++;

  switch (ins.type) {

  case _ACTION_NOOP:
    snprintf(s, sz, "Pas d'operation\n");
    if (modif) {
      *modif = -1;
    }
    break;

  case _ACTION_INIT:
    if (est_un_registre(ins.arg2)) {
      p->reg[ins.arg2] = ins.arg1;
      snprintf(s, sz, 
	       "Initialisation du registre %hd à %hd\n", 
	       ins.arg2, ins.arg1);
      if (modif) {
	*modif = ins.arg2;
      }
    } 
    else return -1;
    break;

  case _ACTION_LECTURE_M2R:
    if (est_une_adresse(ins.arg1)
	&& est_une_donnee(mem + ins.arg1) 
	&& est_un_registre(ins.arg2)) {
      p->reg[ins.arg2] = mem[ins.arg1].arg1;
      snprintf(s, sz, 
	       "Lecture de la donnée d'adresse %hd dans le registre %hd\n", 
	       ins.arg1, ins.arg2);
      if (modif) {
	*modif = ins.arg2;
      }
    } 
    else return -1;
    break;


  case _ACTION_ECRITURE_R2M:
    if (est_un_registre(ins.arg1)
	&& est_une_adresse(ins.arg2)) {
      snprintf(s, sz, 
	       "Écriture du registre %hd à l'adresse %hd\n", 
	       ins.arg1, ins.arg2);
      mem[ins.arg2].arg1 = p->reg[ins.arg1];
      mem[ins.arg2].type = _ACTION_DATA;
      if (modif) {
	*modif = ins.arg2 + NOMBRE_REGISTRES + 1;
      }
    }
    else return -1;
    break;

  case _ACTION_ECRITURE_R2P:
    if (est_un_registre(ins.arg1) 
	&& est_un_registre(ins.arg2)
	&& est_une_adresse(p->reg[ins.arg2])) {
      snprintf(s, sz, 
	       "Écriture du registre %hd à l'adresse %hd\n", 
	       ins.arg1, p->reg[ins.arg2]);
      mem[p->reg[ins.arg2]].arg1 = p->reg[ins.arg1];
      mem[p->reg[ins.arg2]].type = _ACTION_DATA;
      if (modif) {
	*modif = p->reg[ins.arg2] + NOMBRE_REGISTRES + 1;
      }
    }
    else return -1;
    break;

  case _ACTION_LECTURE_P2R:
    if (est_un_registre(ins.arg1)
	&& est_une_adresse(p->reg[ins.arg1])
	&& est_une_donnee(mem + p->reg[ins.arg1])
	&& est_un_registre(ins.arg2)) {
      snprintf(s, sz, 
	       "Lecture de la donnée d'adresse %hd dans le registre %hd\n", 
	       p->reg[ins.arg1], ins.arg2);
      p->reg[ins.arg2] = mem[p->reg[ins.arg1]].arg1;
      if (modif) {
	*modif = ins.arg2;
      }
    }
    else return -1;
    break;

  case _ACTION_ADD_R2R:
    snprintf(s, sz, 
	    "Ajout de la valeur du registre %hd au registre %hd\n",
	    ins.arg1, ins.arg2);
    p->reg[ins.arg2] += p->reg[ins.arg1];
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_ADD_V2R:
    snprintf(s, sz,
	"Ajout de la valeur %hd au registre %hd\n",
	ins.arg1, ins.arg2);
    p->reg[ins.arg2] += ins.arg1;
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_SUBS_R2R:
    snprintf(s, sz, 
	    "Soustrait la valeur du registre %hd au registre %hd\n",
	    ins.arg1, ins.arg2);
    p->reg[ins.arg2] -= p->reg[ins.arg1];
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_SUBS_V2R:
    snprintf(s, sz,
	"Soustrait la valeur %hd au registre %hd\n",
	ins.arg1, ins.arg2);
    p->reg[ins.arg2] -= ins.arg1;
    if (modif) {
      *modif = ins.arg2;
    }
    break;
    
  case _ACTION_MULT_R2R:
   snprintf(s, sz, 
	    "Multiplie la valeur du registre %hd par celle du registre %hd\n",
	    ins.arg2, ins.arg1);
    p->reg[ins.arg2] *= p->reg[ins.arg1];
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_MULT_V2R:
    snprintf(s, sz,
	"Multiplie la valeur du registre %hd par %hd\n",
	ins.arg2, ins.arg1);
    p->reg[ins.arg2] *= ins.arg1;
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_DIV_R2R:
    if (0 == p->reg[ins.arg1]) {
      snprintf(s, sz, 
	       "Division par zero impossible (registre %hd / registre %hd) !\n",
	       ins.arg2, ins.arg1);
      if (modif) {
	*modif = -1;
      }
      return -1;
    }
   snprintf(s, sz, 
	    "Divise la valeur du registre %hd par celle du registre %hd\n",
	    ins.arg2, ins.arg1);
    p->reg[ins.arg2] = p->reg[ins.arg2] / p->reg[ins.arg1];
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_DIV_V2R:
    if (0 == ins.arg1) {
      snprintf(s, sz, 
	       "Division par zero impossible (registre %hd / %hd) !\n",
	       ins.arg2, ins.arg1);
      if (modif) {
	*modif = -1;
      }
      return -1;
    }
    snprintf(s, sz,
	"Divise la valeur du registre %hd par %hd\n",
	ins.arg2, ins.arg1);
    p->reg[ins.arg2] = p->reg[ins.arg2] / ins.arg1;
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_AND_R2R:
    snprintf(s, sz, 
	     "Masque binaire du registre %hd avec la valeur du registre %hd\n",
	     ins.arg2, ins.arg1);
    p->reg[ins.arg2] = p->reg[ins.arg1] & p->reg[ins.arg2];
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_AND_V2R:
    snprintf(s, sz, 
	     "Masque binaire du registre %hd avec la valeur %hd\n",
	     ins.arg2, ins.arg1);
    p->reg[ins.arg2] = ins.arg1 & p->reg[ins.arg2];
    if (modif) {
      *modif = ins.arg2;
    }
    break;

  case _ACTION_INVERT:
    snprintf(s, sz,
	   "Inversion du signe de la valeur du registre %hd\n",
	   ins.arg1);
    p->reg[ins.arg1] = - p->reg[ins.arg1];
    if (modif) {
      *modif = ins.arg1;
    }
    break;

  case _ACTION_JUMP:
    snprintf(s, sz, 
	     "Saut à l'adresse %hd\n",
	     ins.arg1);
    p->cp = ins.arg1;
    if (modif) {
      *modif = NOMBRE_REGISTRES;
    }
    break;

  case _ACTION_JUMP_P:
    if (est_un_registre(ins.arg1) &&
	est_une_adresse(p->reg[ins.arg1])) {
      snprintf(s, sz, 
	       "Saut à l'adresse contenue dans le registre %hd, %hd\n",	      
	       ins.arg1,
	        p->reg[ins.arg1]);
      p->cp = p->reg[ins.arg1];
      if (modif) {
	*modif = NOMBRE_REGISTRES;
      }
    } 
    else return -1;
    break;

  case _ACTION_CONDJUMP:
    snprintf(s, sz,
	     "Si la valeur (%hd) du registre %hd est positive, "
	     "saute à l'adresse %hd\n",
	     p->reg[ins.arg1], ins.arg1, ins.arg2);
    if (0 <= p->reg[ins.arg1]) {
      p->cp = ins.arg2;
      if (modif) {
	*modif = NOMBRE_REGISTRES;
      }
    } else {
      if (modif) {
	*modif = -1;
      }
    }
    break;

  case _ACTION_STOP:
    snprintf(s, sz, "Fin du processus.\n");
      if (modif) {
	*modif = -1;
      }
    return 0;

  case _ACTION_DATA:
  case _ACTION_INCONNUE:
  default:
    snprintf(s, sz, "Opération inconnue !\n");
    if (modif) {
      *modif = -1;
    }
    return -1;
  }
  return 1;
}

/* Écriture du contenu de la mémoire sur la sortie standard */
void
mem2texte(instruction_t mem[], int len, FILE *f)
{
  int i;
  char s[129];
  size_t sz = 129;
  mem++; /* on ne veut pas le noop initial */
  for (i = 1; i < len; i++) {
    /* On ne met les numéros de ligne que sur la sortie standard */
    if (f == stdout) {
      fprintf(f, "%5d  ", i);
    }
    if (!instruction2texte(mem++, s, sz)) {
      fprintf(f, "nothing appropriate here\n");
    }
    else {
      fprintf(f, "%s", s);
    }
  }
}

int
instruction2texte(instruction_t *ins, char *s, size_t sz) 
{
  switch (ins->type) {
  case _ACTION_NOOP:
    snprintf(s, sz, _NOOP_STR"\n");
    break;
  case _ACTION_INIT:
    snprintf(s, sz, _INIT_STR" %d "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_LECTURE_M2R:
    snprintf(s, sz, _LECTURE_STR" "_MEM_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_ECRITURE_R2M:
    snprintf(s, sz, _ECRITURE_STR" "_REG_PREFIXE"%u "_MEM_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
  break;
  case _ACTION_LECTURE_P2R:
    snprintf(s, sz, _LECTURE_STR" "_POINT_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_ECRITURE_R2P:
    snprintf(s, sz, _ECRITURE_STR" "_REG_PREFIXE"%u "_POINT_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_ADD_R2R:
    snprintf(s, sz, _ADD_STR" "_REG_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_ADD_V2R:
    snprintf(s, sz, _ADD_STR" %d "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_SUBS_R2R:
    snprintf(s, sz, _SUBS_STR" "_REG_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_SUBS_V2R:
    snprintf(s, sz, _SUBS_STR" %d "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_MULT_R2R:
    snprintf(s, sz, _MULT_STR" "_REG_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_MULT_V2R:
    snprintf(s, sz, _MULT_STR" %d "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_DIV_R2R:
    snprintf(s, sz, _DIV_STR" "_REG_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_DIV_V2R:
    snprintf(s, sz, _DIV_STR" %d "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_AND_R2R:
    snprintf(s, sz, _AND_STR" "_REG_PREFIXE"%u "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;
  case _ACTION_AND_V2R:
    snprintf(s, sz, _AND_STR" %d "_REG_PREFIXE"%u\n",
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_INVERT:
    snprintf(s, sz, _INVERT_STR" "_REG_PREFIXE"%u\n", 
	   ins->arg1);
    break;

  case _ACTION_JUMP:
    snprintf(s, sz, _JUMP_STR" %u\n", 
	   ins->arg1);
    break;

  case _ACTION_JUMP_P:
    snprintf(s, sz, _JUMP_STR" "_POINT_PREFIXE"%u\n", 
	   ins->arg1);
    break;

  case _ACTION_CONDJUMP:
    snprintf(s, sz, _CONDJUMP_STR" "_REG_PREFIXE"%u %u\n", 
	   ins->arg1, ins->arg2);
    break;

  case _ACTION_STOP:
    snprintf(s, sz, _STOP_STR"\n");
    break;
  case _ACTION_DATA:
    snprintf(s, sz, "%hd\n", ins->arg1);
    break;

  case _ACTION_INCONNUE:
    snprintf(s, sz, _INCONNUE_STR"\n");
    break;

  default:
    return 0;
  }
  return 1;
}

void
proc2texte(processeur_t *p)
{
  int i, j;
  for (j = 0; j < 8; j++) { 
    for (i = 0; i < NOMBRE_REGISTRES / 8; i++) {
      printf(" |r%2d: %4hd| ", j + i * 8, p->reg[j + i * 8]);
    }
    printf("\n");
  }
  printf(" |cp: %5hd| \n", p->cp);  
}
