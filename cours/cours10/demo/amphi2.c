/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
#include <math.h> /* sqrt(), pow(), ... */

/* Declaration des constantes et types utilisateur */
#define TRUE 1
#define FALSE 0
#define ROUGE 4
#define BLEU 5

struct point_s
{
    double x;
    double y;
    int couleur;
};

/* Declaration des fonctions utilisateur */
void afficher_point(struct point_s p);

/* calcule la distance euclidienne entre un point a et un point b */
double calculer_distance(struct point_s a,struct point_s b);

/* calcule le milieu de [a, b] */
struct point_s calculer_milieu(struct point_s a,struct point_s b);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    struct point_s a = {2.3, -1.4, ROUGE};
    struct point_s b = {3.3, -0.4, BLEU};
    
    printf("Premier point : ");
    afficher_point(a);
    printf("\n");

    printf("Deuxieme point : ");
    afficher_point(b);
    printf("\n");

    printf("Distance entre ces points : %g\n", calculer_distance(a, b));

    printf("Milieu du segment : ");
    afficher_point(calculer_milieu(a,b));
    printf("\n");
    

    printf("Bye bye\n");

    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
void afficher_point(struct point_s p)
{
    printf("(%g, %g){couleur : %d}", p.x, p.y, p.couleur);
}

/* calcule la distance euclidienne entre un point a et un point b */
double calculer_distance(struct point_s a,struct point_s b)
{
    return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}


struct point_s calculer_milieu(struct point_s a,struct point_s b)
{
    struct point_s milieu;
    
    milieu.x = (a.x + b.x) / 2.0 ;
    milieu.y = (a.y + b.y) / 2.0 ;
    milieu.couleur = ROUGE;

    return milieu;
}
