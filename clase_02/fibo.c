#include <stdio.h>
#include <stdlib.h>


int fibo(int n)
{
  int res;

  if(n == 2 || n == 1)
    res = 1;
  else
    res = fibo(n-1) + fibo(n-2);

  return res;
}


int main()
{

  int n;

  puts("Ingrese el termino a calcular.");
  scanf("%d", &n);
  printf("Termino Fibonacci %d: %d\n", n, fibo(n));

  fflush(stdin);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
