/* Fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h>  /* printf(), scanf() */

/* Declarations de types et constantes utilisateurs */
#define TRUE 1
#define FALSE 0

/* Declarations de fonctions utilisateurs */

/* Affiche le menu */
void afficher_menu();

/* Recupere un nombre entier saisi par l'utilisateur et le retourne */
int choix_utilisateur();

/* Affichage du menu et traitement du choix de l'utilisateur */
int executer_menu();

/* Teste si un nombre saisi par l'utilisateur est premier et affiche le resultat */
void menu_premier();

/* Teste si son argument (positif) est premier */
int est_premier(int p);


/* Fonction principale */
int main()
{
    /* Declarations et initialisation des variables */
    int encore = TRUE;
    
    /* Boucle d'interaction avec l'utilisateur */
    while (encore)
        {
            encore = executer_menu();
        }
    
    /* Greetings */
    printf("Bye bye\n");
    
    /* Valeur fonction */
    return EXIT_SUCCESS;
}



/* Definitions de fonctions utilisateurs */
void afficher_menu()
{
    printf("****************** MENU ******************\n");
    printf("*                                        *\n");
    printf("*   1) Tester si un nombre est premier   *\n");
    printf("*   2) Calculette                        *\n");
    printf("*   3) Deviner un nombre                 *\n");
    printf("*   4) Motif d'etoiles                   *\n");
    printf("*                                        *\n");
    printf("*   0) QUITTER                           *\n");
    printf("*                                        *\n");
    printf("************************** votre choix :");
}

int choix_utilisateur()
{
    int choix;
    scanf("%d", &choix);
    return choix;
}

int executer_menu()
{
    int choix;

    /* Affichage du menu et choix de l'utilisateur */
    afficher_menu();
    choix = choix_utilisateur();

    if (1 == choix) /* ------- 1) Tester si un nombre est premier ----- */
    {
        menu_premier(); 
    }

    /* Valeur de retour */
    if (choix != 0)
    {
        return TRUE;
    }
    return FALSE;
}

void menu_premier()
{
    int p;

    printf("Donner un nombre : ");
    p = choix_utilisateur();
    
    if (est_premier(p))
    {
        printf("Le nombre %d est premier\n", p);
    }
    else
    {
        printf("Le nombre %d n'est pas premier\n", p);      
    }
}


int est_premier(int n)
{
    int i = 2;
    int premier = TRUE;

    while (premier && i < n) 
    {   
        if (n % i == 0) 
        {
           premier = FALSE;
        }
        i = i + 1;
    }
    return premier;
}
