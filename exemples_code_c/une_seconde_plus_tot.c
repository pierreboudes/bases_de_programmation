#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* soit l'heure représenté par 3 entiers */
    int h; /* heures */
    int m; /* minutes */
    int s; /* secondes */

    /* saisie de l'heure */
    printf("Introduire l'heure puis les minutes puis les secondes : ");
    scanf("%d",&h);
    scanf("%d",&m);
    scanf("%d",&s);
    
    /* calcul de la nouvelle heure */
    s = s - 1; /* une seconde plus tot */

    if(s == -1) /* tour du cadran à l'envers des secondes */
    {
	/* passe à 59 */
	s = 59;

	/* une minute de moins */
	m = m - 1;

	if(m == -1) /* tour du cadran à l'envers des minutes */
	{
	    /* passe à 59 */
	    m = 59;

	    /* une heure de moins */
	    h = h - 1;

	    if(h == -1) /* tour du cadran à l'envers des heures */
	    {
		/* passe à 23 */
		h = 23;
	    }
	}
    }
    /* h,m,s contiennent l'heure une seconde plus tôt */

    /* affichage de l'heure */
    printf("Une seconde plus tôt, il était exactement : %dh%dm%ds\n",h,m,s);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
