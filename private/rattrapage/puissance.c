#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declarations constantes et types utilisateurs */


/* fonction principale */
int main()
{
    double x = 0;
    int n = 0;   
    double p = 1; /* accumulateur pour le produit */
    int i;           /* var de boucle */

    printf("Saisissez un nombre décimal : ");
    scanf("%lg", &x);

    printf("Saisissez un entier : ");
    scanf("%d", &n);

    for (i = 0; i < n; i = i + 1)
    {
        p = p * x;
    }

    printf("%lg puissance %d = %lg\n", x, n, p);
    
    return EXIT_SUCCESS;
}
