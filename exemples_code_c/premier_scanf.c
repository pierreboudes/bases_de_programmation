/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    int a;
    double b;
    char c;

    printf("Entrez un nombre entier puis un nombre réel puis un caractère : ");

    scanf("%d",&a);
    scanf("%lg",&b);
    scanf(" %c",&c);

    printf("Vous avez saisi %d puis %g puis %c.\n",a,b,c);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
