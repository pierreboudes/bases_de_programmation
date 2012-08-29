/* Declaration de fonctionnalites supplementaires */ 
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */
 
/* Declarations constantes et types utilisateurs */ 
 
/* Declarations de fonctions utilisateurs */ 
int factorielle(int n);
int binomial(int n, int p);
double faire_moyenne();
double faire_moyenne_aux(double somme, int n);
int sanscasbase(int n);
int McCarthy(int x);
 
/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */ 
    int x = 3; /* argument */ 
    int res;   /* resultat */
 
    /* Pour créer un débordement de pile
    sanscasbase(1);
    */
 
    /* 91 */
    x = 23;
    res =  McCarthy(x);
    printf(" McCarthy(%d) = %d\n", x, res);
 
    /* factorielle */
    res = factorielle(x);
    printf("%d! = %d\n", x, res);
 
    /* coefficient binomial */
    printf("binom(%d, %d) = %d\n", 5, 3, binomial(5, 3));
  
    /* moyenne */
    printf("moyenne : %g\n", faire_moyenne());
 
    /* plus joli et plus sur */
    printf("\n");
    /* Valeur fonction */
    return EXIT_SUCCESS;
}
 
/* Definitions de fonctions utilisateurs */
int factorielle(int n)
{
    int res; /* resultat */
    printf("factorielle(%d) -- debut\n", n);
    if (n > 1) /* cas récursif */ 
    {
	res = n * factorielle(n - 1);
    } 
    else /* cas de base */ 
    {
	res = 1; 
    }
    printf("factorielle(%d) -- fin\n", n);
    return res;
}
 
int binomial(int n, int p)
{
    printf("binom(%d, %d)\n", n, p);
    if ( (p == 0) || (n == p) ) /* cas de base */
    {
        return 1; 
    } 
    return binomial(n - 1, p - 1) + binomial (n - 1, p);
}
 
double faire_moyenne()
{
    return faire_moyenne_aux(0, 0);
}
 
double faire_moyenne_aux(double somme, int n)
{
    int terme = -1;
    printf("Entier positif : ");
    scanf("%d", &terme);
    if (terme < 0) /* case de base */
    {
	return somme / n; /* moyenne des termes precedents */
    }
    return faire_moyenne_aux(somme + terme, n + 1);
}
 
int sanscasbase(int n)
{
/*  Pour prendre plus de place sur la pile :
    int tab[1024] = {1};
*/
    printf("sanscasbase(%d)\n",n);
    return sanscasbase(n - 1);
}
 
int McCarthy(int x) 
{
    if (x > 100)
    {
        return (x-10);
    }
    else
    {
        return McCarthy(McCarthy(x + 11));
    }
}

