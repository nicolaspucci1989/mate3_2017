#include <stdio.h>
#include <stdlib.h>


int main()
{
  int n=5;
  int matriz[n][n];
  int i,j;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      matriz[i][j]=-1;

  for(i=0;i<n;i++)
    matriz[i][i]=0;

  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      matriz[i][j]=1;


  for(i=0;i<n;i++){
    for(j=0;j<n; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }

  return 0;
}
