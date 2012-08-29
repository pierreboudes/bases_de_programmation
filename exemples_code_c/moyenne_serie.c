/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    int n; /* taille de la serie a saisir par l'utilisateur*/
    int elt; /* un element de la serie a saisir par l'utilsateur */
    double somme = 0.0; /* somme de la serie a calculer pour afficher la moyenne 
                           c'est un double car sinon le C fait une division entiere */
    int i; /* var. de boucle */

    /* demande la taille de la serie a l'utilisateur */
    printf("Combien d'elements dans la série ? ");
    scanf("%d",&n);

    /* saisie serie (n entiers) et calcul incremental de la somme */
    for(i = 0;i < n;i = i + 1) /* chaque entier de la serie */
    {
        /* saisir sa valeur */
        scanf("%d",&elt);

        /* l'ajoute a la somme partielle */
        somme = somme + elt;
    }
    /* i >= n */

    /* somme contient la somme des elements de la serie.
       la moyenne est somme / n */
    printf("La moyenne des valeurs de cette serie est : %g\n",somme / n); /* ce n'est pas une division entiere */

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
