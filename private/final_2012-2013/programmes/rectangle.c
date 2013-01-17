/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() et scanf() */

/* Fonction principale */
int main()
{
    int largeur = 6;
    int hauteur = 4;
    int i; /* var de boucle */
    int j; /* var de boucle */
    for (i = 0; i < hauteur; i = i + 1) /* pour chaque ligne */
    {
	/* afficher une ligne de largeur etoiles */
	for (j = 0; j < largeur; j = j + 1) /* repeter largeur fois */
	{
	    if ( (0 == i) 
		 || (0 == j)
		 || (hauteur - 1 == i)
		 || (largeur - 1 == j))
	    {
		printf("*");
	    }
	    else
	    {
		printf(" ");
	    }
	}
	printf("\n"); /* fin de la ligne */
    }	

    return EXIT_SUCCESS;
}
