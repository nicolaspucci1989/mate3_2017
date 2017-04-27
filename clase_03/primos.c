#include <stdio.h>
#include <stdlib.h>
#define PRIMO 1
#define COMPUESTO 0



void primos(int v[], int n);


int main()
{
    int i,k,n=100;
    int v[n];

    for(i=0; i<n; i++){
      v[i]=PRIMO;
    }


    primos(v,n);


    for(i=0, k=1; i<n; i++){
      if(v[i]==PRIMO){
        printf("%-4.d%c", i,(k%5)?' ':'\n');
        k++;
      }
    }
    return 0;
}

void primos(int v[], int n)
{
  int i,j;

  v[0]=v[1]=COMPUESTO;
  for(i=2; i*i<n; i++)
    for(j=i*i; j<n; j+=i)
      v[j]=COMPUESTO;
}
