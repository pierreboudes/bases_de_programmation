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

    for(i = 0;i < 5;i = i + 1)
    {
        printf("i = %d\n",i);
    }
    /* i >= 5 */

    printf("i vaut %d apres l'execution de la boucle.\n",i);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
