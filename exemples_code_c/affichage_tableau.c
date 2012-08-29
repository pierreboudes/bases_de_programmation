/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int tab[5] = {5,2,4,3,0}; /* tableau a afficher */
    int i; /* var. de boucle */

    for(i = 0;i < 5;i = i + 1) /* chaque case du tableau */
    {
        /* affichage de la case */
        printf("tab[%d] = %d\n",i,tab[i]);
    }
    /* i >= 5 */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
