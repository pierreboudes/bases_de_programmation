#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
/* Declarations de types et fonctions utilisateur */ 
#define TRUE 1
#define FALSE 0
 
#define JOUEUR 1
#define OPPOSANT 0
 
struct tablette_s
{
    int l; /* largeur */
    int h; /* hauteur */
};
 
/* Declaration de fonction utilisateur */
int nombre_aleatoire(int n);
int choix_utilisateur(int a, int b);
void afficher_tablette(struct tablette_s choco);
int partie_perdue(struct tablette_s choco);
struct tablette_s joueur(struct tablette_s choco);
struct tablette_s opposant(struct tablette_s choco);
 
 
int main()
{
    struct tablette_s choco = {8, 5}; /* miam */
    int tour = JOUEUR; 
 
    /* Initialisation */
    srand(time(NULL)); /* à ne faire qu'une fois */
 
    /* Tour de jeu */
    while (!partie_perdue(choco))
    {
	afficher_tablette(choco);
        if (tour == JOUEUR) /* Au joueur de jouer */
	{
	    choco = joueur(choco);
            tour = OPPOSANT;
	} 
        else /* A l'opposant de jouer */
        {
	    printf("Opposant joue\n");
            choco = opposant(choco);
            tour = JOUEUR;
	}
    }
    /* La partie est finie, le gagnant est ... */
    if (tour == JOUEUR) /* L'opposant gagne */
    {
	printf("Perdu !\n");
    } 
    else /* le joueur gagne */    
    {
	printf("Arghh, vous avez gagné\n");
    }
     
    return EXIT_SUCCESS;
}



int nombre_aleatoire(int n)
{
    /* tirage du nombre secret */
    return rand() % (n + 1); /* entre 0 et n inclus */
}

void afficher_tablette(struct tablette_s choco)
{
    int i;
    int j;

    for (i = 0; i < choco.h; i = i + 1)
    {
	for (j = 0; j < choco.l; j = j + 1)
	{
	    if ( (i == choco.h - 1) &&  (j == 0) )
	    {
		printf("X ");
	    }
	    else
	    {		    
		printf("M ");
	    }
	}
	printf("\n");
    }
}
 
int partie_perdue(struct tablette_s choco)
{
    return (choco.l == 1) 
	&& (choco.h == 1);
}
 
struct tablette_s joueur(struct tablette_s choco)
{
    char c = ' '; /* colonne ou ligne */
    int n; /* croque croque */

    /* Choix entre colonnes et lignes */
    if ( (choco.l > 1) && (choco.h > 1) )
    {
	while ( ! ((c == 'c') || (c == 'C') || (c == 'l') || (c == 'L')) )
	{
	    printf("Croquer des _C_olonnes ou des _L_ignes ? (entrer C ou L) : ");
	    scanf(" %c", &c); /* ne pas oublier l'espace avant %c */
	}
    }
    if (choco.l == 1)
    {
	c = 'l';
    }
    if (choco.h == 1)
    {
	c = 'c';
    }
    /* Croquer */
    if ( (c == 'c') || (c == 'C') ) /* croquer des colonnes */
    {
	printf("Combien de colonnes voulez vous croquer [1, %d] : ", choco.l - 1);
	n = choix_utilisateur(1, choco.l - 1);
	choco.l = choco.l - n; 
    }
    if ( (c == 'l') || (c == 'L') ) /* croquer des lignes */
    {
	printf("Combien de lignes voulez vous croquer [1, %d] : ", choco.h - 1);
	n = choix_utilisateur(1, choco.h - 1);
	choco.h = choco.h - n; 
    }
    return choco;
}
 
struct tablette_s opposant(struct tablette_s choco)
{
    int cote; /* 1 ligne, 0 colonne */
 
    /* Cet opposant choisit au hasard le côté */
    if ((choco.h > 1) && (choco.l > 1))
    {
	cote = nombre_aleatoire(1);
    }
    if (choco.h == 1)
    {
	cote = 1;
    }
    if (choco.l == 1)
    {
	cote = 0;
    }
 
    /* Mais il joue intelligement son coup ensuite, lorsque c'est possible */
    if (cote == 1) /* croquer ligne */
    {
	if (choco.h > choco.l)
	{ /* on peut rendre une tablette carrée */
	    choco.h = choco.l;
	}
	else
	{ /* sinon on joue au hasard */
	    choco.h = nombre_aleatoire(choco.h - 2) + 1; 
	}
    }
    if (cote == 0) /* croquer colonne */
    {
	if (choco.l > choco.h)
	{ /* on peut rendre une tablette carrée */
	    choco.l = choco.h;
	}
	else
	{ /* sinon on joue au hasard */
	    choco.l = nombre_aleatoire(choco.l - 2) + 2; 
	}
    }
    return choco;
}
 
int choix_utilisateur(int a, int b)
{
   int compteur = 5; /* compteur du nombre d'essais */
   int choix; /* choix de l'utilisateur */

   scanf("%d", &choix);
   while ((compteur > 0) &&  ((choix < a) || (choix > b)))
   {
       printf("Le nombre doit etre entre %d et %d (inclus) : ", a, b);
       scanf("%d", &choix);
       compteur = compteur - 1;
   }
   if (compteur == 0)
   {
       choix = a;
   }
   return choix;
}
