#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

int main()
{
    /* un tableau et sa taille */
    int tab[5] = {0,1,0,2,3};
    int taille = 5;
    int nouvelle_taille = 0; /* la nouvelle taille du tableau modifie */
    int i; /* var boucle */
 
    /* suppression des zeros dans tab */
    for(i = 0;i < taille;i = i + 1)
    {
        if(tab[i] != 0) /* valeur a conserver */
        {
            tab[nouvelle_taille] = tab[i];
            nouvelle_taille = nouvelle_taille + 1;
        }
    }
    /* i >= taille */
    /* les zeros ont ete supprimes,
       mise a jour de la taille */
    taille = nouvelle_taille;
 
    /* affichage du tableau pour verifier la suppression */
    printf("taille : %d\n",taille);
    for(i = 0;i < taille;i = i + 1)
    {
        printf("%d ",tab[i]);
    }
    /* i >= taille */
    printf("\n");
 
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
