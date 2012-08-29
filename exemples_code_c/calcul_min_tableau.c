/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */
#include <limits.h> /* INT_MAX */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int tab[5] = {2,-4,8,12,-1};
    int min = INT_MAX; /* +infini >= valeurs tableau*/
    int i; /* var. de boucle */

    for(i = 0;i < 5;i = i + 1) /* chaque case du tableau */
    {
        if(tab[i] < min) /* plus petit que min courant */
        {
            /* nouveau min courant */
            min = tab[i];
        }
    }
    /* i >= 5 */
    
    /* min contient le minimum de tous les elements du tableau */
    printf("le minimum des elements du tableau est : %d\n",min);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
