//en una matriz de 10 x 10 mostrar solo los primos
//con el metodo de la criba
#include <stdio.h>
#include <stdlib.h>
#define FILAS 10
#define COLUMNS 10


int main()
{
  int i,j,k=1;
  int matriz[FILAS][COLUMNS];


  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNS; j++){
      matriz[i][j] = k;
      k++;
    }
  }

  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNS; j++){
      printf("%d ", matriz[i][j]);
    }
    putchar('\n');
  }


  puts("Presione enter para continuar");
  getchar();
  return 0;
}
