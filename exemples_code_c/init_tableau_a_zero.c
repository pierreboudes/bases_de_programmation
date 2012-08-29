/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int tab[5]; /* tableau a initialiser */
    int i; /* var. de boucle */

    /* affichage du tableau non initialise */
    printf("affichage du tableau non initialise :\n");
    for(i = 0;i < 5;i = i + 1) /* chaque case du tableau */
    {
        /* affichage de la case */
        printf("tab[%d] = %d\n",i,tab[i]);
    }
    /* i >= 5 */

    /* initialisation des cases a 0 */
    for(i = 0;i < 5;i = i + 1) /* chaque case du tableau */
    {
        /* initialisation de la case a 0 */
        tab[i] = 0;
    }
    /* i >= 5 */

    /* affichage du tableau initialise */
    printf("affichage du tableau initialise :\n");
    for(i = 0;i < 5;i = i + 1) /* chaque case du tableau */
    {
        /* affichage de la case */
        printf("tab[%d] = %d\n",i,tab[i]);
    }
    /* i >= 5 */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
