#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

#define TAILLE 4 /* taille du tableau utilisateur */

/* declaration de fonctions utilisateurs */

int main()
{
    int tab[TAILLE]; /* tableau a initialiser par l'utilisateur */
    int elt; /* l'elt a chercher */
    int nb_occ = 0; /* le nombre d'occurrences de elt dans tab */
    int i; /* var. de boucle */

    /* saisie de TAILLE entiers*/
    printf("Saisissez %d entiers : ",TAILLE);

    for(i = 0;i < TAILLE;i = i + 1) /* chaque case du tableau */
    {
        /* saisir sa valeur */
        scanf("%d",&tab[i]);
    }
    /* i >= TAILLE */

    /* demande a l'utilisateur de saisir l'entier à chercher */
    printf("Compte le nombre d'occurrences de quel entier ?\n");
    scanf("%d",&elt);

    /* compte le nombre d'occurrences */
    for(i = 0;i < TAILLE;i = i + 1) /* chaque case du tableau */
    {
        if(tab[i] == elt) /* trouvé */
        {
            /* un de plus */
            nb_occ = nb_occ + 1;
        }
    }
    /* i >= TAILLE */

    /* affiche résultats */
    printf("Il y a %d occurrences de %d dans le tableau.\n",nb_occ,elt);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
