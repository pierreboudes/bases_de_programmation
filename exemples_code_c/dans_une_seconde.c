/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* soient 23h59m59s */
    int h = 23;
    int m = 59;
    int s = 59;

    /* affiche l'heure actuelle */
    printf("L'heure actuelle est : %dh%dm%ds\n",h,m,s);

    /* une seconde de plus */
    s = s + 1;

    if(s == 60) /* tour du cadran des secondes */
    {
	/* remise a 0 */
	s = 0;

	/* une minute de plus */
	m = m + 1;

	if(m == 60) /* tour du cadran des minutes */
	{
	    /* remise a 0 */
	    m = 0;

	    /* une heure de plus */
	    h = h + 1;

	    if(h == 24) /* tour du cadran des heures */
	    {
		/* remise a zero */
		h = 0;
	    }
	}
    }
    /* h,m,s contiennent l'heure une seconde plus tard */

    /* affiche l'heure */
    printf("Dans une seconde, il sera exactement : %dh%dm%ds\n",h,m,s);

    /* valeur fonction */
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
