#include <stdlib.h>
#include <stdio.h>
int nb_pile = 0;
double maximum(double x, double y);
double valeur_absolue(double x);
void afficher_pile(char *s);
int main() {
    double a = -4.2;
    double b = 1.3; 
    nb_pile  = nb_pile + 1;
    afficher_pile("debut main()\n");
    a = valeur_absolue(a) + valeur_absolue(b);
    afficher_pile(""); printf("%g\n", a);
    afficher_pile("fin main()\n");
    nb_pile  = nb_pile - 1;
    return EXIT_SUCCESS;
}
double maximum(double x, double y) {
    double res;
    nb_pile  = nb_pile + 1;    
    afficher_pile("debut "); printf("maximum(%g, %g)\n", x, y);
    if (x > y) {
	res = x;
    }
    else
    {
	res = y;
    }
    afficher_pile("fin "); printf("= %g\n", res);
    nb_pile  = nb_pile - 1;
    return res;
}
double valeur_absolue(double x) {
    double res;
    nb_pile  = nb_pile + 1;
    afficher_pile("debut ");printf("valeur_absolue(%g)\n", x);
    res = maximum(x, -x);
    afficher_pile("fin ");printf("= %g\n", res);
    nb_pile  = nb_pile - 1;
    return res;
}
void afficher_pile(char *s) {
    int i;
    for (i = 0; i < nb_pile; i = i + 1) {
	printf("|   ");
    }
    printf("%s",s);
}

