/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declaration constantes et types utilisateurs */

/* declaration de fonctions utilisateurs */

/* fonction principale */
int main()
{
    double nombre_g; /* membre gauche de l'expression */
    double nombre_d; /* membre droit de l'expression */
    char op; /* operateur */
    double expr; /* resultat de l'expression */

    /* saisie expression */
    printf("Entrez une expression de la forme : nombre operateur nombre\n");
    scanf("%lg",&nombre_g);
    scanf(" %c",&op);
    scanf("%lg",&nombre_d);

    /* calcul valeur expression */
    /* cas mutuellement exclusif */
    if(op == '+') /* addition */
    {
	expr = nombre_g + nombre_d;
    }

    if(op == '-') /* soustraction */
    {
	expr = nombre_g - nombre_d;
    }

    if(op == '*') /* multiplication */
    {
	expr = nombre_g * nombre_d;
    }

    if(op == '/') /* division */
    {
	expr = nombre_g / nombre_d;
    }

    /* affichage resultat */
    printf("%g %c %g = %g\n",nombre_g,op,nombre_d,expr);

    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
