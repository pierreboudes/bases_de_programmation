#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* déclaration constantes et types utilisateurs */
struct complexe_s 
{
    double re;
    double im;
};

/* déclaration de fonctions utilisateurs */
struct complexe_s multiplier(struct complexe_s x, struct complexe_s y);
struct complexe_s additionner(struct complexe_s x, struct complexe_s y);
void afficher(struct complexe_s x);

/* Fonction principale */
int main()
{
    struct complexe_s z =  {-0.5, 0.5}; 
   struct complexe_s resultat;
   
   /* calcul de (z * z) + z */
   resultat = multiplier(z, z);
   resultat = additionner(resultat, z);

   /* affichage du résultat */
   afficher(resultat);

   /* valeur fonction */
  return EXIT_SUCCESS;
}

/* définition de fonctions utilisateurs */
struct complexe_s multiplier(struct complexe_s x, struct complexe_s y)
{
    struct complexe_s res;
    res.re = x.re * y.re - x.im * y.im;
    res.im = x.re * y.im + x.im * y.re;
    return res;
}
struct complexe_s additionner(struct complexe_s x, struct complexe_s y)
{
    struct complexe_s res;
    res.re = x.re + y.re;
    res.im = x.im + y.im;
    return res;    
}
void afficher(struct complexe_s x)
{
    printf("%lg + %lg i\n", x.re, x.im); /*sans cas particuliers */
}
