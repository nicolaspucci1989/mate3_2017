//ingreso de 15 numeros en un vector
// mostrar los de indice par.
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


void impresion(int v[])
{
  int i;
  for(i=0; i<NUMEROS; i++){
    if(i%2 == 0)
      printf("%d ", v[i]);
  }
  putchar('\n');
}


int main()
{
  int vector[NUMEROS];


  printf("Ingrese %d numeros\n", NUMEROS);


  ingreso(vector);
  fflush(stdin);
  printf("Numeros de indice par: ");
  impresion(vector);
  putchar('\n');


  puts("Presione una enter para continuar");
  getchar();
  return 0;
}
