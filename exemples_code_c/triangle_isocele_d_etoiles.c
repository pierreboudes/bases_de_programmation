#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

int main()
{
    int base; /* un nombre impair d'étoiles à la base du triangle, saisie par l'utilisateur */
    int i; /* var. de boucle */
    int j; /* var. de boucle */

    /* saisie base (impair) */
    printf("Nombre d'étoiles à la base du triangle (impair) ?\n");
    scanf("%d",&base);

    /* affichage triangle isocèle d'étoiles */
    for(i = 1;i <= base;i = i + 2) /* chaque nombre d'étoiles à afficher (base impair)*/
    {
        /* affiche les blancs */
        for(j = 0;j < (base - i) / 2;j = j + 1) /* (base - i) / 2 fois */
        {
            /* affiche un blanc */
            printf(" ");
        }
        /* j >= (base - i) /2 */

        /* affiche les étoiles */
        for(j = 0;j < i;j = j + 1) /* i fois */
        {
            /* affiche une etoile */
            printf("*");
        }
        /* j >= i */

        /* passe a la ligne suivante */
        printf("\n");
    }
    /* i >= base */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
