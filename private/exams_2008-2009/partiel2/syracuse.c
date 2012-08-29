#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h>

int terme_suivant(int u);
void syracuse(int x);

int main()
{
  int i;
  int n;
  printf("Tester de 2 a ? ");
  scanf("%d", &n);

  for (i = 2; i <= n; i = i + 1)
  {
      syracuse(i);
  }

  return EXIT_SUCCESS;
}

int terme_suivant(int u)
{
  int res;
  if (u % 2 == 0) /* si u est pair */
  {
    res = u / 2;
  }
  else 
  {
    res = 3 * u + 1;
  }
  return res;
}


void syracuse(int u)
{
    int vol = 0;
    int altitude;
    altitude = u;
    printf("Depart : %d, ", u);
    while (u != 1)
    {
	u = terme_suivant(u);
	vol = vol + 1;
	
	if (u > altitude) /* nouveau record d'altitude ! */
	{
	    altitude = u;
	}
    }
    
    printf("altitude maximale : %d, temps de vol : %d\n", altitude, vol);
}
