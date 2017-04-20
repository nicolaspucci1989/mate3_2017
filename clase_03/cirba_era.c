//en una matriz de 10 x 10 mostrar solo los primos
//con el metodo de la criba
#include <stdio.h>
#include <stdlib.h>
#define FILAS 10
#define COLUMNAS 10
#define TACHADO -1

int tomarNumeroNoTachado(matriz[][COLUMNAS])
{
  int i,j,res;
  
  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      if(matriz[i][j] == 0){
        res = matriz[i][j];
        matriz[i][j] = TACHADO;
        i=FILAS;break;
      }
    }
  }

  return res;
}

int main()
{
  int i,j,k=2;
  int matriz[FILAS][COLUMNAS];


  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      matriz[i][j] = k;
      k++;
    }
  }

  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      printf("%d ", matriz[i][j]);
    }
    putchar('\n');
  }


  puts("Presione enter para continuar");
  getchar();
  return 0;
}
