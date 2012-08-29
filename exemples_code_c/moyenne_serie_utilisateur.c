#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration de fonctions utilisateurs */

int main()
{
    int elt; /* un élément de la série à saisir par l'utilisateur */
    int n = 0; /* taille de la série */
    double somme = 0.0; /* somme de la série à calculer pour afficher la moyenne 
                           c'est un double car sinon le C fait une division entière */

    /* demande utilisateur */
    printf("Entrer la série d'entiers positifs ou nuls (terminée par un nombre négatif) :\n");

    /* premier elt */
    scanf("%d",&elt);

    while(elt >= 0) /* pas fini */
    {
        /* ajoute un elt de plus */
        somme = somme + elt;
        n = n + 1; /* un de plus */

        /* préparation itération suivante */
        /* demande utilisateur */
        scanf("%d",&elt);
    }
    /* elt < 0 */

    if(n > 0) /* au moins un élément dans la série */
    {
        /* somme contient la somme des elements de la serie.
           la moyenne est (somme / n) */
        printf("La moyenne des valeurs de cette serie est : %g\n",somme / n); /* ce n'est pas une division entiere */
    }
    else /* série vide */
    {
        printf("La série est vide.\n");
    }
    
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
