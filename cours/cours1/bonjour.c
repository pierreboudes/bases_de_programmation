/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
  int age;

  printf("Vous avez %d ans\n", age);
  /* Declaration et initialisation des variables */
  if (age >= 18) {
    printf("Vous avez le permis\n");
  }
  else {
    printf("Vous n'avez pas le permis\n");
  }

  /* Valeur fonction */
  return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
