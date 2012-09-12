/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */

/* Declaration constantes et types utilisateurs */

/* Declaration de fonctions utilisateurs */
void permute_valeurs(int a,int b);



/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int x = 1;
    int y = 2;
    
    permute_valeurs(x,y);
    printf("x = %d et y = %d\n",x,y);
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Implantation de fonctions utilisateurs */
void permute_valeurs(int a,int b)
{
    int aux; /*var aux pour permutation */
    
    aux = a;
    a = b;
    b = aux;
}
