#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* déclaration constantes et types utilisateurs */

/* Fonction principale */
int main()
{
    double dette = 100.0;
    double versement = 25.0;
    double tauxa = 0.06;
    int annee = 0;
    double interets;
    double total = 0.0;

    while (dette > 0)
    {
	interets = dette * tauxa;
	dette = dette + interets - versement;
	annee = annee + 1;
	if (dette < 0)
	{
	    versement = versement + dette; /* on supprime le trop vers'e */
	    dette = 0;
	}
	printf("annee %d, interets : %g, versement : %g, dette : %g\n", annee, interets, versement, dette);
	total = total + versement;
    }

    printf("Duree %d annees, %g euros\n", annee, total);
    

  return EXIT_SUCCESS;
}
