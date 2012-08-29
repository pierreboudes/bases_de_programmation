/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */
#include <limits.h> /* INT_MAX, INT_MIN */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    int a;

    printf("INT_MAX = %d\n",INT_MAX);
    printf("INT_MIN = %d\n",INT_MIN);

    printf("Entrer un entier plus grand que INT_MAX ou plus petit que INT_MIN :\n");
    scanf("%d",&a);
    printf("Vous avez saisi l'entier %d.\n",a);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
