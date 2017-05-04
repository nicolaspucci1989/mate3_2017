#include <stdio.h>
#include <stdlib.h>
#define PRIMO 1
#define COMPUESTO 0



void primos(int v[], int tam);


int main()
{
    int i;
    int n=10;
    int v[n];

    primos(v,n);

    for (i = 0; i < n; i++) {
      printf("%d ", v[i]);
    }
    return 0;
}

void primos(int salida[], int tam)
{
  int i,k,j,n=100;
  int v[n];

  for(i=0; i<n; i++){
    v[i]=PRIMO;
  }

  v[0]=v[1]=COMPUESTO;
  for(i=2; i*i<n; i++)
    for(j=i*i; j<n; j+=i)
      v[j]=COMPUESTO;

  for(i=0, k=0; k<tam; i++){
    if(v[i]==PRIMO){
      salida[k]=i;
      k++;
    }
  }
}
