//Ingreso de 20 numeros, mostar pares e imparess
#include <stdio.h>
#include <stdlib.h>
#define ELEMENTOS 4

void ingreso(int v[])
{
  int i;
  for(i=0; i<ELEMENTOS; i++)
    scnaf("%d", &v[i]);
}


int compPar(int a)
{
  return a%2 == 0;
}


int compImpar(int a)
{
  return a%2 != 0;
}


void impresion(int v[], int (*comp)(int a))
{
  int i;

  for(i=0; i<ELEMENTOS; i++){
    if((*comp)(v[i]))
      printf("%d", v[i]);
  }
  putchar('\n');
}


int main()
{
  int v[ELEMENTOS];
  ingreso(v);
  impresion(v, compPar);
  impresion(v, compImpar);

  return 0;
}
