#include <stdio.h>
#include <stdlib.h>

static void inverse(int a[], int taille)
{
  int i, t;
  i = 0 ;
  while (i<taille/2) {
    t = a[i] ;
    a[i] = a[taille-i-1] ;
    a[taille-i-1] = t ;
    i = i + 1;
  }
}

int main(int argc, char *argv[])
{
    int *a;
    int i;

    a = (int *)malloc((argc - 1) * sizeof(int));
    for (i = 0; i < argc - 1; i++)
        a[i] = atoi(argv[i + 1]);

    inverse(a, argc);

    for (i = 0; i < argc - 1; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}
