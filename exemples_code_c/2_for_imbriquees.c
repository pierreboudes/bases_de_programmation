/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int i; /* var. de boucle */
    int j; /* var. de boucle */

    for(i = 0;i < 3;i = i + 1)
    {
        for(j = 0;j < 3;j = j + 1)
        {
            printf("(%d,%d) ",i,j);
        }
        /* j >= 3 */
    }
    /* i >= 3 */

    /* passe a la ligne pour faire joli */
    printf("\n");

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
