#include <stdio.h>
#include <stdlib.h>


int factorial(int n)
{
  int res;

  if(n == 1)
    res = 1;
  else
    res = n * factorial(n-1);

  return res;
}


int main()
{
  int n = 5;

  puts("Ingrese un entero.");
  scanf("%d", &n);
  printf("Factorial de %d:  %d\n", n, factorial(n));

  fflush(stdin);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
