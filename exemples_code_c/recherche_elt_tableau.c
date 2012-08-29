#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

#define FALSE 0
#define TRUE 1

#define TAILLE 5 /* taille du tableau dans lequel chercher l'élément */

/* declaration de fonctions utilisateurs */

int main()
{
    int tab[TAILLE] = {-2,10,-10,3,4};
    int elt; /* elt à chercher, saisie par l'utilisateur */
    int pas_trouve = TRUE; /* TRUE si elt pas trouvé dans le tableau */ 
    int i; /* var. boucle */

    /* saisie nombre à trouver */
    printf("?\n");
    scanf("%d",&elt);

    /* premiere case */
    i = 0;

    while(i < TAILLE && pas_trouve) /* pas fin tableau et pas trouvé elt */
    {
        if(tab[i] == elt) /* trouvé elt */
        {
            pas_trouve = FALSE;
        }

        /* préparation itération suivante */
        i = i + 1; /* case suivante */
    }
    /* fin tableau ou trouvé */

    if(pas_trouve)
    {
        printf("%d n'est pas dans le tableau.\n",elt);
    }
    else
    {
        printf("%d est dans le tableau.\n",elt);
    }

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
