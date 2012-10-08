/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int x;
    int compteur = 1; /* tout nombre s'ecrit avec au moins un chiffre */
    printf("Entrer un nombre entier positif ");
    scanf("%d", &x);
    
    while (x > 1) /* tant que x ne s'ecrit pas avec un seul chiffre */
    {
	x = x / 2; /* enlever un chiffre a x */
	compteur = compteur + 1; /* compter un chiffre de plus */
    }
    printf("Il s'ecrit sur %d bits\n", compteur);
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
