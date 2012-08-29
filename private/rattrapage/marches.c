/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */
#define TRUE 1
#define FALSE 0
#define PANIQUE 2
#define INQUIETUDE 1
#define CONFIANCE 0

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    int marches = PANIQUE;
    double dette = 0.5; 
    int refus = TRUE;
    int rembourser = TRUE;
    
    if (marches == PANIQUE) /* 1) accroche toi a l'euribor je retire le zinzin */
    {
	rembourser = FALSE;
    }
    if (marches == INQUIETUDE) /* 2) c'est grave docteur ? */
    {	
	if (dette > 0.5)
	{
	    if (refus)
	    {
		rembourser = FALSE;
	    }
	}
    }

    if (rembourser)
    {
	printf("Ne rien changer\n");
    }
    else
    {
	printf("Ne plus rembourser\n");
    }
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
