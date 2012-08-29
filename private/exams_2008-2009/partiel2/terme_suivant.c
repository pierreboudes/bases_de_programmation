#include <stdlib.h>		/* EXIT_SUCCESS */
#include <stdio.h>

#define N 1

int terme_suivant (int u);
int choix_utilisateur ();
void afficher_terme (int i, int u);

int
main ()
{
    int t[N];
    int u;
    int i;

    u = choix_utilisateur ();

    for (i = 0; i < N; i = i + 1)
    {
	t[i] = u;
	afficher_terme (i, u);
	u = terme_suivant (u);
    }

    return EXIT_SUCCESS;
}

int
terme_suivant (int u)
{
    int res;

    if (u % 2 == 0)		/* si u est pair */
    {
	res = u / 2;
    }
    else
    {
	res = 3 * u + 1;
    }
    return res;
}

int
choix_utilisateur ()
{
    int res;

    printf ("Donner le premier terme : ");
    scanf ("%d", &res);
    return res;
}

void
afficher_terme (int i, int u)
{
    printf ("terme %d = %d\n", i, u);
}
