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


void inicializarDominio(int v[], int n){
  int i;
  for(i=0;i<n;i++)
    v[i]=-1;
}


void inicializarImagen(char v[], int n)
{
  int i;
  for(i=0;i<n;i++)
    v[i]=-1;
}


void ingresoConjuntoA(int n, int conjuntoA[])
{
  int i;

  printf("Ingrese conjunto A\n");
  for(i=0;i<n;i++){
    printf("$ ");
    scanf("%d", &conjuntoA[i]);
  }
}


void ingresoConjunoB(int n, char conjuntoB[])
{
  int i;

  printf("Ingrese conjunto B\n");
  for(i=0;i<n;i++){
    printf("$ ");
    scanf("%c", &conjuntoB[i]);
    fflush(stdin);
  }
}


void ingresoRelacion(int n, struct relacion rel[])
{
  int i;

  printf("Ingrese la relacion\n");
  for(i=0;i<n;i++){
    printf("Ingrese elemento x\n$");
    scanf("%d", &rel[i].x);
    fflush(stdin);
    printf("Ingrese elemento y\n$");
    scanf("%c", &rel[i].y);
    fflush(stdin);
  }
}


int main(){


  int i;
  int n=4;
  int conjuntoA[] = {1, 2, 3, 8};
  // int conjuntoA[ELEMENTOS_A];
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  // char conjuntoB[ELEMENTOS_B];
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  // struct relacion rel[ELEMENTOS_RELACION];
  int dominio[n];
  char imagen[n];

  n=2;
  ingresoRelacion(n,rel);
  for(i=0;i<n;i++){
    printf("%d %c\n", rel[i].x, rel[i].y);
  }


  fflush(stdin);
  putchar('\n');
  puts("Presione enter.");
  getchar();
  return 0;
}
