/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() et scanf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    double x;
    double res;
    int i; /* var de boucle */

    /* Demander a l'utilisateur de saisir un nombre reel */
    printf("Entrer un nombre reel : ");
    scanf("%lg", &x);

    /* Calcul du carre */
    res = x * x;

    /* affichage du resultat */
    printf("%g exposant 2 = %g\n", x, res);

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
