// Ingresar 10 numeros, mostrar mayor y menor
#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 4


void maximo(int numero, int *maximo)
{
  if(numero > *maximo)
    *maximo = numero;
}


void minimo(int numero, int *minimo)
{
  if(numero < *minimo)
    *minimo = numero;
}


int main()
{
  int i;
  int max = -99999, min = 99999;
  int numero;


  printf("Ingrese %d numeros\n", CANTIDAD);
  for(i=0; i<CANTIDAD; i++){
    scanf("%d", &numero);
    minimo(numero, &min);
    maximo(numero, &max);
  }
  printf("Maximo %d\nMinimo %d\n", max, min);


  return 0;
}
