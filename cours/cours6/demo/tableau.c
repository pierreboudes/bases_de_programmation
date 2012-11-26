/* Pierre Boudes ine: 0000000000 */
/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define N 8
# define M 4

/* Declaration des fonctions utilisateur */
int[2] saisir_fraction(); 

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int lignes[N] = {1, 3, 4, 3, 4, 1, 2, 3};
    int colonnes[M] = {2, 4, 1, 2};
    int i; /* var de boucle */
    int j; /* var de boucle */
    int somme;
    int compteur = 0;
    
    /* affichage des sommes */
    for (i = 0; i < N; i = i + 1)/* pour chaque case de lignes */
    {
	for (j = 0; j < M; j = j + 1)/* pour chaque case de colonnes */
	{
	    /* calculer et afficher la somme */
	    somme = lignes[i] + colonnes[j];
	    printf("%d ", somme);
	}
	printf("\n");
    }
    printf("\n");

    /* compte le nb de fois ou ça vaut 5 */
    for (i = 0; i < N; i = i + 1)/* pour chaque case de lignes */
    {
	for (j = 0; j < M; j = j + 1)/* pour chaque case de colonnes */
	{
	    /* calculer et compter */
	    somme = lignes[i] + colonnes[j];
	    if (somme == 5) 
	    {
		compteur = compteur + 1;
	    }
	}
    }
    printf("Nombre de fois ou la somme vaut cinq : %d fois\n", compteur);

    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
int[2] saisir_fraction() {   
}
