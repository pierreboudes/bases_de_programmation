/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
#include <math.h> /* pour log, pow */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    double x = 3.2;
    double y = 2.4;
    double z;
    int i;

    for (i = 0; i < 10000000; i = i +1)
    {
	z = log(x + i);
/*	printf("log(%g) = %g\n", x, z); */

	z = pow(y + i, 100.0*x);
/* 	printf("%g^100x%g = %g\n", y, x, z); */
    }
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
