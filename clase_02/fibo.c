#include <stdio.h>
#include <stdlib.h>


int fibo(int n)
{
  int res;

  // if(n == 2 || n == 1)
  //   res = 1;
  if(n == 0)
    res = 0;
  else if(n == 1)
    res = 1;
  else
    res = (fibo(n-1) + fibo(n-2));

  return res;
}


int main()
{

  int n;
  int i;

  puts("Ingrese el termino a calcular.");
  scanf("%d", &n);

  for(i=1; i<=n; i++){
    printf("%d ", fibo(i));
  }


  fflush(stdin);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
