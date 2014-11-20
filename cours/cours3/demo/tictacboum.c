#include <stdlib.h> /* EXIT_SUCCESS, rand, srand */
#include <stdio.h> /* printf, scanf */
#include <time.h> /* time */
#include <stdbool.h> /* booleens */

/* declaration de constantes et types utilisateurs */
#define TIC 1
#define TAC 2

/* declaration de fonctions utilisateurs */

int main()
{
    int debut; /* debut en temps standard */
    int duree = 0; /* duree en secondes a initialiser ;) */
    int tictac = TAC;

    printf("Auto-destruction en cours, ctrl-C pour desamorcer !\n");
    debut = time(NULL); /* date de debut (secondes depuis 1/1/1970) */
    while(duree < 3) /* pas encore 10 secondes */
    {
	duree = time(NULL) - debut; /* duree depuis debut (secondes) */
	if (duree % 2 == 0) /* duree paire: faire un tic */
	{
	    if (tictac == TAC) /* le precedent tictac est un tac */
	    {
		/* faisons tic */
		printf("tic...\n");
		tictac = TIC;
	    }
	}
	else /* duree impaire : faire un tac */
	{
	    if (tictac == TIC) /* le precedent tictac est un tic */
	    {
		/* faisons tac */
		printf("tac...\n");
		tictac = TAC;
	    }
	}
    } /* fin des 10 secondes */
    printf("** BOUM ! **\n");

    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateurs */
