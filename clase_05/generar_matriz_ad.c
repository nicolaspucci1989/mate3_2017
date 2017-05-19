#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 4
#define COLUMNAS 4


void inicializarMatriz(int matriz[FILAS][COLUMNAS], int valor, int tam)
{
	int i,j;
  for(i=0;i<tam;i++)
    for(j=0;j<tam;j++)
      matriz[i][j]=valor;
}


void recorrerDiagonal(int matriz[FILAS][COLUMNAS],int n)
{
 	int r=rand()%2;
	int i;
  for(i=0;i<n;i++)
    matriz[i][i]=r;
}


void recorrerMitadSuperior(int matriz[FILAS][COLUMNAS], int n)
{
	int i,j,r;

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			r=rand()%2;
			matriz[i][j]=r;
			matriz[j][i]=r;
		}
}


void imprimirMatriz(int matriz[FILAS][COLUMNAS], int n)
{
	int i,j;

  for(i=0;i<n;i++){
    for(j=0;j<n; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }

}

int numeroDeAristas(int matriz[FILAS][COLUMNAS], int n)
{
	int i,j,aristas=0;

	//Buscar unos encima de la diagonal
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(matriz[i][j]==1)
				aristas++;

	return aristas;
}

int numeroDeLazos(int matriz[FILAS][COLUMNAS], int n)
{
	int i;
	int lazos = 0;

	//Buscar unos en la diagonal
	for(i=0;i<n;i++)
		if(matriz[i][i]==1)
			lazos++;

	return lazos;
}


int main()
{
	srand(time(NULL));
  int n=FILAS;
  int matriz[n][n];

	inicializarMatriz(matriz,-1,n);

	recorrerDiagonal(matriz,n);

	recorrerMitadSuperior(matriz,n);

	imprimirMatriz(matriz,n);

	printf("Numero de lazos: %d\n", numeroDeLazos(matriz, n));
	printf("Numero de aristas: %d\n", numeroDeAristas(matriz, n));

  return 0;
}
