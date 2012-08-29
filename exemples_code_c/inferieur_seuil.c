#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */
#define TAILLE 4 /* taille du tableau utilisateur */

/* declaration de fonctions utilisateurs */

int main()
{
    double tab[TAILLE]; /* tableau � initialiser par l'utilisateur */
    double seuil; /* seuil � saisir par l'utilisateur pour filtrer le tableau */
    int plus_petit = 0; /* nombre d'�l�ments du tableau < seuil */
    int i; /* var. de boucle */

    /* demande saisie de TAILLE r�els */
    printf("Saisissez %d r�els : ",TAILLE);

    /* saisie des elts du tableau (TAILLE r�els) */
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
        if(tab[i] < seuil) /* trouv� plus petit */
        {
            plus_petit = plus_petit + 1; /* un de plus */
        }
    }
    /* i >= TAILLE */

    printf("Il y a %d nombre(s) < seuil.\n",plus_petit);
  
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
