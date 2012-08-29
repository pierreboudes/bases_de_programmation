/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */

/* Declarations constantes et types utilisateurs */
#define N 5
struct duree_s
{
    int j; /* jours    */
    int h; /* heures   */
    int m; /* minutes  */
    int s; /* secondes */
};

/* Declarations de fonctions utilisateurs */
/* Multiplier une duree par un facteur (positif) */
struct duree_s somme_duree(struct duree_s d1, struct duree_s d2);
/* Multiplier une duree par un facteur (positif) */
struct duree_s multiplier_duree(int facteur, struct duree_s d);
/* Normaliser une duree (minutes et secondes seront dans [0, 59]) */
struct duree_s normaliser_duree(struct duree_s d); 
/* Afficher une duree */
void afficher_duree(struct duree_s d);

/* Fonction principale */
int main()
{
   /* Declaration et initialisation des variables */
    struct duree_s durees[N] =  /* durees des differentes seances */
	{
	    {0, 1, 30, 0}, /* cours */
	    {0, 3, 0, 0},  /* TD */
	    {0, 1, 30, 0}, /* TP */
	    {0, 3, 0, 0},  /* partiel */
	    {0, 0, 15, 0}  /* colles */
	};
    int seances[N] = {12, 12, 12, 2, 1}; /* nombre de seances */
    struct duree_s duree_totale = {0, 0, 0, 0}; /* Duree totale */
    int i; /* var de boucle */
    /* Calcul */
    for (i = 0; i < N; i = i + 1)
    {
	duree_totale = somme_duree(duree_totale, 
				   multiplier_duree(seances[i], durees[i]));
    }

    printf("Duree totale : ");
    afficher_duree(duree_totale);
    printf("\n");
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definitions de fonctions utilisateurs */
struct duree_s somme_duree(struct duree_s d1, struct duree_s d2)
{
    /* Calcul */
    d1.s = d1.s + d2.s;
    d1.m = d1.m + d2.m;
    d1.h = d1.h + d2.h;
    d1.j = d1.j + d2.j;
    /* Normalisation */
    d1 = normaliser_duree(d1);
    /* Retour resultat */
    return d1;
}


struct duree_s multiplier_duree(int facteur, struct duree_s d)
{
    struct duree_s res; /* resultat */  
    /* Calcul */
    res.j = d.j * facteur;
    res.h = d.h * facteur;
    res.m = d.m * facteur;
    res.s = d.s * facteur;
    /* Normalisation */
    res = normaliser_duree(res); 
    /* Retour valeur */
    return res;
}

struct duree_s normaliser_duree(struct duree_s d)
{
    struct duree_s res; /* resultat */
    /* Normalisation secondes */
    res.m = d.m + d.s / 60;
    res.s = d.s % 60;
    /* Normalisation minutes */
    res.h = d.h + res.m / 60;
    res.m = res.m % 60;
    /* Normalisation heures */
    res.j = d.j + res.h / 24;
    res.h = res.h % 24;
    /* Retour valeur */
    return res;
}

void afficher_duree(struct duree_s d)
{
    printf("%d jours %d heures %d minutes %d secondes", d.j, d.h, d.m, d.s);
}
