/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */
#define TAILLE 4 /* taille du tableau utilisateur */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    int tab[TAILLE]; /* tableau a initialiser par l'utilisateur */
    int i; /* var. de boucle */

    /* demande a l'utilisateur de saisir TAILLE entiers*/
    printf("Saisissez %d entiers : ",TAILLE);

    /* saisie des elts du tableau (TAILLE entiers) */
    for(i = 0;i < TAILLE;i = i + 1) /* chaque case du tableau */
    {
        /* saisir sa valeur */
        scanf("%d",&tab[i]);
    }
    /* i >= TAILLE */

    /* affichage du tableau */
    printf("Vous avez saisi le tableau suivant : ");

    for(i = 0;i < TAILLE;i = i + 1) /* chaque case du tableau */
    {
        /* afficher sa valeur */
        printf("%d ",tab[i]);
    }
    /* i >= TAILLE */
    printf("\n");

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
