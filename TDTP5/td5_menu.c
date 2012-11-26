/* Fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS, rand(), srand() */
#include <stdio.h>  /* printf(), scanf() */
#include <limits.h> /* INT_MAX */
#include <time.h>   /* time() */

/* Declarations de types et constantes utilisateurs */
#define TRUE 1
#define FALSE 0
#define DEVINER_MAX 100
#define DEVINER_ESSAIS 8

/* Declarations de fonctions utilisateurs */

/* Affiche le menu */
void afficher_menu();

/* Recupere un nombre entier saisi par l'utilisateur dans l'intervalle
 * [a,b] et le retourne */
int choix_utilisateur(int a, int b);

/* Affichage du menu et traitement du choix de l'utilisateur */
int executer_menu();

/* Teste si un nombre saisi par l'utilisateur est premier et affiche le resultat */
void menu_premier();

/* Teste si son argument (positif) est premier */
int est_premier(int p);

/* Factorielle */
void menu_factorielle();
int factorielle(int n);

/* Jouer a une devinette */
void menu_deviner();

/* Tirer un nombre au hasard entre 0 et n */
int nombre_aleatoire(int n);

/* calculette */
void menu_calculette();
int calculette();

/* motif */
void afficher_motif(int cote);
int motif(int colonne, int ligne);

/* Fonction principale */
int main()
{
    /* Declarations et initialisation des variables */
    int encore = TRUE;

    /* Initialisation du generateur aleatoire */
    srand(time(NULL)); /* à ne faire qu'une fois */

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
    printf("*   2) Calcul de factorielle             *\n");
    printf("*   3) Deviner un nombre                 *\n");
    printf("*   4) Motif d'etoiles                   *\n");
    printf("*   5) Calculette                        *\n");
    printf("*                                        *\n");

    printf("*   0) QUITTER                           *\n");
    printf("*                                        *\n");
    printf("************************** votre choix : ");
}

int choix_utilisateur(int a, int b)
{
   int compteur = 0; /* compteur du nombre d'essais */
   int choix = 0; /* choix de l'utilisateur */
   char saisie[256]; /* declaration d'un chaine qui nous servira de
		      * "tampon" */
   choix = a - 1;

   while ((compteur < 5) &&  ((choix < a) || (choix > b)))
   {
       if (compteur > 0) {
	   printf("Le nombre doit etre entre %d et %d (inclus) : ", a, b);
       }
       fgets(saisie, 256, stdin); /* preleve la ligne tapee par
				     l'utilisateur et la place dans le
				     tampon */
       sscanf(saisie, "%d", &choix); /* tente de reconnaitre un entier
					dans le tampon */
       compteur = compteur + 1;
   }
   if ((choix < a) || (choix > b)) {
       choix = a;
   }
   return choix;
}

int executer_menu()
{
    int choix;

    /* Affichage du menu et choix de l'utilisateur */
    afficher_menu();
    choix = choix_utilisateur(0, 5);

    if (1 == choix) /* ------- 1) Tester si un nombre est premier ----- */
    {
	menu_premier();	
    }

    if (2 == choix) /* ------- 2) calcul de factorielle --------------- */
    {
	menu_factorielle();
    }

    if (3 == choix) /* ------- 3) Deviner un nombre ------------------- */
    {
	menu_deviner();	
    }

    if (4 == choix) /* ------- 4) Motif d'etoiles -------------------- */
    {
	afficher_motif(10);
    }

    if (5 == choix) /* ------- 5) Calculette  ------------------------ */
    {
	menu_calculette();	
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
    p = choix_utilisateur(1, INT_MAX);
    
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

void menu_factorielle()
{
    int n;
    printf("Calcul de factorielle.\nEntrer l'argument (entier positif) : ");
    n = choix_utilisateur(0, INT_MAX);
    printf("%d\n", factorielle(n));
}

int factorielle(int n)
{
    int i;
    int res = 1;
    for (i = 2; i <= n; i = i + 1)
    {
	res = res * i;
    }
    return res;
}

void menu_deviner()
{
    int choix; /* choix de l'utilisateur pour le nombre secret */
    int trouve = FALSE; /* TRUE si trouvé */
    int nombre_secret;
    int essais = DEVINER_ESSAIS; /* essais restants */
    
    /* Tirage aléatoire du nombre secret */
    nombre_secret = nombre_aleatoire(DEVINER_MAX);

    /* manche joueur */
    while(!trouve && (essais > 0)) /* pas trouvé nombre secret */
    {
	/* demande nombre à l'utilisateur */
	printf("Votre choix (nombre entre 0 et %d) : ", DEVINER_MAX);
	choix = choix_utilisateur(0, DEVINER_MAX);
		
	if(choix == nombre_secret) /* trouvé */
	{
	    trouve = TRUE;
	}
	else /* pas trouvé */
	{
	    /* donne indice */
	    if(choix > nombre_secret)
	    {
		printf("Trop grand.\n");
	    }
	    else
	    {
		printf("Trop petit.\n");
	    }
	}       
	essais = essais - 1;
    }

    if (essais > 0)
    {
	/* trouvé nombre secret */	  
	printf("Gagné. Vous avez trouvé le nombre secret.\n");   
    }
    else
    {
	/* Perdu */
	printf("Perdu : limite du nombre d'essais atteinte.\n");
    }
}


int nombre_aleatoire(int n)
{
    /* tirage du nombre secret */
    return rand() % (n + 1); /* entre 0 et n inclus */
}

void menu_calculette()
{
    int continuer = TRUE;
    printf("Mode calculette\n");
    printf("Entrer des expressions nombre operateur nombre\n");
    printf("ou 0+0 pour quitter\n");
    while (continuer)
    {
	printf("Votre expression ? ");
	continuer = calculette();
    }
}

int calculette()
{
    double x;
    double y;
    char op;
    
    scanf("%lg %c %lg", &x, &op, &y);

    if ('+' == op) /* addition */
    {
	if ((0 == x) && (0 == y))
	{
	    printf("La tete a toto \n");
	    return FALSE;
	}
	printf("%lg\n", x + y);
    }
    else if ('-' == op) /* soustraction */
    {
	printf("%lg\n", y - x);
    }
    else if ( ('*' == op) || ('x' == op)) /* multiplication */
    {
	printf("%lg\n", x * y);
    }
    else if ('/' == op) /* division */
    {
	printf("%lg\n", x / y);
    }
    else 
    {
	printf("operation non reconnue\n");
	return FALSE;
    }
    return TRUE;
}

void afficher_motif(int cote)
{
    int ligne; /* numero de ligne, de bas en haut */
    int colonne; /* numero de colonne, de gauche a droite */
    for (ligne = cote - 1; ligne >= 0; ligne = ligne - 1) /* pour chaque ligne */
    {
        for (colonne = 0; colonne < cote; colonne = colonne + 1) /* pour chaque colonne */
        {
            if (motif(colonne, ligne)) /* le point appartient au motif */
            {
                printf("* ");  
            }
            else /* le point n'appartient pas au motif */
            {
                printf("  "); 
            }   
        }
        printf("\n"); /* ligne suivante */
    }
}

int motif(int colonne, int ligne)
{
    return (0 == (colonne + ligne) % 2) 
	|| (colonne < 5);
}
