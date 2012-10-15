/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int n = -1;
    double x;
    char z;
    
    printf("entrer un caractere\n");
    scanf("%c", &z);
    printf("entrer un nombre entier\n");
    scanf("%d", &n);
    printf("entrer un nombre à virgule\n");
    scanf("%lg", &x);
    printf("vous avez saisi %c,  %d et %g\n", z, n, x);
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
