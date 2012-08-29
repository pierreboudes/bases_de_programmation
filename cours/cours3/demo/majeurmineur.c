/* Déclaration de fonctionnalités supplémentaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Déclaration des constantes et types utilisateur */
#define MAJORITE 18
#define MASCULIN 1
#define FEMININ 2

/* Déclaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
    /* Déclaration et initialisation des variables */
    int age = 20;
    int genre = FEMININ;

    /* Commençons par dire bonjour */
    printf("Bonjour,\n");

    printf("Vous etes ");
    if (age < MAJORITE) /* mineur */
    {
	if (genre == FEMININ) /* au feminin */
	{
	    printf("mineure");
	}
	if (genre == MASCULIN) /* au masculin */
	{
	    printf("mineur");
	}
    }
    else /* majeur */
    {
	printf("titulaire du permis de conduire");
    }
    printf(".\n");

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Définition des fonctions utilisateur */
