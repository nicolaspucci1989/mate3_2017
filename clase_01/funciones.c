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

int estaEnLaRelacionY(char elementoY, struct relacion rel[])
{
  int i;
  int res = -1;
  for(i=0; i<ELEMENTOS_RELACION; i++){
    if(elementoY == rel[i].y){
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

int estaEnA(int n, int conjuntoA[])
{
  int i;
  int res = 0;
  for(i=0; i<ELEMENTOS_A; i++){
    if(n == conjuntoA[i]){
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

int estaEnImagen(char n, struct relacion rel[], int conjuntoA[])
{
  int i=0;
  if((i = estaEnLaRelacionY(n, rel) != -1) && estaEnA(rel[i].x, conjuntoA))
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

  return;
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

  return;
}
