#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(){
  int i, j;
  int conjuntoA[] = {1, 2, 3, 8};
  // int conjuntoA[ELEMENTOS_A];
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  // char conjuntoB[ELEMENTOS_B];
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  // struct relacion rel[ELEMENTOS_RELACION];
  int dominio[ELEMENTOS_A] = {-1, -1, -1, -1};
  // char imagen[ELEMENTOS_B] = {-1, -1, -1, -1};

  for(i=0, j=0; i<ELEMENTOS_A; i++){
    if(estaEnDominio(conjuntoA[i], rel, conjuntoB)){
      dominio[j] = conjuntoA[i];
      j++;
    }
  }

  imprimirDominio(dominio);


  fflush(stdin);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
