/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */
#define TAILLE 4 /* taille du tableau utilisateur */

/* declaration de fonctions utilisateurs */

int main()
{
    int tab[TAILLE]; /* tableau a initialiser par l'utilisateur */
    int produit = 1; /* element neutre pour la multiplication */
    int i; /* var. de boucle */

    /* demande saisie de TAILLE entiers*/
    printf("Saisissez %d entiers : ",TAILLE);

    /* saisie des elts du tableau (TAILLE entiers) */
    for(i = 0;i < TAILLE;i = i + 1) /* chaque case du tableau */
    {
        /* saisie valeur */
        scanf("%d",&tab[i]);
    }
    /* i >= TAILLE */

    /* calcul produit */
    for(i = 0;i < TAILLE;i = i + 1) /* chaque case */
    {
        /* multiplie le produit partiel par la valeur de la case */
        produit = produit * tab[i];
    }
    /* i >= TAILLE */

    /* produit contient le produit des éléments du tableau */
    printf("Le produit des éléments du tableau vaut %d.\n",produit);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
