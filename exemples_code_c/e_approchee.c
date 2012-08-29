/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* Declaration des fonctions utilisateurs */
/* calcule de factorielle */
double factorielle(int n);
/* calcule de la constante e approchee */ 
double e_approchee(int n);

int main()
{
    int n;
    double x = 2.718281828459045235360287;
    printf("valeur idéale : %.17g.\n",x);

    printf("Entrez l'indice de la sÃ©rie : ");
    scanf("%d",&n);

    printf("Une valeur approchee de la constante de Neper est : %.17g.\n",e_approchee(n));

    return EXIT_SUCCESS;
}

/* Definitions des fonctions utilisateurs */
/* calcule de factorielle */
double factorielle(int n)
{
    int i; /* Var. de boucle */
    double res = 1.0; /* resultat */

    for (i = 1; i <= n; i = i + 1) /* Pour i = 1, 2, ..., n */
    {
        res = res * i; /* mettre i dans le produit */
    }

    /* Valeur fonction */
    return res;
}

/* calcule de la constante e approchee */ 
double e_approchee(int n)
{
    int i; /* Var. de boucle */
    double res = 0; /* elt neutre de l'addition */

    for (i = 0; i <= n; i = i + 1) /* Pour i = 1, 2, ..., n */
    {
        res = res + 1.0 / factorielle(i); /* attention on ne veut pas de division entiere */
    }

    /* Valeur fonction */
    return res;
}
