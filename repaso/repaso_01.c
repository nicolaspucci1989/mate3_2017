// Ingreso de 10 numeros, mostrarlos ordenados, menor a mayor, mayor a menor.
#include <stdio.h>
#include <stdlib.h>
#define ELEMENTOS 5
#define FALSE 0
#define TRUE 1


void lectura(int vector[])
{
  int i;
  for(i=0; i<ELEMENTOS; i++){
    scanf("%d", &vector[i]);
  }
}


void imprimirVector(int vector[])
{
  int i;
  for(i=0; i<ELEMENTOS; i++){
    printf("%d ", vector[i]);
  }
  putchar('\n');
}


int comapararMayorMenor(int a, int b)
{
  return a > b;
}


int comapararMenorMayor(int a, int b)
{
  return a < b;
}


void bSort(int vector[], int (*comparacion)(int a, int b))
{
  int i;
  int intercambio;
  int temp;


  do {
    intercambio = FALSE;
    for(i=1; i<=ELEMENTOS-1; i++){
      if((*comparacion)(vector[i-1], vector[i])){
        temp = vector[i];
        vector[i] = vector[i-1];
        vector[i-1] = temp;
        intercambio = TRUE;
      }
    }
  } while(intercambio != FALSE);
}


int main()
{
  int vector[ELEMENTOS];

  printf("Ingrese %d numeros.\n", ELEMENTOS);
  lectura(vector);
  bSort(vector,comapararMayorMenor);
  imprimirVector(vector);
  bSort(vector,comapararMenorMayor);
  imprimirVector(vector);
  return 0;
}
