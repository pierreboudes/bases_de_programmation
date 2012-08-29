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
/* moteur.h */
#ifndef _moteur_h
#define _moteur_h

/* Partis pris : on num�rote les lignes en dur (pas de labels); on se
 * contrefiche du codage des instructions et des donn�es : le 
 * r�sultat est affreux puisque pleins de bits sont inexploit�s. 
 */

/* Attention le nombre de registres doit �tre un multiple de 8 */
#define NOMBRE_REGISTRES 16
#define COLS_REGS NOMBRE_REGISTRES / 8

/* mots m�moires et processeur */
typedef short int mot_t;
typedef mot_t registre_t;

typedef struct {
  registre_t reg[NOMBRE_REGISTRES];
  registre_t cp;
} processeur_t;


/* Les instructions */

/* On note r0, r1, ..., r31 les registres */
# define _REG_PREFIXE "r"
# define _REG_PREFIXE_CAP "R"

/* On note 0, 1, ... les adresses m�moire */
# define _MEM_PREFIXE ""
# define _MEM_PREFIXE_CAP ""

/* On note *r0, *r1, ..., *r31 les adresses m�moires point�es par les
   registres */
# define _POINT_PREFIXE "*r"
# define _POINT_PREFIXE_CAP "*R"


typedef enum {

  /* noop */
#define _NOOP_STR "noop"
  _ACTION_NOOP = 0,

#define _INIT_STR "valeur"
  _ACTION_INIT,

# define _LECTURE_STR "lecture"
  _ACTION_LECTURE_M2R,
  _ACTION_LECTURE_P2R,

# define _ECRITURE_STR "ecriture"
  _ACTION_ECRITURE_R2M,
  _ACTION_ECRITURE_R2P,

  /* "add ri rj" ou bien "add x rj" ajoute la valeur du registre ri (ou x)
     � celle du registre rj et �crit le r�sultat dans le registre rj*/
# define _ADD_STR "add"
  _ACTION_ADD_R2R,
  _ACTION_ADD_V2R,

  /* "soustr ri rj" ou bien "soustr x rj" soustrait la valeur du
      registre ri (ou x) � celle du registre rj et �crit le r�sultat
      dans le registre rj*/
# define _SUBS_STR "soustr"
  _ACTION_SUBS_R2R,
  _ACTION_SUBS_V2R,

  /* "mult ri rj" ou bien "mult x rj" multiplie la valeur du registre
     rj par celle du du registre ri (ou par x) et �crit le r�sultat
     dans le registre rj*/
# define _MULT_STR "mult"
  _ACTION_MULT_R2R,
  _ACTION_MULT_V2R,

  /* "div ri rj" ou bien "div x rj" divise la valeur du registre rj
     par celle du du registre ri (ou par x) et �crit le r�sultat
     (arrondi � un entier) dans le registre rj*/
# define _DIV_STR "div"
  _ACTION_DIV_R2R,
  _ACTION_DIV_V2R,

  /* "et ri rj" ou bien "et x rj" effectue le et bit � bit entre les
     valeurs des deux registres ri et rj ou bien entre x et la valeur
     de rj et �crit le r�sultat dans le registre rj */
# define _AND_STR "et"
  _ACTION_AND_R2R,
  _ACTION_AND_V2R,

  /* "inverse ri", inverse le signe de la valeur de l'entier contenu
     dans le registre ri */
#define _INVERT_STR "inverse"
  _ACTION_INVERT,

  /* "saut i" met le cp � i*/
#define _JUMP_STR "saut"
  _ACTION_JUMP,

  /* "saut *ri" met le cp � la valeur contenue dans le registre ri */
  _ACTION_JUMP_P,

  /* "sautpos ri j" si la valeur de ri est positive ou nulle, met le cp
     � j */
#define _CONDJUMP_STR "sautpos"
  _ACTION_CONDJUMP,

  /* "stop" met fin � l'ex�cution */
#define _STOP_STR "stop"
  _ACTION_STOP,

  /* Ce type d'action signale simplement qu'il ne s'agit pas d'une
     instruction mais d'une donn�e (stock�e dans arg1). */
#define _DATA_STR ""
  _ACTION_DATA,

  /* Aucune action connue */
#define _INCONNUE_STR "?"
  _ACTION_INCONNUE,

  /* Marqueur de fin de m�moire */
  _ACTION_EOM
} action_t;

typedef struct {
  action_t type;
  mot_t arg1;
  mot_t arg2;  
} instruction_t;


/* parse_fichier()

   parse le fichier et l'encode dans la m�moire. Renvoie NULL si
   erreur, adresse de la m�moire sinon */

instruction_t * parse_fichier(char *path, int *len);

/* parse_ligne() 

   Renvoie -1 si peut pas parser, sinon : 0 si pas de num�ro de ligne,
  <num> si num�ro de ligne num. encode l'instruction lue dans ins.*/

int parse_ligne(instruction_t *ins, char *s);

/* parse_instrution() 

   sous-routine de parse_ligne() parsant l'instruction. */

int parse_instruction(instruction_t *ins, char *s);


/* initialisation du processeur */
processeur_t * init_processeur();

/* est_une_donnee(ins) 

   Renvoie 1 si l'instruction ins est une donn�e, 0 sinon */
int
est_une_donnee(instruction_t *ins);

/* est_une_instruction(ins)

   Renvoie 0 si l'instruction ins est une v�ritable instruction, 0 si
   c'est une donn�e */
int
est_une_instruction(instruction_t *ins);


int
est_un_registre(registre_t x);


/* execute_instruction_suivante()

   Cette fonction... ex�cute l'instruction suivante (bah si).

   Elle renvoie 0 si l'instruction ex�cut�e est STOP, 1 sinon. 

   Elle affiche �galement un texte pr�cisant l'instruction ex�cut�e
   dans le buffer s, avec une longueur max de sz.

   si modif n'est pas NULL elle y �crit soit :
   - le num�ro (0, ..., NOMBRE_REGISTRES - 1) du registre modifi� si
     un registre a �t� modifi�
   - ou bien NOMBRE_REGISTRES si le CP a �t� repositionn� par une
     instruction de saut
   - ou bien NOMBRE_REGISTRES + 1 + le num�ro de la m�moire modifi�e 
     si une m�moire a �t� modifi�e
   - ou -1 si rien de tout cela n'est arriv�.
   */

int
execute_instruction_suivante(instruction_t mem[], processeur_t *p, 
			     char *s, size_t sz, int *modif);

/* �criture du contenu de la m�moire sur la sortie standard */
void 
mem2texte(instruction_t mem[], int len, FILE *f);

/* Renvoie 1 si ins pointe sur une instruction, 0 sinon */
int instruction2texte(instruction_t *ins, char *s, size_t sz);

/* �criture du contenu du processeur */
void proc2texte(processeur_t *p);

#endif
