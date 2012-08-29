/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    int cote; /* cote du demi-carré droit en nb d'etoiles a saisir par l'utilisateur*/
    int i; /* var. de boucle */
    int j; /* var. de boucle */

    /* saisie cote */
    printf("Entrer la taille du demi-carré :\n");
    scanf("%d",&cote);

    /* affichage du demi-carre droit */
    printf("Affichage d'un demi-carre droit d'etoiles de cote %d.\n",cote);

    for(i = 1;i <= cote;i = i + 1) /* chaque numero de ligne d'étoiles */
    {
	/* affiche les blancs */
        for(j = 0;j < cote - i;j = j + 1) /* chaque colonne de blancs */
        {
            /* affiche un blanc */
            printf(" ");
        }
        /* j >= cote - i */

        /* affiche autant d'etoiles que le numero de ligne */
        for(j = 0;j < i;j = j + 1) /* chaque colonne d'etoiles */
        {
            /* affiche une etoile */
            printf("*");
        }
        /* j >= i */

        /* passe a la ligne suivante */
        printf("\n");
    }
    /* i > cote */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
