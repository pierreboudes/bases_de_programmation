/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() et scanf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */
void afficher_cercle(int rayon);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */

    afficher_cercle(6);
    printf("\n");
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
void afficher_cercle(int rayon)
{
    /* on balaie le carré contenant le disque, de coté = 2 rayons + 1,
       et on affiche une étoile si la distance au centre est
       inférieure au rayon, sinon un blanc */
    int i;
    int j;
    for (i = -rayon; i <= rayon; i = i + 1)
    {
	for (j = -rayon; j <= rayon; j = j + 1)
	{
	    if ( (i*i+j*j) <= rayon*rayon )
	    {
		printf("*");
	    }
	    else
	    {
		printf(" ");
	    }
	}
	printf("\n");
    }	
}

int pgcd_r(int a, int b)
{
    if (a < b)
    {
	return pgcd_r(b, a);
    }
    if (b == 0)
    {
	return a;
    }
    return pgcd_r(b,  a % b);
}

int pgcd_i(int a, int b)
{
    int i;
    int min;
    int d;
    /* cas particuliers */
    if (a == 0)
    {
	return b;
    }
    if (b == 0)
    {
	return a;
    }
    /* min = minimum(a, b) */
    if (a < b)
    {
	min = a;
    }
    else
    {
	min = b;
    }
    /* diviseurs */
    for (i = 1; i <= min; i = i + 1)
    {
	/* i diviseur commun ? */
	if ( (0 == a % i) && (0 == b % i) )
	{
	    d = i;
	}
    } /* d plus grand diviseur commun */
    return d;
}
