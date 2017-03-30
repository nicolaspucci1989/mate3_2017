#include <stdio.h>
#include <stdlib.h>
#define ELEMENTOS_A 4
#define ELEMENTOS_B 4
#define ELEMENTOS_RELACION 2
#define TAMVECTOR(x) ((sizeof x) / (sizeof *x))

struct relacion {
  int elementoX;
  char elementoY;
};


int estaEnDominio(int elementoA, int conjuntoA[])
{
  int i;
  int res=0;

  //por cada elemento del conjuto A
  //esta el elementoA?
  for(i=0; i<ELEMENTOS_A; i++){
    if(conjuntoA[i] == elementoA){
      res = 1;
      break;
    } else
      res = 0;
  }
  return res;
}


void buscarDominio(struct relacion rel[], int conjuntoA[], int dominio[])
{
  int i, j=0;


  for(i=0; i<ELEMENTOS_RELACION; i++){
    if(estaEnDominio(rel[i].elementoX, conjuntoA)){
      dominio[j] = rel[i].elementoX;
      j++;
    }
  }
}


void imprimirDominio(int v[])
{
  int i=0;
  printf("Dominio: ");
  while(v[i] != -1){
    printf("%d ", v[i]);
    i++;
  }
  putchar('\n');
}


int main(){
  int conjuntoA[] = {1, 2, 3, 8};
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  int dominio[ELEMENTOS_A] = {-1, -1, -1, -1};

  buscarDominio(rel, conjuntoA, dominio);
  imprimirDominio(dominio);

  puts("Presione enter para continuar");
  getchar();
  return 0;
}
