/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() et scanf() */

/* Declaration des constantes et types utilisateur */
#define FALSE 0
#define TRUE 1

/* Declaration des fonctions utilisateur */
int numero_vers_premier(int n);
int premier_vers_numero(int n);
int est_premier(int x);

/* Fonction principale */
int main()
{
    int i;

    for (i = 0; i < 20; i = i + 1)
    {
	printf(" %3d", i);
    }
    printf("\n");

    for (i = 0; i < 20; i = i + 1)
    {
	printf(" %3d", numero_vers_premier(i));
    }
    printf("\n");

    printf("centieme nombre premier : %d\n", numero_vers_premier(100));

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
int numero_vers_premier(int n)
{
    int compt = 0; /* compteur */
    int p = 1; /*var de boucle */
    while (compt < n)
    {
	p = p + 1;
	if (est_premier(p))
	{
	    compt = compt + 1; /*on compte un nouveau nb premier */
	}
    }
    /* le compteur a enregistre n nombre premiers, p est le dernier d'entre eux */
    return p;
}


int premier_vers_numero(int p)
{
    int compt = 0; /* compteur */
    int q = 1; /*var de boucle */
    while (q < p)
    {
	q = q + 1;
	if (est_premier(q))
	{
	    compt = compt + 1; /*on compte un nouveau nb premier */
	}
    }
    /* le compteur a enregistre tous les nombre premiers jusqu'a p compris */
    return compt;    
}

int est_premier(int n)
{
    int i;

    for (i = 2; i < n; i = i + 1)
    {	
	if (n % i == 0) 
	{
	    return FALSE; 
	}
    }
    return TRUE;
}
