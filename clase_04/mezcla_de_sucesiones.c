#include <stdio.h>
#include <stdlib.h>

void primos(int v[], int n);
int fibo(int n);

int main()
{


  puts("Presione enter para continuar");
  getchar();
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

int fibo(int n)
{
  int res;

  if(n == 0)
    res = 0;
  else if(n == 1)
    res = 1;
  else
    res = (fibo(n-1) + fibo(n-2));

  return res;
}
