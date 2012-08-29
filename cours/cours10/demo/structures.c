/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
#include <math.h> /* pour pow() et sqrt() */

/* Declaration des constantes et types utilisateur */
struct point_s
{
    double x; /* absisse */
    double y; /* ordonnee */
    int rang;
};

/* Declaration des fonctions utilisateur */
void afficher_point(struct point_s p);
double distance(struct point_s a, struct point_s b);
struct point_s milieu(struct point_s a, struct point_s b);

/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    struct point_s a;
    struct point_s b = {4.2, -0.4, 4};
    double d;

    a.x = 0.0;
    a.y = 3.5;
    a.rang = 1;

    afficher_point(a);
    printf("\n");

    d = distance(a, b);
    printf("La distance entre ");
    afficher_point(a);
    printf(" et ");
    afficher_point(b);
    printf(" est de %g.\n", d);

    afficher_point(milieu(a,b));
    printf("\n");
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
void afficher_point(struct point_s p)
{
    printf("(%g, %g)[%d]", p.x, p.y, p.rang);
}

double distance(struct point_s a, struct point_s b)
{
    double d;

    d = sqrt(pow((a.x - b.x),2.0) + pow((a.y - b.y), 2.0));
    return d;
}
struct point_s milieu(struct point_s a, struct point_s b)
{
    struct point_s m;
    m.x = (a.x + b.x)/ 2.0;
    m.y = (a.y + b.y)/ 2.0;
    m.rang = (a.rang + b.rang)/ 2.0;
    return m;
}
