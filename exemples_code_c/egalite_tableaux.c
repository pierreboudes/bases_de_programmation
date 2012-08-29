#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

#define FALSE 0
#define TRUE 1

#define TAILLE 5 /* taille des tableaux � comparer */

/* declaration de fonctions utilisateurs */

int main()
{
    int tab1[TAILLE] = {-2,10,-10,3,4};
    int tab2[TAILLE] = {-2,10,-10,3,3};
    int egaux = TRUE; /* TRUE si les tableaux sont �gaux */ 
    int i; /* var. boucle */

    /* premiere case */
    i = 0;

    while(i < TAILLE && egaux) /* pas fin tableau et �gaux */
    {
        if(tab1[i] != tab2[i]) /* pas �gaux */
        {
            egaux = FALSE;
        }

        /* pr�paration it�ration suivante */
        i = i + 1; /* case suivante */
    }
    /* fin tableau ou pas �gaux */

    if(egaux)
    {
        printf("Ils sont �gaux.\n");
    }
    else
    {
        printf("Ils diff�rent.\n");
    }

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
