#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */
#define TAILLE 4 /* taille du tableau utilisateur */

/* declaration de fonctions utilisateurs */

int main()
{
    double tab[TAILLE]; /* tableau à initialiser par l'utilisateur */
    double seuil; /* seuil à saisir par l'utilisateur pour filtrer le tableau */
    int plus_petit = 0; /* nombre d'éléments du tableau < seuil */
    int i; /* var. de boucle */

    /* demande saisie de TAILLE réels */
    printf("Saisissez %d réels : ",TAILLE);

    /* saisie des elts du tableau (TAILLE réels) */
    for(i = 0;i < TAILLE;i = i + 1) /* chaque case du tableau */
    {
        /* saisie valeur */
        scanf("%lg",&tab[i]);
    }
    /* i >= TAILLE */
    
    /* saisie seuil */
    printf("Entrez le seuil : ");
    scanf("%lg",&seuil);
    
    /* comptage nombre < seuil */
    for(i = 0;i < TAILLE;i = i + 1) /* chaque case */
    {
        if(tab[i] < seuil) /* trouvé plus petit */
        {
            plus_petit = plus_petit + 1; /* un de plus */
        }
    }
    /* i >= TAILLE */

    printf("Il y a %d nombre(s) < seuil.\n",plus_petit);
  
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
