/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */
#include <math.h>

/* Declaration des fonctions utilisateurs */
double f(double x);
double integrale(double a, double b, int n);

int main()
{
    int n = 1000000;
    double a = -1e3;
    double b = 1e3;
    double z;
    z = integrale(a, b, n);

    printf("Valeur approchee de l'integrale entre %g et %g est :\n%g (de carre: %.16g)\n", a, b, z, pow(z, 2.0) - M_PI);

    return EXIT_SUCCESS;
}

/* Definitions des fonctions utilisateurs */
double f(double x)
{
    return exp(-pow(x,2.0));
}

/* calcule de la constante e approchee */ 
double integrale(double a, double b, int n)
{
    int i;
    double res = 0.0;
    double pas = (b - a)/n;
    for (i = 0; i < n; i = i + 1)
    {
	res = res + pas * f(a + i * pas);
    }
    return res;
}
