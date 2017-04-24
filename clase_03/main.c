#include <stdio.h>
#include <stdlib.h>


void primos(int v[], int n);


int main()
{
    int v[100];
    int i, n=100;

    for(i=0; i<n; i++){
      v[i]=1;
    }


    primos(v,n);


    for(i=0; i<n; i++){
      if(v[i]==1)
        printf("%d\n", i);
    }
    return 0;
}

void primos(int v[], int n)
{
  int i,j;

  v[0]=v[1]=0;
  for(i=2; i*i<n; i++)
    for(j=i*i; j<n; j+=i)
      v[j]=0;
}
