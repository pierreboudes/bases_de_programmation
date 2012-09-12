/* -*- coding: utf-8 -*- pour que emacs travaille en utf8  */
/* menu3.c (L1 EI), debut de l'utilisation de fonctions dans le menu */
#include <stdlib.h> /* EXIT_SUCCESS, rand, srand */
#include <stdio.h>  /* printf, scanf */
#include <time.h>   /* time */

#define TRUE 1
#define FALSE 0
#define NB_MAX 100
/* declaration de fonctions utilisateurs */

/* test de primalité */
int est_premier(int n);

/* Calcul de la factorielle (vaut 1 si l'argument est négatif) */
int factorielle(int n);

/* Tirer un nombre au hasard entre 0 et n */
int nombre_aleatoire(int n);

/* motif cercle de rayon 'rayon' et de centre (0,0) */
char cercle(int x, int y, int rayon);


int main()
{
    int continuer = TRUE; /* TRUE si on doit proposer le menu */
    int choix_menu = 0;	  /* Choix de l'utilisateur */

    srand(time(NULL)); /* à ne faire qu'une fois */

    /* Boucle principale d'interaction avec l'utilisateur */
    while(continuer) 
    {
	/* Affichage du menu */
	printf("\n\n");
	printf("****************** MENU ******************\n");
	printf("*					 *\n");
	printf("*   1) Tester si un nombre est premier	 *\n");
	printf("*   2) Calculette			 *\n");
	printf("*   3) Deviner un nombre		 *\n");
	printf("*   4) Cercle d'etoiles			 *\n");
	printf("*   ...					 *\n");
	printf("*					 *\n");
	printf("*					 *\n");
	printf("*   0) QUITTER				 *\n");
	printf("*					 *\n");
	printf("************************** votre choix : ");

	/* Choix utilisateur */
	scanf("%d", &choix_menu);
	
	/* Execution du choix de l'utilisateur (cas mutuellement exclusifs) */

	if (1 == choix_menu) /* ---------------- Test de primalité -------------------- */
	{
	    int p; /* nombre a tester */
	    
	    /* Saisie utilisateur */
	    printf("Donner un nombre entier positif : ");
	    scanf("%d", &p);

	    if (est_premier(p)) /* p est premier ... ou négatif */
	    {
		printf("Le nombre %d est premier\n", p);
	    }
	    else /* x n'est pas premier et i - 1 divise x */
	    {
		printf("Le nombre %d n'est pas premier\n", p);
	    }
	}

	if (2 == choix_menu) /* --------------- Calculette --------------------------- */
	{
	    double nombre_g; /* membre gauche de l'expression */
	    double nombre_d; /* membre droit de l'expression */
	    char op; /* operateur */
	    double expr; /* resultat de l'expression */

	    /* saisie expression */
	    printf("Entrez une expression de la forme : nombre operateur nombre\n");
	    scanf("%lg",&nombre_g);
	    scanf(" %c",&op);
	    if (op == '!')
	    {
		int n = nombre_g; /* ignorer la décimale */
		expr = factorielle(n); 
		nombre_g = n; /* ignorer la décimale dans l'affichage */
	    }
	    else
	    {
		scanf("%lg",&nombre_d);
	    }
	    /* calcul valeur expression */
	    /* cas mutuellement exclusif */
	    if(op == '+') /* addition */
	    {
		expr = nombre_g + nombre_d;
	    }

	    if(op == '-') /* soustraction */
	    {
		expr = nombre_g - nombre_d;
	    }

	    if(op == '*') /* multiplication */
	    {
		expr = nombre_g * nombre_d;
	    }

	    if(op == '/') /* division */
	    {
		expr = nombre_g / nombre_d;
	    }

	    /* affichage resultat */
	    if (op == '!')
	    {
		printf("%g! = %g\n",nombre_g, expr);   
	    }
	    else
	    {
		printf("%g %c %g = %g\n",nombre_g,op,nombre_d,expr);   
	    }
	}

	if (3 == choix_menu) /* --------------- Deviner un nombre ---------------- */
	{
	    int choix; /* choix de l'utilisateur pour le nombre secret */
	    int trouve = FALSE; /* TRUE si trouvé */
	    int nombre_secret;

	    /* Tirage aléatoire du nombre secret */
	    nombre_secret = nombre_aleatoire(NB_MAX);

	    /* manche joueur */
	    while(!trouve) /* pas trouvé nombre secret */
	    {
		/* demande nombre à l'utilisateur */
		printf("Votre choix (nombre entre 0 et %d) ?\n",NB_MAX);
		scanf("%d",&choix);
		
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
	    }
	    /* trouvé nombre secret */
	    
	    printf("Vous avez trouvé le nombre secret.\n");
	}
	
	if (4 == choix_menu) /* --------------- Cercle --------------------------- */
	{	    
	    int ligne;	 /* numero de ligne */
	    int colonne; /* numero de colonne */
	    int rayon; /* rayon du cercle */
	    
	    printf("Donner le rayon : ");
	    scanf("%d", &rayon);
	    printf("\n");

	    /* Affichage par balayage */
	    for (ligne = -rayon; ligne <= rayon; ligne = ligne + 1)
	    {
		for (colonne = -rayon; colonne <= rayon; colonne = colonne + 1)
		{
		    printf("%c", cercle(colonne, ligne, rayon));
		}
		printf("\n");
	    }
	    
	} 

	if (4 < choix_menu) /* Non disponible */
	{
	    printf("\n** Choix non disponible **\n");
	}

	
	if (0 < choix_menu) /* Attendre que l'utilisateur soit pret a revenir au menu */
	{
	    char c;
	    printf("\n[Saisir un caractere pour revenir au menu] ");
	    scanf(" %c", &c); /* un caractère blanc ne sera pas pris en compte */
	}

	if (0 == choix_menu) /* quitter */
	{
	    printf("Sayonara\n");
	    continuer = FALSE;
	}
    }

    /* valeur fonction */
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
int est_premier(int n)
{
    int i;

    for (i = 2; i < n; i = i + 1)
    {	
	if (n % i == 0) 
	{
	    return FALSE; 
	}
    }
    return TRUE;
}


int factorielle(int n)
{
    int i; /* Var. de boucle */
    int res = 1; /* resultat */

    for (i = 1; i <= n; i = i + 1) /* Pour i = 1, 2, ..., n */
    {
	res = res * i; /* mettre i dans le produit */
    }

    /* Valeur fonction */
    return res;
}

char cercle(int x, int y, int rayon)
{
    if (x*x + y*y <= rayon * rayon)
    {
	return '*';
    }
    return ' ';
}

int nombre_aleatoire(int n)
{
    /* tirage du nombre secret */
    return rand() % n; /* entre 0 et n inclus */
}
