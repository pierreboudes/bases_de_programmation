/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() et scanf() */

/* Declarations de constantes */
#define TAILLE 5

/* Fonction principale */
int main()
{
    int tab[TAILLE] = {1, 2, 4, 2, 5};
    int x; /* valeur cherchée */
    int i = 0; /* var de boucle */
 
    /* saisie utilisateur */
    printf("entier recherché ? ");
    scanf("%d", &x);
    
    /* recherche dans le tableau */
    while ( (x != tab[i]) && (i < TAILLE) ) 
    {
	i = i + 1;
    }

    if (i == TAILLE)
    {
	printf("entier absent du tableau\n");	
    }
    else
    {
	printf("entier %d trouvé à l'indice %d\n", x, i);	
    }
    
    return EXIT_SUCCESS;
}
