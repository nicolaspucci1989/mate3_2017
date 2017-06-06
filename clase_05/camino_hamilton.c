#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0


int esSimple(int camino[], int n)
{
  int i,j,res=VERDADERO;

  for (i = 0; i < n; i++) {
    for (j = i+1; j < n; j++)
      if(camino[i]==camino[j]){
        res=FALSO;
        i=n;
        break;
      }
  }

  return res;
}


int contieneTodosLosVertices( int n, int verticesDelGrafo)
{
  return n == verticesDelGrafo;
}


int esDeHamilton(int camino[], int n, int verticesDelGrafo)
{
  return esSimple(camino,n) && contieneTodosLosVertices(n,verticesDelGrafo);
}


int main()
{
  int camino[] = {0,1,2,3,4};
  int verticesDelGrafo = 5;
  int n = sizeof(camino)/sizeof(camino[0]);
  esDeHamilton(camino,n,verticesDelGrafo)?printf("Si"):printf("No");
  printf(" de hamilton\n");

  return 0;
}
