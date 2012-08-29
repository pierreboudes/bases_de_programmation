/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
 
/* Declaration des constantes et types utilisateur */
#define N 5
 
struct date_s
{
    int jour;
    int mois;
    int annee;
};
 
struct bm_s
{
    double temperature; /* temperature de l'air */
    int          force; /* force (echelle de Beaufort) */
    struct date_s date;
}; /* je n'ai pas oublié le point-virgule ! */
 
/* Declaration des fonctions utilisateur */
void afficher_bulletin(struct bm_s x);
 
/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    struct bm_s maximum;
    struct bm_s bulletins[N] = {
	{10.3, 6, {15,3,2011}}, 
	{12.6, 1, {23,4,2011}},
	{-5.1, 10, {1,2,2011}},
	{34.0, 0, {15,7,2011}},
	{25.1, 1, {10,9,2011}}
    };
    int i; /* var de boucle */
 
    /* affichage des bulletins */
    for (i = 0; i < N; i = i + 1)
    {
	afficher_bulletin(bulletins[i]);	
    }
 
    /* recherche du maximum */
    maximum = bulletins[0];
    for (i = 1; i < N; i = i + 1)
    {
	if (maximum.temperature < bulletins[i].temperature)
	{
	    maximum = bulletins[i];
	}
    }
 
    printf("Maximum des temperatures\n");
    afficher_bulletin(maximum);
 
    /* Valeur fonction */
    return EXIT_SUCCESS;
}
 
/* Definition des fonctions utilisateur */
void afficher_bulletin(struct bm_s x)
{
    printf("bulletin : %g°C, force %d", 
	   x.temperature, 
	   x.force);
    printf(", le %d/%02d/%d\n", 
	   x.date.jour,
	   x.date.mois, 
	   x.date.annee);
}
