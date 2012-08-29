/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
  /* Declaration et initialisation des variables */
  int x = 5;

  /* Commencons par dire bonjour */
  printf("Bonjour tout le monde !\n");

  if (x > 10)
  {
    x = x - 2;
  }
  else
  {
    x = 3*x + 1;
  }

  /* Valeur fonction */
  return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
