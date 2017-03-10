// Ingresar 10 numeros, mostrar mayor y menor
#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 4


int main()
{
  int i;
  int maximo = -99999, minimo = 99999;
  int numero;


  printf("Ingrese %d numeros\n", CANTIDAD);
  for(i=0; i<CANTIDAD; i++){
    scanf("%d", &numero);
    if(numero > maximo)
      maximo = numero;
    if(numero < minimo)
      minimo = numero;
  }
  printf("Maximo %d\nMinimo %d\n", maximo, minimo);


  return 0;
}
