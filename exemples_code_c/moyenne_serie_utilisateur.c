#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration de fonctions utilisateurs */

int main()
{
    int elt; /* un �l�ment de la s�rie � saisir par l'utilisateur */
    int n = 0; /* taille de la s�rie */
    double somme = 0.0; /* somme de la s�rie � calculer pour afficher la moyenne 
                           c'est un double car sinon le C fait une division enti�re */

    /* demande utilisateur */
    printf("Entrer la s�rie d'entiers positifs ou nuls (termin�e par un nombre n�gatif) :\n");

    /* premier elt */
    scanf("%d",&elt);

    while(elt >= 0) /* pas fini */
    {
        /* ajoute un elt de plus */
        somme = somme + elt;
        n = n + 1; /* un de plus */

        /* pr�paration it�ration suivante */
        /* demande utilisateur */
        scanf("%d",&elt);
    }
    /* elt < 0 */

    if(n > 0) /* au moins un �l�ment dans la s�rie */
    {
        /* somme contient la somme des elements de la serie.
           la moyenne est (somme / n) */
        printf("La moyenne des valeurs de cette serie est : %g\n",somme / n); /* ce n'est pas une division entiere */
    }
    else /* s�rie vide */
    {
        printf("La s�rie est vide.\n");
    }
    
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
