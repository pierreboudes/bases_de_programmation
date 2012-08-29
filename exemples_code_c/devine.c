#include <stdlib.h> /* EXIT_SUCCESS, rand, srand */
#include <stdio.h> /* printf, scanf */
#include <time.h> /* time */

#define TRUE 1
#define FALSE 0

#define NB_MAX 16 /* nombre secret entre 0 et NB_MAX inclus */

/* declaration de fonctions utilisateurs */

int main()
{
    int nombre_secret; /* nombre secret � deviner */
    int choix; /* choix de l'utilisateur pour le nombre secret */
    int pas_trouve = TRUE; /* TRUE si pas trouv� nombre secret */

    /* initialisation du g�n�rateur de nombres pseudo-al�atoires */
    srand(time(NULL)); /* � ne faire qu'une fois */

    /* tirage du nombre secret */
    nombre_secret = rand() % (NB_MAX + 1); /* entre 0 et NB_MAX inclus */

    /* manche joueur */
    while(pas_trouve) /* pas trouv� nombre secret */
    {
        /* demande nombre � l'utilisateur */
        printf("Votre choix (nombre entre 0 et %d) ?\n",NB_MAX);
        scanf("%d",&choix);
        
        if(choix == nombre_secret) /* trouv� */
        {
            pas_trouve = FALSE;
        }
        else /* pas trouv� */
        {
            /* donne indice */
            if(choix > nombre_secret)
            {
                printf("Plus petit.\n");
            }
            else
            {
                printf("Plus grand.\n");
            }
        }
    }
    /* trouv� nombre secret */

    printf("Vous avez trouv� le nombre secret.\n");

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
