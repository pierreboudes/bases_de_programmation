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
    double res = 1.0;
    int exposant;
    int i; /* var de boucle */

    /* Demander a l'utilisateur de saisir un nombre reel */
    printf("Entrer un nombre reel : ");
    scanf("%lg", &x);
    printf("Entrer son exposant (entier positif) : ");
    scanf("%d", &exposant);

    /* Calcul de la puissance */
    for (i = 0; i < exposant; i = i + 1) /* repeter exposant fois */
    {
	res = res * x; /* multiplication par x */
    }

    /* affichage du resultat */
    printf("%g exposant %d = %g\n", x, exposant, res);

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
