#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void obtenerDominio(int n, int dominio[], int conjuntoA[],
                  char conjuntoB[], struct relacion rel[])
{
  int i,h,j,k;
  for(i=0,h=0;i<n;i++)
    for(j=0;j<n;j++)
      if(conjuntoA[i]==rel[j].x)
        for(k=0;k<n;k++)
          if(conjuntoB[k]==rel[j].y){
            dominio[h]=conjuntoA[i];
            h++;
          }
}


void obtenerImagen(int n, char imagen[], char conjuntoB[],
                  int conjuntoA[], struct relacion rel[])
{
  int i,h,j,k;

  for(i=0,h=0;i<n;i++)
    for(j=0;j<n;j++)
      if(conjuntoB[i]==rel[j].y)
        for(k=0;k<n;k++)
          if(conjuntoA[k]==rel[j].x){
            imagen[h]=conjuntoB[i];
            h++;
          }
}


int main(){


  int n=4;
  int conjuntoA[] = {1, 2, 3, 8};
  // int conjuntoA[ELEMENTOS_A];
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  // char conjuntoB[ELEMENTOS_B];
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  // struct relacion rel[ELEMENTOS_RELACION];
  int dominio[] = {-1, -1, -1, -1};
  char imagen[] = {-1, -1, -1, -1};

  obtenerDominio(n,dominio,conjuntoA,conjuntoB,rel);
  imprimirDominio(dominio);
  obtenerImagen(n,imagen,conjuntoB,conjuntoA,rel);
  imprimirImagen(imagen);
  
  return 0;
}
