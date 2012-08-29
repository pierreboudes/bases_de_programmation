#include <stdio.h>
#include <stdlib.h>

long calcul( long limite )
{
   long i, c, s;
   i = 0 ;
   s = 0 ;
  
   for (i=1; i<limite; i++)
     {
       c = i*i ;
       s = s+c ;
       i = i+1 ;
     }
 
   return s ;
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
