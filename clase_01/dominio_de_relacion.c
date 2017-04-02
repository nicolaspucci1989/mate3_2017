#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(){
  int i;
  int conjuntoA[] = {1, 2, 3, 8};
  // int conjuntoA[ELEMENTOS_A];
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  // char conjuntoB[ELEMENTOS_B];
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  // struct relacion rel[ELEMENTOS_RELACION];
  // int dominio[ELEMENTOS_A] = {-1, -1, -1, -1};
  // char imagen[ELEMENTOS_B] = {-1, -1, -1, -1};

  for(i=0; i<ELEMENTOS_A; i++){
    if(estaEnDominio(conjuntoA[i], rel, conjuntoB))
    // if(estaEnLaRelacionX(conjuntoA[0], rel) != -1)
      printf("Elemento %d esta en el dominio\n", conjuntoA[i]);
    else
      printf("Elemento %d no esta en el dominio\n", conjuntoA[i]);
  }
  // printf("Ingrese %d elementos del conjunto A\n", ELEMENTOS_A);
  // ingresoConjuntoA(conjuntoA);
  // fflush(stdin);
  //
  //
  // printf("Ingrese %d elementos del conjunto B\n", ELEMENTOS_B);
  // ingresoConjuntoB(conjuntoB);
  //
  //
  // printf("ingrese %d elementos de la relacion", ELEMENTOS_RELACION);
  // ingresoRelacion(rel);




  fflush(stdin);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
