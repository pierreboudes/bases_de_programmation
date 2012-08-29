/* Déclaration de fonctionalités supplémentaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* Déclaration constantes et types utilisateurs */

/* Déclaration de fonctions utilisateurs */

/* Fonction principale */
int main()
{
    /* Déclaration et initialisation variables */
    int i;
    int j;
    int compt = 0;
    int n = 0;

    printf("Entrer un montant : ");
    scanf("%d", &n);

    printf("Pour rendre %d brouzoufs, je peux donner :\n", n);
    for (i = 0; i <= n; i = i + 50) /* i pieces de 50 */
    {
	for (j = 0; j <= n - i; j = j + 20) /* j pieces de 20 */
	{
	    compt =compt + 1;
	    printf("* %3d en pieces de 50 + %3d en pieces de 20 + %3d en pieces de 10\n", i, j, n - i - j);
	}
    }

    printf("Il y a %d facon de rendre la monnaie\n", compt);
  
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
