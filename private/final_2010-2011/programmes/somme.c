/* Déclaration de fonctionalités supplémentaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* Déclaration constantes et types utilisateurs */
#define N 2

/* Déclaration de fonctions utilisateurs */

/* Fonction principale */
int main()
{
    /* Déclaration et initialisation variables */
    int t[N] = {3,0}; /* donnees */
    int s; /* commentaire supprimé */
    int i; /* var. de boucle */
    int j; /* var. de boucle */
    for(i = 0; i < N; i = i + 1) /* commentaire supprimé */
    {
	/* commentaire supprimé */
	s = 0;
	for(j = 1; j <= t[i]; j = j + 1) /* commentaire supprimé */
	{
	    /* commentaire supprimé */
	    s = s + j;
	}	
	/* commentaire supprimé */
	printf("%d\n", s);
    }
    /* commentaire supprimé */
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
