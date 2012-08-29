/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int n = 5;
    int fact = 1; /* accumulateur de produit */
    int somme = 0; /* accumulateur de somme */
    int i; /* var de boucle */
    int j; /* var de boucle */

    /* 1) calculer la factorielle de n = 1 x ... x n */
    for (i = 1; i <= n; i = i + 1) /* pour chaque entier de 1 a n */
    {
	/* multiplier l'accumulateur par l'entier */
	fact = fact * i;
    }
    printf("Factorielle de %d : %d! = %d\n", n, n, fact);

    /* 2) calcule la somme des factorielles 1! + ... + n! */
    for (j = 1; j <= n; j = j + 1) /* pour chaque j de 1 a n */
    {
    
        /* a) calculer la factorielle de j */
	/* initialisation de fact */
	fact = 1;
	for (i = 1; i <= j; i = i + 1) /* pour chaque de 1 a n */
	{
	    /* multiplier l'accumulateur par l'entier */
	    fact = fact * i;
	}
	/* fact vaut j! */

        /* b) ajouter cette factorielle a l'accumulateur de somme */
	somme = somme + fact;
    }
    /* affichage de la somme */
    printf("Somme des factorielles jusqu'a 3 : %d\n", somme);

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
