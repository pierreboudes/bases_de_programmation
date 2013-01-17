/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() et scanf() */

/* Declarations de constantes */
#define TAILLE 5
#define TRUE 1
#define FALSE 0
/* Fonction principale */
int main()
{
    int tab[TAILLE] = {1, 2, 4, 2, 5};
    int x; /* valeur cherchée */
    int trouve = FALSE;
    int i = 0; /* var de boucle */
 
    /* saisie utilisateur */
    printf("entier recherché ? ");
    scanf("%d", &x);

    /* recherche dans le tableau */
    while ((!trouve) && (i < TAILLE)) 
    /* tant qu'on n'a pas trouvé et qu'il reste des éléments à
     * parcourir */
    {
	if (x == tab[i])
	{
	    trouve = TRUE;
	}
	else
	{
	    i = i + 1;
	}
    } 

    /* affichage du résultat */
    if (trouve)
    {
	printf("entier %d trouvé à l'indice %d\n", x, i);
    }
    else
    {
	printf("entier absent du tableau\n");
    }

    return EXIT_SUCCESS;
}
