/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define N 30

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int i; /* var. de boucle */
    int j; /* var. de boucle */
    int n = 0; /* largeur */

    printf("Entrer une largeur de triangle : ");
    scanf("%d", &n);

    for (j = 0; j < n; j = j + 1) /* pour chaque ligne */
    {
	/* afficher j etoiles */
	for (i = 0; i < n; i = i + 1)
	{
	    if ( i > j)
	    {
		printf("*");
	    }
	    else
	    {
		printf(" ");
	    }
	}
	printf("\n");
    }

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
