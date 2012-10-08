/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */

/* Declaration constantes et types utilisateurs */
#define N

/* Declaration de fonctions utilisateurs */
void permute_valeurs(int tab[]);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int t[N] = {0, 10};
    int i;
    
    permute_valeurs(tab);

    /* Affichage */
    for (i = 0; i < N; i = i + 1)
    {
	printf("t[%d] = %d, ", i, t[i]);
    }
    printf("\n");
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Implantation de fonctions utilisateurs */
void permute_valeurs(int tab[])
{
    int aux; /*var aux pour permutation */
    
    aux = tab[0];
    tab[0] = tab[1];
    tab[2] = aux;
}
