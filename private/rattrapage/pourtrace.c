#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declarations constantes et types utilisateurs */

/* declarations de fonctions utilisateurs */
double foo(int n, double x);
double bar(double x);

/* fonction principale */
int main()
{
    int n = 3;
    double x = 6;
    double res;

    res = foo(n, x);
    printf("bar^%d(%lg) = %lg\n", n, x, res);
    
    return EXIT_SUCCESS;
}

/* definitions de fonctions utilisateurs */
double foo(int n, double x)
{
    int i;
    for (i = 0; i < n; i = i + 1)
    {
	x = bar(x);
    }
    return x;
}

double bar(double x)
{
    return x / 2.0 + 1.0;
}
