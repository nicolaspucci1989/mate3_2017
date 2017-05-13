#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int r=rand()%2;
  int n=5;
  int matriz[n][n];
  int i,j;

	//Inicializa matriz en -1
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      matriz[i][j]=-1;

  for(i=0;i<n;i++)
    matriz[i][i]=r;

  /*Recorre la mitad superior a la diagonal y
	asigna el mismo numero al otro extremo*/
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++){
      r=rand()%2;
      matriz[i][j]=r;
      matriz[j][i]=r;
    }


	//Imprime matriz
  for(i=0;i<n;i++){
    for(j=0;j<n; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }

  return 0;
}
