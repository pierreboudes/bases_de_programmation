#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declarations constantes et types utilisateurs */


/* fonction principale */
int main()
{
    int n = 0;       /* saisie utilisateur */
    int produit = 1; /* accumulateur pour le produit */
    int i;           /* var de boucle */

    printf("Saisissez un entier : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i = i + 1)
    {
	produit = produit * i;
    }

    printf("factorielle de %d = %d\n", n , produit);
    
    return EXIT_SUCCESS;
}

