#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration de fonctions utilisateurs */

int main()
{
    int fait_beau; /* booléen */
    int pas_de_vent; /* booléen */

    /* avec saisie utilisateur */
    printf("Entrer la valeur des 2 booléens (sous forme d'entiers avec 0 pour FALSE et TRUE sinon).\n");
    scanf("%d",&fait_beau);
    scanf("%d",&pas_de_vent);

    printf("%d\n",fait_beau && pas_de_vent);
    printf("%d\n",fait_beau || pas_de_vent);
    printf("%d\n",! fait_beau || pas_de_vent);
    printf("%d\n",! (! fait_beau || pas_de_vent) == (fait_beau && ! pas_de_vent));

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
