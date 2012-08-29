/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    /* declaration et initialisation variables */
    int temps = 2; /* temps : 0 COUVERT, 1 ENSOLEILLE, 2 PLUVIEUX */
    int temperature = 15; /* temperature en degres celsius */
    int chat_parti = 1; /* 0 NON, 1 OUI */

/* 
   si couvert alors
     si temp > 10 alors
       sors le chien
     sinon
       reste chez moi
   si ensoleille alors
     si voisin absent alors
       sors le chien
     sinon
       reste chez moi
   et si pluvieux alors
     reste chez moi
*/

    /* cas mutuellement exclusif */

    if(temps == 0) /* COUVERT */
    {
        if(temperature > 10)
        {
            /* on sort le chien */
            printf("Je sors le chien.\n");
        }
        else /* temperature <= 10 */
        {
            /* je reste chez moi */
            printf("Je reste chez moi.\n");
        }
    }

    if(temps == 1) /* ENSOLEILLE */
    {
        if(chat_parti == 1) /* OUI */
        {
            /* on sort le chien */
            printf("Je sors le chien.\n");
        }
        else /* NON */
	{
            /* je reste chez moi */
            printf("Je reste chez moi.\n");
        }
    }

    if(temps == 2) /* PLUVIEUX */
    {
        printf("Je reste chez moi.\n");
    }
    
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
