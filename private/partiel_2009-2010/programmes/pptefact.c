/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
#include <math.h>
#include <limits.h>

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */
int factorielle(int x);


/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int limite = 1000000;
    int base = 10;
    int i;
    int x;
    int somme;

    for (base = 2; base <= 60; base = base + 1)
    {
	printf("base %d :\n", base);
	limite = factorielle(base - 1) * base;
	printf("limite %d, INT_MAX = %d\n", limite, INT_MAX);
	for (i = 10; i <= limite; i = i + 1)
	{
	    x = i;
	    somme = 0;
	    while (x > 0)
	    {
		somme = somme + factorielle(x%base);
		x = x/base;
	}
	    if (somme == i)
	    {
		printf("%d\n", i);
	    }
	}
    }
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
int factorielle(int x)
{
    int i;
    int res = 1;
    for (i = 1; i <= x; i = i + 1)
    {
	res = i * res;
    }
    return res;
}
