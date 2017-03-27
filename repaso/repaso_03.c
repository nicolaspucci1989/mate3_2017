  //Ingreso de 20 numeros, mostar pares e imparess
#include <stdio.h>
#include <stdlib.h>
#define ELEMENTOS 10

void ingreso(int v[])
{
  int i;
  for(i=0; i<ELEMENTOS; i++)
    scanf("%d", &v[i]);
}


void intercambio(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}


void segregarParesImpares(int v[])
{
  int izquierda = 0, derecha = ELEMENTOS - 1;
  while(izquierda < derecha){
    while (v[izquierda]%2 == 0 && izquierda < derecha )
      izquierda++;

    while (v[derecha]%2 == 1 && izquierda < derecha)
      derecha--;

    if(izquierda < derecha){
      intercambio(&v[izquierda], &v[derecha]);
      izquierda++;
      derecha--;
    }
  }
}
void impresion(int v[])
{
  int i;

  for(i=0; i<ELEMENTOS; i++){
    printf("%d ", v[i]);
  }
  putchar('\n');
}


int main()
{
  int v[ELEMENTOS];
  printf("Ingrese %d numeros\n", ELEMENTOS);
  ingreso(v);
  segregarParesImpares(v);
  impresion(v);

  return 0;
}
