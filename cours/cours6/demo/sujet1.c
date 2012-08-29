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
    int tab[N] = {1,-2,4,10,-6};
    int i; /* var de boucle */
    int somme = 0; /* 0 élément neutre de la somme */

    /* 1) Affichage du tableau */
    printf("Affichage du tableau\n");

    for (i = 0; i < N; i = i + 1) /* pour chaque case */
    {
	/* afficher le contenu de la case */
	printf("%d ", tab[i]);
    }
    printf("\n");

    /* 2) Affichage du tableau en valeurs absolues */
    printf("Affichage du tableau en valeurs absolues\n");

    for (i = 0; i < N; i = i + 1) /* pour chaque case */
    {
	if (tab[i] < 0)
	{/* |tab[i]| = -tab[i] */
	    printf("%d ",-tab[i]);
	}
	else
	{
	    printf("%d ",tab[i]);
	}
    }
    printf("\n");

    /* 3) Calcul de la somme des valeurs absolues */
    for (i = 0; i < N; i = i + 1) /* pour chaque case */
    {
	/* ajouter la valeur absolue de la case */
	if (tab[i] < 0)
	{/* |tab[i]| = -tab[i] */
	    somme = somme - tab[i];
	}
	else
	{
	    somme = somme + tab[i];
	}
    }
    printf("Somme en valeur absolue : %d\n", somme);
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
