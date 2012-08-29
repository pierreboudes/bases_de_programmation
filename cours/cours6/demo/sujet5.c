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
    int fact = 1;
    int i; /* var de boucle */
    int somme = 0; /* accumulateur de somme */
    int x; /* var de boucle */

    /* Question 1 */
    /* calcul de la factorielle */
    for (i = 1; i <= n; i = i + 1) /* pour i = 1, ..., n */
    {
	fact = fact * i;
    }
    /* affichage */
    printf("Factorielle de %d : %d! = %d\n", n, n, fact);


    /* Question 2 */
    for (x = 1; x <= n; x = x + 1)/* pour chaque x entre 1 et n */
    {
	/* calculer factorielle de x */
	fact = 1; /* reinitialisation de l'accumulateur fact */
	for (i = 1; i <= x; i = i + 1) /* pour i = 1, ..., n */
	{
	    fact = fact * i;
	}
	/* l'ajouter a la somme */
	somme = somme + fact;
	printf("x = %d, somme = %d, fact = %d\n", x, somme, fact);
    }
    printf("Somme des factorielles jusqu’a %d = %d\n", n, somme);

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
