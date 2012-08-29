#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

#define FALSE 0
#define TRUE 1

#define TAILLE 5 /* taille du tableau dans lequel chercher l'�l�ment */

/* declaration de fonctions utilisateurs */

int main()
{
    int tab[TAILLE] = {-2,10,-10,3,4};
    int elt; /* elt � chercher, saisie par l'utilisateur */
    int pas_trouve = TRUE; /* TRUE si elt pas trouv� dans le tableau */ 
    int i; /* var. boucle */

    /* saisie nombre � trouver */
    printf("?\n");
    scanf("%d",&elt);

    /* premiere case */
    i = 0;

    while(i < TAILLE && pas_trouve) /* pas fin tableau et pas trouv� elt */
    {
        if(tab[i] == elt) /* trouv� elt */
        {
            pas_trouve = FALSE;
        }

        /* pr�paration it�ration suivante */
        i = i + 1; /* case suivante */
    }
    /* fin tableau ou trouv� */

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
