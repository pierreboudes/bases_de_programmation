#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declarations constantes et types utilisateurs */

/* declarations de fonctions utilisateurs */
int foo(int n);
void bar(int n);

/* fonction principale */
int main()
{
    int x = 3;
    int res;

    res = foo(x);
    printf("foo(%d) = %d\n", x, res);
    
    bar(x);

    return EXIT_SUCCESS;
}

/* definitions de fonctions utilisateurs */
int foo(int n)
{
    int i;
    int reponse = 42;
    for (i = n; i > 0; i = i - 2)
    {
	printf("%d ", i);
    }
    printf("\n");
    return reponse;
}

void bar(int n)
{
    if (n > 1) 
    {
        printf("%d ", n);
	bar(n - 2);
    }
    else
    {
	printf("%d\n", n);
    }
}
