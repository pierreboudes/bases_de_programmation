/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */
#include <math.h> /* pour les fonctions mathematiques : pow(base,exp), log(x) */
  
/* Declaration des constantes et types utilisateur */
#define ANNEE 12
#define TRUE 1
#define FALSE 0
#define TAUXDEFAUT 0.044 /* 4.4% meilleurtaux.com, mai 2011 dont assurance de 0.38 */
  
/* Declaration des fonctions utilisateur */
void afficher_menu();
void afficher_pret(double capital, double taux, double echeance, double duree);
int choix_utilisateur();
double valeur_utilisateur();
double calculer_echeance(double capital, double taux, double duree);
double calculer_duree(double capital, double taux, double echeance);
double calculer_capital(double echeance, double taux, double duree);
double mensualiser_taux(double taux);
void afficher_amortissement(double capital, double taux, double echeance, double duree);
  
/* Fonction principale */
int main()
{
    /* Declaration et initialisation des variables */
    double capital = 100.0; /* capital emprunté */
    double taux = 0.044; /* taux annuel */
    double echeance = 1.0; /* montant echeance mensuelle */
    double duree = 15.0;  /* nombre d'annees */
  
    int continuer = TRUE;
    int choix = 0;


    echeance = calculer_echeance(capital, taux, duree);
  
    while (continuer)
    {
	afficher_menu();
	choix = choix_utilisateur();
	if (0 == choix) /* quitter */
	{
	    continuer = FALSE;
	}
	if (1 == choix) /* afficher le pret */
	{
	    afficher_pret(capital, taux, echeance, duree);
	}
	if (2 == choix) /* afficher le tableau d'amortissement */
	{
	    afficher_amortissement(capital, taux, echeance, duree);
	}
	if (3 == choix) /* changer le capital emprunte */
	{
	    printf("Changement du capital\n");
	    capital = valeur_utilisateur();
	    echeance = calculer_echeance(capital, taux, duree);
	    afficher_pret(capital, taux, echeance, duree);
	}
	if (4 == choix) /* changer le taux */
	{
	    printf("Changement du taux (en pourcent)\n");
	    taux = valeur_utilisateur() / 100;
	    echeance = calculer_echeance(capital, taux, duree);
	    afficher_pret(capital, taux, echeance, duree);
	}
	if (5 == choix) /* changer la duree */
	{
	    printf("Changement de la duree (en annees)\n");
	    duree = valeur_utilisateur();
	    echeance = calculer_echeance(capital, taux, duree);
	    afficher_pret(capital, taux, echeance, duree);
	}
	if (6 == choix) /* fixer l'echeance calculer la duree */
	{
	    printf("Fixer le montant de l'echeance\n");
	    echeance= valeur_utilisateur();
	    duree = calculer_duree(capital, taux, echeance);
	    afficher_pret(capital, taux, echeance, duree);
	}
	if (7 == choix) /* fixer le taux calculer la duree */
	{
	    printf("Changement du taux (en pourcent)\n");
	    taux = valeur_utilisateur() / 100;
	    duree = calculer_duree(capital, taux, echeance);
	    afficher_pret(capital, taux, echeance, duree);
	}
	if (8 == choix) /* fixer l'echeance calculer la duree */
	{
	    printf("Fixer la dur'ee\n");
	    duree = valeur_utilisateur();
	    capital = calculer_capital(echeance, taux, duree);
	    afficher_pret(capital, taux, echeance, duree);
	}
    }
      
    /* Greetings */
    printf("Sayonara\n\n");
    /* Valeur fonction */
    return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
void afficher_menu()
{
    printf("**********************************************\n");
    printf("* Faites votre choix :                       *\n");
    printf("* 1. afficher les donnees du pret            *\n");
    printf("* 2. tableau d'amortissement                 *\n");
    printf("* FAIRE VARIER LE MONTANT DE L'ECHEANCE      *\n");    
    printf("* 3. fixer le capital emprunt'e              *\n");
    printf("* 4. fixer le taux annuel                    *\n");
    printf("* 5. fixer la dur'ee                         *\n");
    printf("* FAIRE VARIER LA DUREE DU PRET              *\n");    
    printf("* 6. fixer la mensualit'e                    *\n");
    printf("* 7. fixer le taux                           *\n");
    printf("* FAIRE VARIER LE CAPITAL EMPRUNTE           *\n");
    printf("* 8. fixer la dur'ee                         *\n");
    printf("*                                            *\n");
    printf("* 0. quitter                                 *\n");
    printf("***************************** votre choix ? ");
}

int choix_utilisateur()
{
    int choix = 0;
    scanf("%d", &choix); /* peut echouer */
    return choix;
}

double valeur_utilisateur()
{
    double valeur = 0.0;
    scanf("%lg", &valeur); /* peut echouer */
    return valeur;
}

void afficher_pret(double capital, double taux, double echeance, double duree)
{
    printf("Conditions d'emprunt\n");
    printf("Capital :\t %g euros\n", capital);
    printf("Taux annuel :\t %g%%\n", taux * 100);
    printf("Echeance :\t %g euros\n", echeance);
    printf("Duree : \t %g annees\n", duree);
    printf("Cout total : \t %g\n", duree * echeance * 12 - capital);	    
}

double calculer_echeance(double capital, double taux, double duree)
{
    double tauxm = mensualiser_taux(taux);
    return tauxm / (1 - pow(1+tauxm, - duree * 12)) * capital;
}

double calculer_duree(double capital, double taux, double echeance)
{
    double tauxm = mensualiser_taux(taux);
    return ((log(echeance/capital) - log(echeance/capital - tauxm)) / log(1+tauxm)) / 12;
}

double calculer_capital(double echeance, double taux, double duree)
{
    double tauxm = mensualiser_taux(taux);
    return (1 - pow(1+tauxm, - duree * 12))/tauxm * echeance;
}

double mensualiser_taux(double taux)
{
    return pow(1.0 + taux, 1.0 / 12.0) - 1.0;
}

void afficher_amortissement(double capital, double taux, double echeance, double duree)
{
    double tauxm = mensualiser_taux(taux);
    double interets;
    double total_interets = 0.0;
    double dette;
    int mois = 0;
    dette = capital;
  
    while (dette > 0)
    {
	mois = mois + 1;
	interets = dette * tauxm;
	total_interets = total_interets + interets;
	dette = dette + interets - echeance;
	if (mois % 6 == 1)
	{
	    printf("mois \t%d\t restant du \t%g\t echeance\t %g (%g%% interets)\n", mois, dette, echeance, interets/echeance * 100.0);
	}
    }
    printf("Total des interets : %g (%g%% du capital)\n", total_interets, total_interets / capital * 100.0);
}
