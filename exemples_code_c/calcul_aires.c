/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* Declaration des constantes et types utilisateurs */
#define PI 3.1415926

/* Declaration des fonctions utilisateurs */
/* calcule l'aire d'un rectangle */
double aire_rectangle(double longueur,double largeur);
/* calcule l'aire d'un cercle */ 
double aire_cercle(double rayon);
/* calcule l'aire d'un triangle */ 
double aire_triangle(double base,double hauteur);

int main()
{
    double longueur;
    double largeur;
    double cote; 
    double rayon;
    double base;
    double hauteur;

    printf("Entrez la longueur et largeur du rectangle : ");
    scanf("%lg",&longueur);
    scanf("%lg",&largeur);
    printf("L'aire du rectangle est %g.\n",aire_rectangle(longueur,largeur));

    printf("Entrez le rayon du cercle : ");
    scanf("%lg",&rayon);
    printf("L'aire du cercle est %g.\n",aire_cercle(rayon));

    printf("Entrez la base et la hauteur du triangle : ");
    scanf("%lg",&base);
    scanf("%lg",&hauteur);
    printf("L'aire du triangle est %g.\n",aire_triangle(base,hauteur));

    return EXIT_SUCCESS;
}

/* Definitions des fonctions utilisateurs */
/* calcule l'aire d'un rectangle */
double aire_rectangle(double longueur,double largeur)
{
    return longueur * largeur;
}

/* calcule l'aire d'un cercle */ 
double aire_cercle(double rayon)
{
    return PI * rayon * rayon;
}

/* calcule l'aire d'un triangle */ 
double aire_triangle(double base,double hauteur)
{
    return (base * hauteur) / 2;
}

