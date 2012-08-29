#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* déclaration constantes et types utilisateurs */

/* Fonction principale */
int main()
{
    double dette = 100.0;
    double versement = 25.0;
    double taux = 0.06;
    int annee = 0;
    double interets;

    while (dette > 0)
    {
	interets = dette * taux;
	dette = dette + interets - versement;
	annee = annee + 1;
	printf("annee %d, interets : %g, versement : %g, dette : %g\n", 
	       annee, interets, versement, dette);
    }    

  return EXIT_SUCCESS;
}
