/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf() */

/* Declarations constantes et types utilisateurs */

struct duree_s
{
    int j; /* jours    */
    int h; /* heures   */
    int m; /* minutes  */
    int s; /* secondes */
};

/* Declarations de fonctions utilisateurs */

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
    struct duree_s duree_unitaire = {0, 1, 32, 14}; /* Duree unitaire */
    int seances = 100; /* Nombre de seances */
    struct duree_s duree_totale; /* Duree totale */

    /* Affichage */
    printf("Duree d'une seance : ");
    afficher_duree(duree_unitaire);
    printf("\n");

    duree_totale = multiplier_duree(seances, duree_unitaire);

    /* Affichage */
    printf("Duree totale des %d seances : ", seances);
    afficher_duree(duree_totale);
    printf("\n");


    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definitions de fonctions utilisateurs */
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
