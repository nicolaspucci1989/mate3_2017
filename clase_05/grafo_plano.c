#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define VERTICES 4
#define VERDADERO 1

int cardinalAristas(int grafo[VERTICES][VERTICES])
{
  int acum=0,i,j;

  // Suma de los grados de los vertices
  for(i=0;i<VERTICES;i++)
    for(j=0;j<VERTICES;j++)
      if(grafo[i][j])
        acum++;

  // Retorna |A|
  return acum/2;
}

int cardinalVertices()
{
  return VERTICES;
}

int esPlano(int grafo[VERTICES][VERTICES])
{
  // |A| > 2|V|-4
  return cardinalAristas(grafo) <= 3 * cardinalVertices() - 6;
}

int main()
{
  int grafo[][VERTICES] = {{0, 0, 1, 1},
                          {0, 0, 1, 1},
                          {1, 1, 0, 0},
                          {1, 1, 0, 0}};

  printf("Grafo %s es plano\n", esPlano(grafo)?"si":"no");
  puts("Presione enter");
  getchar();
  return 0;
}
