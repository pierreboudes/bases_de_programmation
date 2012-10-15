/* lapins.c (I3) */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h>  /* printf */

#define DISPARITION 1

/* declaration de fonctions utilisateurs */
int simuler_population(int nb_mois, int nb_couples);
void afficher_population(int nouveaux, int un_mois, int vieux);
int lapins_un_milliard(int nb_couples);

int main()
{
#if DISPARITION == 0
    int n;
    /* nb_lapins après 24 mois */
    printf("nb_lapins apres 24 mois : %d\n", simuler_population(24, 1));
    /* depasser le milliard a partir d'un couple en */
    n = lapins_un_milliard(1);
    printf("apres %d mois il y plus d'un milliard de lapins, exactement : %d\n", n, simuler_population(n, 1));
#else
    printf("nb_lapins apres 50 mois : %d\n", simuler_population(50, 5));
#endif

    /* valeur fonction */
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
int simuler_population(int nb_mois, int nb_couples)
{
    int nouveaux = 2*nb_couples;
    int un_mois = 0;
    int vieux = 0;
    int naissances = 0;
#if DISPARITION
    int tot_naissances = 0;
#endif
    int i; /* var boucle */
    for (i = 1; i <= nb_mois; i = i + 1) {
	/* les un_mois sont maintenant vieux (de deux_mois) */
	vieux = vieux + un_mois;
	/* il y a nb de vieux naissances */
	naissances =  2 * (vieux / 2);
	/* les ex-nouveaux ont un mois */
	un_mois = nouveaux;	
	/* les naissances font les nouveaux */
	nouveaux = naissances;
#if DISPARITION
	tot_naissances = tot_naissances + naissances;
	if (i >= 7) {
	    /* 4/5 des vieux meurent */
	    vieux = vieux / 5;
	    /* 2/5 des un_mois */
	    un_mois = 4 * un_mois / 5;
	    nouveaux = 9 * nouveaux / 10;
	}
	printf("|%2d| ", i);
	afficher_population(nouveaux, un_mois, vieux);	
#endif
    }
    /* population de lapins après nb_mois */
#if DISPARITION
    printf("Nombre total de naissances : %d\n", tot_naissances);
#endif
    return vieux + un_mois + nouveaux;
}

void afficher_population(int nouveaux, int un_mois, int vieux)
{
/* ..... ooooo ##### */
    int i;    
    for (i = 0; i < nouveaux ; i = i + 1)
    {
	printf(".");
    }
    if (nouveaux > 0) 
    {
	printf(" ");
    }
    for (i = 0; i < un_mois ; i = i + 1)
    {
	printf("o");
    }
    if (un_mois > 0)
    {
	printf(" ");
    }
    for (i = 0; i < vieux ; i = i + 1)
    {
	printf("#");
    }
    if (vieux > 0)
    {
	printf(" ");
    }
    printf("|%d|\n", nouveaux + un_mois + vieux);
}

int lapins_un_milliard(int nb_couples)
{
/* one ne recode pas la simulation ce qui fait des calculs inutiles */
    int n = 0;
    /* dépasser le milliard */
    while (simuler_population(n, nb_couples) < 1000000000) {
	n =n + 1;
    }

    return n;
}
