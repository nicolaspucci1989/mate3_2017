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


int compPar(int i, int v[])
{
  return v[i]%2 == 0;
}


int compImpar(int i, int v[])
{
  return v[i]%2 != 0;
}


void impresion(int v[], int (*comp)(int i, int vect[]))
{
  int i;

  for(i=0; i<ELEMENTOS; i++){
    if((*comp)(i, v))
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
