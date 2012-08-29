#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

int main()
{
    int a; /* booleen */
    int b; /* booleen */

    printf("Entrez deux valeurs booleennes : ");
    scanf("%d",&a);
    scanf("%d",&b);

    printf("a\tb\ta ET b\ta OU b\tNON a\tNON b\tNON a ET b\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a,b,a && b,a || b,!a,!b,!a && b);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
