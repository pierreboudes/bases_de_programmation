/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */

/* Declaration des constantes et types utilisateurs */

/* Declaration des fonctions utilisateurs */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int x = 4;
    int y = 5;
    int z = 3;
    int aux; /* variable auxilliaire pour la permutation */
    
    /* copie de la valeur de x dans la variable auxilliaire */
    aux = x;
    /* copie de la valeur de y dans x */
    x = y;
    /* copie de la valeur de z dans y */
    y = z;
    /* copie dans z de l'ancienne valeur de x, depuis la variable auxilliaire */
    z = aux;

    /* valeur fonction */
    return EXIT_SUCCESS;
}

/* Definitions des fonctions utilisateurs */
