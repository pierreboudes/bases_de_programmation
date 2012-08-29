/* Declaration de fonctionnalites supplementaires */ 
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */

/* Declarations constantes et types utilisateurs */ 

/* Declarations de fonctions utilisateurs */ 
int factorielle(int n);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */ 
    int x = 3; /* argument */ 
    int res;   /* resultat */

    /* calcul */ 
    res = factorielle(x);

    /* affichage */
    printf("%d! = %d\n", x, res);
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definitions de fonctions utilisateurs */
int factorielle(int n)
{
    int res; /* resultat */ 
    if (n > 1) /* cas récursif */ 
    {
	res = n * factorielle(n - 1);
    } 
    else /* cas de base */ 
    {
	res = 1; 
    }
    return res;
}

