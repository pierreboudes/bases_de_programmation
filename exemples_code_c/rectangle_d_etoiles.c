/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int largeur = 3; /* largeur du rectangle en nb d'etoiles */
    int longueur = 6; /* longueur du rectangle en nb d'etoiles */
    int i; /* var. de boucle */
    int j; /* var. de boucle */

    printf("Affichage d'un rectangle d'etoiles de longueur %d et largeur %d.\n",longueur,largeur);

    for(i = 0;i < largeur;i = i + 1) /* chaque ligne d'étoiles */
    {
        /* affiche longueur etoiles */
        for(j = 0;j < longueur;j = j + 1) /* chaque colonne d'etoiles */
        {
            /* affiche une etoile */
            printf("*");
        }
        /* j >= longueur */

        /* passe a la ligne suivante */
        printf("\n");
    }
    /* i >= largeur */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
