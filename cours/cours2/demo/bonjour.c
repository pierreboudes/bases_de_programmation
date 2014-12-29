 /* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define BORNESUP 16

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
  int i; /* var. de boucle */
  int somme = 0;

  /* pour i allant de 1 à 4 */
  for ( i = 1; i <= BORNESUP ; i = i + 1) {
    printf("Bonjour %d\n", i);
    /* ajouter i à la somme */
    somme = somme + i;
  }

  printf("A la fin somme = %d\n", somme);

  /* Valeur fonction */
  return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
