#include <stdio.h>
#include <stdlib.h>

long calcul( long limite )
{
  long c, s;
  c = limite * limite ;
  if (limite>0)
    { s = calcul( limite-1 ); }
  else
    { s = 0 ; }
  s = s+c ;
  return s;
}

int main()
{
  long n, s;
  printf("Entrez un nombre positif : ");
  scanf("%ld", &n);
  s = calcul( n );
  printf("La somme des carres des %ld premiers entiers est %ld\n", n, s);
  return EXIT_SUCCESS;
}
