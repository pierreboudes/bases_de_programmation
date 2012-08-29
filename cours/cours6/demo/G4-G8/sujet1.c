/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define N 5
/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int tab[N] = {2,3,-10,5,9};
    int i; /* var. de boucle */
    int somme = 0; 

    /* 1) afficher le tableau */
    printf("1) affichage du tableau\n");
    for (i = 0; i < N; i = i + 1) /* pour chaque case */
    {
	printf("%d, ", tab[i]);
    }
    printf("\n");

    /* 2) afficher la valeur absolue des éléments du tableau */
    printf("2) affichage des valeurs absolues du tableau\n");
    for (i = 0; i < N; i = i + 1) /* pour chaque case */
    {
	/* afficher la valeur absolue de la case */
	if (tab[i] < 0)
	{
	    printf("%d, ", -tab[i]);
	}
	else
	{
	    printf("%d, ", tab[i]);
	}
    }
    printf("\n");

    /* 3) somme */
    /* calcul de la somme des valeurs absolues */
    for (i = 0; i < N; i = i + 1) /* pour chaque case */
    {
	/* afficher la valeur absolue de la case */
	if (tab[i] < 0)
	{
	    /* ajouter -tab[i] */
	    somme = somme - tab[i];
	}
	else
	{
	    /* ajouter tab[i] */
	    somme = somme + tab[i];
	}
    }

    /* affichage de la somme */
    printf("3) somme des valeurs absolues du tableau : %d\n", somme);

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
