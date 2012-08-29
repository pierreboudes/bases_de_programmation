/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define N 10
#define LEGENDE 1
#define CHOIXCAR 1

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{    
    /* Declaration et initialisation des variables */
    int donnees[N] = {3,0,2,8,9,10,3,5,5,2}; /* donnees a afficher */
    int maximum = 0; /* maximum dans les donnees */
    int i; /* var de boucle */
    int j; /* var de boucle */
    char c = '#'; /* caractère d'affichage */

#if CHOIXCAR
    /* choix du caractère */
    printf("Entrer le caractere a utiliser pour l'affichage (par exemple #)\n");
    scanf(" %c", &c);
#endif

    /* Affichage des donnees sous la forme d'un graphique barre gauche-droite */
    printf("Graphique barre 1 :\n\n");
    for (i = 0; i < N; i = i + 1) /* pour chaque donnee */
    {
#if LEGENDE
	/* legende */
	printf("%2d ", donnees[i]);
#endif
	/* afficher une ligne d'etoiles de longueur la valeur de la donnee */
	for (j = 0; j < donnees[i]; j = j + 1)
	{
#if CHOIXCAR
	    printf("%c", c);
#else
	    printf("#");
#endif
	}
	/* fin de ligne */
	printf("\n");
    }

    /* Trouver le maximum */
    for (i = 0; i < N; i = i + 1) /* pour chaque donnee */
    {
	if (maximum < donnees[i])/* nouveau maximum */
	{
	    maximum = donnees[i];
	}
    }

    /* Affichage d'une graphe barre vertical */
    printf("\nGraphique barre 2 :\n\n");
    for (j = maximum; j > 0; j = j - 1) /* pour chaque hauteur de donnee */
    {	
	for (i = 0; i < N; i = i + 1) /* pour chaque donnee */
	{	    
	    if (donnees[i] >= j) /* si la barre de donnee atteint cette hauteur */
	    {
#if CHOIXCAR
		printf(" %c%c", c, c); /* dessiner la barre */
#else
		printf(" ##"); /* dessiner la barre */
#endif
	    }
	    else /* sinon laisser blanc */
	    {
		printf("   ");
	    }
	} 
	/* fin de la ligne */
	printf("\n");
    }
#if LEGENDE
    /* Ajout d'une legende */
    for (i = 0; i < N; i = i + 1) /* pour chaque donnee */
    {
	printf(" %2d", donnees[i]);
    }
    /* fin de la ligne */
    printf("\n");
#endif
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
