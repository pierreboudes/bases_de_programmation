#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */
#include <time.h> /* time */
 
/* declaration de constantes et types utilisateurs */
#define TRUE 1
#define FALSE 0
#define NBMAX 100
/* declaration de fonctions utilisateurs */
 
int main()
{
    int x; /* nombre au hasard */
    int y; /* autre nombre au hasard */
    int choix; /* choix de l'utilisateur */
    int continuer = TRUE; /* TRUE s'il faut continuer a jouer */
    int essais = 0; /* nombre d'essais */
    int succes = 0; /* nombre de reponses justes */
    int debut; /* debut en temps standard */
    int duree; /* duree en secondes */
 
    /* initialisation du generateur de nombres pseudo-aleatoires */
    srand(time(NULL)); /* a ne faire qu'une fois */
 
    /* bienvenue */
    printf("Teste ton aptitude au calcul mental en faisant des additions !\n");
 
    /* partie */
    debut = time(NULL);
 
    while(continuer) /* le joueur veut faire un nouvel essai */
    {
        essais = essais + 1;
        /* tirage de x */
        x = rand() % NBMAX + 1; /* entre 1 et NBMAX inclus */
        /* tirage de y */
        y = rand() % NBMAX + 1; /* entre 1 et NBMAX inclus */
 
        /* question */
        printf("%d + %d = ", x, y);
        scanf("%d",&choix);

        if(x + y == choix) /* trouve */
        {
            printf("Bravo c'est bien %d\n", choix);
            succes = succes + 1;
        }
        else /* pas trouve */
        {
            printf("Faux, %d + %d = %d (pas %d)\n", x, y, x + y, choix);        
        }
	/* fin d'essai */
        printf("Continuer (1) ou arreter (0) ?\n");
        scanf("%d", &choix);
        if (choix == 0)
        {
            continuer = FALSE;
        }
    }
    /* fin */
 
    /* affichage du score */
    duree = time(NULL) - debut;
    printf("Votre score : %d justes sur %d essais en %d secondes\n", succes, essais, duree);
    printf("Sayonara\n");
 
    return EXIT_SUCCESS;
}
 
/* Definition des fonctions utilisateurs */
