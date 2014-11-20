/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */
int somme(int a, int b);

/* Fonction principale */
int main()
{
  /* Declaration et initialisation des variables */
  printf("Bonjour tout le monde\n");
  printf("somme de %d a %d = %d\n", 11, 43, somme(11, 43));
  printf("somme de %d a %d = %d\n", 1, 100, somme(1, 100));
  /* Valeur fonction */
  return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
int somme(int a, int b) {
  int resultat = 0;
  int i; /* var de boucle */
  for (i = a; i <= b; i += 1) {/* pour chaque entier i entre a et b
                                  inclus, ajouter i a la somme */
    resultat += i;
  }

  return resultat;
}
