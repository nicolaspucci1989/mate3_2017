#include <stdio.h>
#include <stdlib.h>
#define COLUMNAS 3

int transitiva(int n, int m[][COLUMNAS])
{
  int esTransitiva=1;
  int i,j,k;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(m[i][j])
        for(k=0;k<n;k++)
          if(m[j][k]==1 && m[i][k]!=1)
            esTransitiva=0;

  return esTransitiva;
}

int main()
{
  char *esTransitiva[]={"No es transitiva","Es transitiva"};
  int n=3;
  int relacion[][COLUMNAS]={{1,0,0},
                            {0,1,0},
                            {0,0,1}};

  printf("%s\n", esTransitiva[transitiva(n,relacion)]);

  puts("Presione enter para continuar");
  getchar();
  return 0;
}
