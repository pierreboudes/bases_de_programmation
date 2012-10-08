/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int x = 2;

    /* afficher la valeur courante de x */
    printf("x = %d\n", x);

    /* saisie par l'utilisateur d'une valeur pour x*/
    printf("Entrer un nombre entier "); 
    scanf("%d", &x);

    /* afficher la valeur courante de x */
    printf("x = %d\n", x);
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
