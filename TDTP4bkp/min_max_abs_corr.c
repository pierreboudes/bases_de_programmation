#include <stdlib.h> /* EXIT_SUCCESS */

/* Declaration de constantes et types utilisateurs */

/* Declaration de fonctions utilisateurs */
/* Retourne la valeur absolue de son argument entier */
int valeur_absolue(int n);
/* Retourne le minimum des deux valeurs en argument */
int minimum(int a, int b);
/* Retourne la factorielle de l'argument entier (si positif) */
int factorielle(int n);

/* Fonction principale */
int main()
{
    int x = -3;
    int y = 5;
    int z;
    
    /* Un calcul sans signification particulière */
    x = valeur_absolue(x); /* valeur absolue de x */
    z = minimum(x, y);     /* minimum entre x et y */ 
    z = factorielle(z);    /* z! */
    z = minimum(y, z);     /* minimum entre y et z */
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}
/* Definition de fonctions utilisateurs */
int valeur_absolue(int n)
{
    if (n < 0) /* si n est négatif */
    {
	/* Valeur fonction */
        return -n; /* inverser le signe de n et renvoyer */
    }
    else /* n est positif */
    {
        /* Valeur fonction */
        return n;
    }
}

int minimum(int a, int b)
{
    if (a < b) /* Si a est le minimum */
    {
        /* Valeur fonction */
        return a;
    }
    else /* a n'est pas le minimum */
    {
        /* Valeur fonction */
        return b;
    }
}

int factorielle(int n)
{
    int i; /* Var. de boucle */
    int res = 1; /* resultat */

    for (i = 1; i <= n; i = i + 1) /* Pour i = 1, 2, ..., n */
    {
	res = res * i; /* mettre i dans le produit */
    }

    /* Valeur fonction */
    return res;
}

