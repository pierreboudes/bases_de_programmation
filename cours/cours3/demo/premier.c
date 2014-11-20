/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
#include <stdbool.h> /* booleens */


/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int n = 1;
    int d;
    bool premier = true;
    bool continuer = true;


    while (continuer)
    {
      premier = true;
      printf("Donner un entier positif (0 pour terminer)\n");
	scanf("%d", &n);
	printf("Vous avez saisi %d\n", n);

	if (n == 0)
	{
	    continuer = false;
	}
	/* test de primalite */
	d = 2;
	while ( premier && (d < n) ) /* sans diviseur < d */
	{
	    if (n % d == 0) /* d divise n */
	    {
		printf("divisible par %d\n", d);
		premier = false;
	    }
	    d = d + 1; /* candidat diviseur suivant */
	}

	if (premier)
	{
	    printf("%d est premier\n", n);
	}
	else
	{
	    printf("%d n'est  pas premier\n", n);
	}
    }
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
