#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declarations constantes et types utilisateurs */

/* declarations de fonctions utilisateurs */
int foo(int n);
int bar(int n);

int main()
{
    int x = 1;
    int res;

    res = foo(x);
    printf("foo(%d) = %d\n", x, res);
    
    res = bar(x);
    printf("bar(%d) = %d\n", x, res);

    return EXIT_SUCCESS;
}

/* definitions de fonctions utilisateurs */
int foo(int n)
{
    int i = 0;
    int res = 5;
    while(i < n)
    {
	res = 3 * res + 2;
	i = i + 1;
    }
    return res;
}

int bar(int n)
{
    if (n == 0) 
    {
        return 5;
    }
    return 3 * bar(n - 1) + 2;
}
