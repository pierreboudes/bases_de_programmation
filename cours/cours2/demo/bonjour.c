/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define NOMBREMAGIQUE 42
/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int i; /* variable de boucle */
    int somme = 0;

    for (i = 1; i <= 10; i = i + 1)
    {
	printf("Bonjour entier %d, viens avec nous dans la somme !\n", i);
	somme = somme + i;
	printf("somme = %d\n", somme);
    }

    printf("somme = %d\n", somme);
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
