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
    int premier = TRUE; /* TRUE ou FALSE selon si n est premier */
    int d;

    while ( n != 0)
    {
	/* Saisie utilisateur */
	printf("Valeur de n ? ");
	scanf("%d", &n);
	printf("n = %d\n", n);

	/* test de primalité */
	d = 2;
	while (premier && (d < n))
	{
	    /* si d divise n, mettre premier a FALSE */
	    if ( n % d == 0) /* modulo, signifie que d divise n*/
	    {
		premier = FALSE;
	    }
	    d = d + 1;
	}
	/* soit premier = FALSE soit d >= n */
	
	/* affichage */
	if (premier)
	{
	    printf("%d est premier\n", n);
	}
	else
	{
	    printf("%d n'est pas premier\n", n);
	}
	premier = TRUE;
    }	
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
