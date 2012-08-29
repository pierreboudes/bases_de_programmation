/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int tab[5] = {2,-4,8,12,-1};
    int somme = 0; /* element neutre pour l'addition */
    int i; /* var. de boucle */

    for(i = 0;i < 5;i = i + 1) /* chaque case du tableau */
    {
        /* ajoute la case a la somme partielle */
        somme = somme + tab[i];
    }
    /* i >= 5 */

    /* somme vaut 0 + 2 - 4 + 8 + 12 - 1 */
    printf("somme = %d\n",somme);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
