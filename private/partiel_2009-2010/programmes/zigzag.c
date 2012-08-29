/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int largeur = 10;
    int dents = 3;
    int i; /* var de boucle */
    int j; /* var de boucle */
    int k; /* var de boucle */


    for (i = 0; i < dents; i = i + 1)     /* pour chaque dent */
    {
	/* dessiner la pente a droite */
	for (j = 1; j <= largeur;j = j + 1) /* pour chaque ligne */
	{
	    /* afficher une ligne de j etoiles */
	    for (k = 0; k < j; k = k + 1) /* pour chaque colonne */
	    {
		printf("**"); 
	    }
	    /* fin de ligne */
	    printf("\n");
	}
	/* dessiner la pente a gauche */
	for (j = largeur; j > 0;j = j - 1) /* pour chaque ligne */
	{
	    /* afficher une ligne de j etoiles */
	    for (k = 0; k < j; k = k + 1) /* pour chaque colonne */
	    {
		printf("**"); 
	    }
	    /* fin de ligne */
	    printf("\n");
	}
    }
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
