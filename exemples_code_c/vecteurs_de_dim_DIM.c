/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */
#define DIM 5 /* dimension de l'espace vectoriel */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    /* soient 3 vecteurs x,y et z */
    double x[DIM] = {1.0,-2.3,2.0,2.2,-0.3};
    double y[DIM] = {-1.0,-0.1,1.5,0.4,-0.3};
    double z[DIM];
    int i; /* var. de boucle */
    double produit_scalaire; /* le produit scalaire de 2 vecteurs */

    for(i = 0;i < DIM;i = i + 1) /* chaque composante */
    {
        /* affichage de la composante */
        printf("%g ",x[i]);
    }
    /* i >= DIM */
    printf("\n");

    /* multiplication de x par le scalaire 2.0 */
    for(i = 0;i < DIM;i = i + 1) /* chaque composante */
    {
        /* multiplication par 2.0 */
        x[i] = x[i] * 2.0;
    }
    /* i >= DIM */

    /* initialisation de z avec la somme de x et y */
    for(i = 0;i < DIM;i = i + 1) /* chaque composante */
    {
        /* somme des composantes */
        z[i] = x[i] + y[i];
    }
    /* i >= DIM */

    /* recopie de z dans y */
    for(i = 0;i < DIM;i = i + 1) /* chaque composante */
    {
        /* recopie */
        y[i] = z[i];
    }
    /* i >= DIM */

    /* calcul et affichage du produit scalaire de x et y */
    produit_scalaire = 0.0;

    for(i = 0;i < DIM;i = i + 1) /* chaque composante */
    {
        /* multiplication deux à deux */
        produit_scalaire = produit_scalaire + (x[i] * y[i]);
    }
    /* i >= DIM */
    printf("le produit scalaire de x et y est : %g\n",produit_scalaire);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
