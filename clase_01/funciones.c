#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int estaEnLaRelacionX(int elementoX, struct relacion rel[])
{
  int i;
  int res = -1;
  for(i=0; i<ELEMENTOS_RELACION; i++){
    if(elementoX == rel[i].x){
      res = i;
      break;
    }
  }
  return res;
}

int estaEnB(char n, char conjuntoB[])
{
  int i;
  int res = 0;
  for(i=0; i<ELEMENTOS_B; i++){
    if(n == conjuntoB[i]){
      res = 1;
      break;
    }
  }
  return res;
}


int estaEnDominio(int n, struct relacion rel[], char conjuntoB[])
{
  int i=0;
  if((i = estaEnLaRelacionX(n, rel) != -1) && estaEnB(rel[i].y, conjuntoB))
    i = 1;
  return i;
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


void imprimirImagen(char v[])
{
  int i=0;
  printf("Imagen: ");
  while(v[i] != -1){
    printf("%c ", v[i]);
    i++;
  }
  putchar('\n');
}

void ingresoConjuntoA(int conjuntoA[])
{
  int i;
  for(i=0; i<ELEMENTOS_A; i++){
    scanf("%d", &conjuntoA[i]);
  }
}


void ingresoConjuntoB(char conjuntoB[])
{
  int i;
  for(i=0; i<ELEMENTOS_B; i++){
    scanf("%c", &conjuntoB[i]);
    fflush(stdin);
  }
}


void ingresoRelacion(struct relacion rel[])
{
  int i;
  for(i=0; i<ELEMENTOS_RELACION; i++)
  {
    scanf("%d", &rel[i].x);
    fflush(stdin);
    scanf("%c", &rel[i].y);
    fflush(stdin);
  }
}
