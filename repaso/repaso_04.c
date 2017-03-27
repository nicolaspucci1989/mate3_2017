// Ingreso de 15 numeros a un vector, imprimir los pares.
#include <stdio.h>
#include <stdlib.h>
#define NUMEROS 5


void ingreso(int v[])
{
  int i;
  for(i=0; i<NUMEROS; i++){
    scanf("%d", &v[i]);
  }
}


void imprimirPares(int v[])
{
  int i;
  for(i=0; i<NUMEROS; i++){
    if(v[i]%2 == 0)
      printf("%d ", v[i]);
  }
}


int main()
{
  int v[NUMEROS];
  printf("Ingrese %d numeros\n", NUMEROS);
  ingreso(v);
  printf("%s","Numeros pares: ");
  imprimirPares(v);
  return 0;
}
