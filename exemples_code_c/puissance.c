#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf, scanf */

/* declarations constantes et types utilisateurs */

/* declarations de fonctions utilisateurs */
int puissance(int base,int exposant);

int main()
{
    int x;
    int y;
    
    printf("Entrez les valeurs de la base puis de l'exposant : ");
    scanf("%d",&x); /* 4 est saisi par l'utilisateur */
    scanf("%d",&y); /* 3 est saisi par l'utilisateur */
    
    printf("%d exposant %d = %d\n",x,y,puissance(x,y));

    return EXIT_SUCCESS;
}

/* definitions de fonctions utilisateurs */
int puissance(int base,int exposant)
{
    int i; /* var. boucle */
    int produit = 1; /* resultat */

    for(i = 0;i < exposant;i = i + 1)
    {
        produit = produit * base;
    }

    return produit;
}
