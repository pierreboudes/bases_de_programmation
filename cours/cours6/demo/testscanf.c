/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define MAJORITE 18
/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int age = 15;

    /* saisie utilisateur */
    printf("Quel est ton age ?\n");
    scanf("%d", age);

    printf("Ton age est %d\n", age);

    if (age < MAJORITE)
    {
	printf("Tu n'as pas le permis\n");
    }
    else
    {
	printf("Tu as le permis\n");
    }
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
