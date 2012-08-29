/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int tab[3] = {2,-4,8};
    int aux; /* var auxiliaire pour realiser la permutation */

    /* permutation circulaire vers la droite des valeurs des cases */
    aux = tab[2];
    tab[2] = tab[1];
    tab[1] = tab[0];
    tab[0] = aux;

    /* affichage du tableau */
    printf("tab[0] = %d\n",tab[0]);
    printf("tab[1] = %d\n",tab[1]);
    printf("tab[2] = %d\n",tab[2]);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
