#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* déclaration constantes et types utilisateurs */
struct date_s 
{
    int j; /* jour */
    int m; /* mois */
    int a; /* annee */
};
/* Fonction principale */
int main()
{
  int nbjours[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  /* nombre de jours de chaque mois, de decembre 2010 a decembre 2011 */
    
  struct date_s demain = {2, 1, 2011}; /* exemple */
  struct date_s hier;

  /* calcul de la date d'hier */
  hier = demain;
  hier.j = demain.j - 2;
  if (hier.j < 1) 
  {
      hier.m = demain.m - 1;
      hier.j = nbjours[hier.m] + hier.j;
  }
  if (0 == hier.m) 
  {
      hier.m = 12;
      hier.a = 2010;
  }

  /* affichage du résultat */
  printf("Demain : %d/%d/%d\n", demain.j, demain.m, demain.a);
  printf("Hier :   %d/%d/%d\n", hier.j, hier.m, hier.a);

  /* valeur fonction */
  return EXIT_SUCCESS;
}
