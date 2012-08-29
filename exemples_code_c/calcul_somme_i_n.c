/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int somme = 0; /* element neutre pour l'addition */
    int i; /* var. de boucle */

    for(i = 1;i <= 4;i = i + 1) /* i allant de 1 a 4 */
    {
        /* ajoute i a la somme partielle */
        somme = somme + i;
    }
    /* i > 4 */

    /* somme vaut 0 + 1 + 2 + 3 + 4 */
    printf("somme = %d\n",somme);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
