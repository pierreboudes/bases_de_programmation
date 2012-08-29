/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */
#include <limits.h> /* INT_MAX */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    int i;

    for(i = 0;i <= INT_MAX;i = i + 100000)
    {
	printf("%d\n",i);
    }
    /* i > INT_MAX */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
