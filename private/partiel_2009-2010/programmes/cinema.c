/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define BON 2
#define MOYEN 1
#define MAUVAIS 0

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int critique = MOYEN;
    int acteurs = BON;
    int distance = 2; /* accepter la version distance reelle (double) */
    
    /* Il y a trois possibilites exclusives les unes des autres */
    if (critique == BON) /* 1) c'est un bon film */
    {
	if (distance <= 5) /* c'est a moins de 5 km */
	{
	    printf("J'y vais\n");
	}
	else /* c'est a plus de 5 km */
	{
	    printf("Je reste\n");
	}
    }
    if (critique == MOYEN) /* 2) le film est moyen */
    {	
	if (acteurs == MOYEN) /* j'apprecie moyennement les acteurs */
	{
	    printf("Je reste\n");
	}
	else /* il y a un bon choix d'acteurs */
	{
	    if (distance <= 1) /* c'est a moins de 1 km */
	    {
		printf("J'y vais\n");
	    }
	    else /* c'est a plus de 1 km */
	    {
		printf("Je reste\n");
	    }
	}
    }
    if (critique == MAUVAIS) /* 3) le film est mauvais */
    {	
	printf("Je reste\n");
    }

    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
