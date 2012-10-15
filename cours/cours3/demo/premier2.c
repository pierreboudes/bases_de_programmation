/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define TRUE 1
#define FALSE 0

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int n = 1;
    int d;
    int premier = TRUE;
    int continuer = TRUE;


    while (continuer)
    {
	printf("Donner un entier positif (0 pour terminer)\n");
	scanf("%d", &n);
	printf("Vous avez saisi %d\n", n);

	if (n == 0)
	{
	    continuer = FALSE;
	}
	d = 2;
	/* test de primalité */
	while ( premier && (d < n - 1) )
	{
	    if (n % d == 0)
	    {
		printf("divisible par %d\n", d);
		premier = FALSE;
	    }
	    d = d + 1;
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
