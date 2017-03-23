//Ingreso de una matriz 2x2
//mostrar determinante
#include <stdio.h>
#include <stdlib.h>


void ingreso(int matriz[][2])
{
  int i, j;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("Ingrese elemento %d %d\n", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
}


int determinante(int matriz[][2])
{
  return matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
}


int main()
{
  int matriz[2][2];

  printf("Ingrese una matriz de 2 x 2\n");
  ingreso(matriz);
  fflush(stdin);
  printf("Determinante %d\n", determinante(matriz));

  puts("Presione una tecla para continuar");
  getchar();
  return 0;
}
