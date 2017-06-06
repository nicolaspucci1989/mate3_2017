#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0

// int esDeHamilton()
// {
//   return esSimple() && contieneTodosLosVertices();
// }


int esSimple(int camino[], int n)
{
  int i,j,res=VERDADERO;

  for (i = 0; i < n; i++) {

    for (j = i+1; j < n; j++)
      if(camino[i]==camino[j])
        res=FALSO;break;

    for(j = i-1; j>=0; j--)
      if(camino[i]==camino[j])
        res=FALSO;break;
  }

  return res;
}


int main()
{
  int camino[] = {0,1,2,3,4};
  int n = sizeof(camino)/sizeof(camino[0]);
  esSimple(camino,n)?printf("Es simple\n"):printf("No es simple\n");

  return 0;
}
