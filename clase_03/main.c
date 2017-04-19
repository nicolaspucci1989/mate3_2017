#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int esPrimo = 0;
  int i;
  int divisor = 1;
  char *cartel[] = {"Es primo", "No es primo"};
  int numero = 67;

  numero = ((int) sqrt(numero)) - 1;

  for(i=2; i<numero; i++){
    if(numero%i == 0){
      esPrimo = 1;
      divisor = i;
      break;
    }
  }

  printf("%s, divisor: %d\n", cartel[esPrimo], divisor);


  puts("Presione enter");
  getchar();
  return 0;
}
