#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, c, s;

  printf("Entrez un nombre positif : ");
  scanf("%ld", &n);

  s = 0 ;
  
  for (i=1; i<n; i=i+1)
    {
      c = i*i ;
      s = s+c ;
      i = i+1 ;
    }

  printf("La somme des carres des %ld premiers entiers est %ld\n", n, s);
  return EXIT_SUCCESS;
}
