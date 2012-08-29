/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int temps = 1; /* temps qu'il fait */

    /* si temps = 0 alors affiche couvert */ 
    if(temps == 0) /* COUVERT */
    {
	printf("Le temps est couvert.\n");
    }

    /* si temps = 1 alors affiche ensoleille */ 
    if(temps == 1) /* ENSOLEILLE */
    {
	printf("Le temps est ensoleille.\n");
    }

    /* si temps = 2 alors affiche pluvieux */ 
    if(temps == 2) /* PLUVIEUX */
    {
	printf("Le temps est pluvieux.\n");
    }
    
    /* retour fonction */
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
