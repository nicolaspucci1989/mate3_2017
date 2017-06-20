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

	//Buscar unos en y sobre de la diagonal
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

void gradoVertices(int matriz[FILAS][COLUMNAS], int n, int grados[])
{
	int i,j;
	for(i=0;i<n;i++){
		//Buscar unos en la fila
		for(j=0;j<n;j++)
			if(matriz[i][j])
				grados[i]+=1;
		//Si hau un uno en la diagonal vale doble
		if(matriz[i][i])
			grados[i]+=1;
	}
}

int main()
{
	srand(time(NULL));
  int n=FILAS;
  int matriz[n][n];
	int grados[]={0,0,0,0};
	int i;

	inicializarMatriz(matriz,-1,n);

	recorrerDiagonal(matriz,n);

	recorrerMitadSuperior(matriz,n);

	puts("Matriz:");
	imprimirMatriz(matriz,n);
	putchar('\n');

	printf("Numero de lazos: %d\n", numeroDeLazos(matriz, n));
	printf("Numero de aristas: %d\n", numeroDeAristas(matriz, n));

	gradoVertices(matriz,n,grados);

	for(i=0;i<n;i++){
		printf("Grado vertice %d: %d\n", i+1, grados[i]);
	}

	getchar();
	return 0;
}
