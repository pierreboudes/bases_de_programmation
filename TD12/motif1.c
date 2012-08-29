/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */

/* Declaration constantes et types utilisateurs */
#define LARGEUR 11
#define HAUTEUR 11

/* Declaration de fonctions utilisateurs */
char motif(int x, int y);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int colonne; /* Var de boucle, n° de colonne */
    int ligne; /* Var de boucle, n° de ligne */
    
    for (ligne = 1; ligne <= HAUTEUR; ligne = ligne + 1)
    {
	for (colonne = 1; colonne <= LARGEUR; colonne = colonne + 1)
	{
	    printf("%c", motif(colonne, ligne));
	}
	printf("\n");
    }

    /* Valeur fonction */
    return EXIT_SUCCESS;
}
