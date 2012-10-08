/* Pierre Boudes 0000000 */
/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
 
/* Declaration des constantes et types utilisateur */
#define N 3
#define M 2
 
/* Declaration des fonctions utilisateur */
 
/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int ligne[N] = {4, 3, 1};
    int colonne[M] = {2, 3};
    int i; /* var de boucle */
    int j; /* var de boucle */
    int somme;
    int compteur = 0;
     
    /* calcul et affichage des sommes */
    for (i = 0; i < N; i = i + 1) /* pour chaque case de ligne */
    {
	for (j = 0; j < M; j = j + 1) /* pour chaque case de colonne */
	{
	    /* calculer et afficher la somme */
	    somme = ligne[i] + colonne[j];
	    printf("%d ", somme);
	}
    }
    printf("\n");
 
    /* compte le nombre de cinq */
    for (i = 0; i < N; i = i + 1) /* pour chaque case de ligne */
    {
	for (j = 0; j < M; j = j + 1) /* pour chaque case de colonne */
	{
	    /* calculer */
	    somme = ligne[i] + colonne[j];
	    /* compter */
	    if (somme == 5)
	    {
		compteur = compteur + 1;
	    }
	}
    }
 
    /* afficher le compteur */
    printf("cinq apparait %d fois\n", compteur);
 
    /* Valeur fonction */
    return EXIT_SUCCESS;
}
 
/* Definition des fonctions utilisateur */
