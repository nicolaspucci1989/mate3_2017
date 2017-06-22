#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 4

void imprimirMatriz(int matriz[FILAS][COLUMNAS])
{
  int i,j;
  for(i=0;i<FILAS;i++){
    for(j=0;j<COLUMNAS;j++){}
      printf("%d ", matriz[i][j]);
    putchar('\n');
  }
}

void cargarMatriz(int matriz[FILAS][COLUMNAS])
{
  int i,j;
  for(i=0;i<FILAS;i++)
    for(j=0;j<COLUMNAS;j++)
      scanf("%d", &matriz[i][j]);

  fflush(stdin);
}


int sumaDiagonal(int matriz[FILAS][COLUMNAS])
{
  int i,acum=0;
  for(i=0;i<FILAS;i++)
    acum+=matriz[i][i];

  return acum;
}

void positivosNegativos(int matriz[FILAS][COLUMNAS])
{
  int i,j,negativos=0,positivos=0;

  for(i=0;i<FILAS;i++)
    for(j=0;j<COLUMNAS;j++){
      if(matriz[i][j]>0)
        positivos++;
      if(matriz[i][j]<0)
        negativos++;
    }

  printf("Positivos %d\n", positivos);
  printf("Negativos %d\n", negativos);
}

void valorMaximo(int matriz[FILAS][COLUMNAS])
{
  int i,j,maximo=-99999999;

  for(i=0;i<FILAS;i++)
    for(j=0;j<COLUMNAS;j++)
      if(matriz[i][j]>maximo)
        maximo=matriz[i][j];
        
  printf("Maximo: %d\n", maximo);
  printf("Posicion:");

  for(i=0;i<FILAS;i++)
    for(j=0;j<COLUMNAS;j++)
      if(matriz[i][j] == maximo)
        printf("(%d,%d) ", i,j);
}

int main()
{
  int matriz[FILAS][COLUMNAS];
  printf("Ingrese los elementos de la matriz\n");
  cargarMatriz(matriz);
  putchar('\n');
  imprimirMatriz(matriz);
  printf("Suma de la diagonal = %d\n", sumaDiagonal(matriz));
  positivosNegativos(matriz);
  valorMaximo(matriz);

  puts("Presione enter para continuar");
  getchar();
  return 0;
}
