#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */
#include <stdbool.h> /* booleens */
/* Declaration constantes et types utilisateurs */

/* Declaration de fonctions utilisateurs */
bool est_xxx(int n);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int n = 9;

    if (est_xxx(n)) {
	printf("L'entier %d est xxx\n", n);
    }
    else {
	printf("L'entier %d n'est pas xxx\n", n);
    }

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition de fonctions utilisateurs */
bool est_xxx(int n)
{
    int i;

    for (i = 2; i < n; i = i + 1){
	if (n % i == 0) {
	    return false;
	}
    }
    return true;
}
