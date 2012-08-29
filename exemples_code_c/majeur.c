/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int age = 16; /* age de la personne */

    if(age >= 18) /* majeur */
    {
	/* affiche majeur */
	printf("Vous êtes majeur.\n");
    }
    else /* mineur */
    {
	/* affiche mineur */
	printf("Vous êtes mineur.\n");
    }
    
    /* retour fonction */
    return EXIT_SUCCESS; /* renvoie OK */
}

/* definitions des fonctions utilisateurs */
