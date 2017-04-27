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


void obtenerImagen(int n, char imagen[], int conjuntoA[],
                  char conjuntoB[], struct relacion rel[])
{
  int i,h,j,k;

  for(i=0,h=0;i<n;i++)
    for(j=0;j<n && rel[j].x!=-1;j++)
      if(conjuntoB[i]==rel[j].y)
        for(k=0;k<n;k++)
          if(conjuntoA[k]==rel[j].x){
            imagen[h]=conjuntoB[i];
            h++;
          }
}


void inicializarDominio(int n,int v[]){
  int i;
  for(i=0;i<n;i++)
    v[i]=-1;
}


void inicializarImagen(int n, char v[])
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


void imprimirImagen(int n, char v[])
{
  int i=0;
  printf("Imagen: ");
  while(v[i] != -1 && i<n){
    printf("%c ", v[i]);
    i++;
  }
  putchar('\n');
}


void imprimirDominio(int n, int v[])
{
  int i=0;
  printf("Dominio: ");
  while(v[i] != -1 && i<n){
    printf("%d ", v[i]);
    i++;
  }
  putchar('\n');
}

int main(){


  int n=4;
  int conjuntoA[] = {1, 2, 3, 8};
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  int dominio[n];
  char imagen[n];

  inicializarImagen(n,imagen);
  inicializarDominio(n,dominio);
  obtenerImagen(n,imagen,conjuntoA,conjuntoB,rel);
  imprimirImagen(n,imagen);

  fflush(stdin);
  putchar('\n');
  puts("Presione enter.");
  getchar();
  return 0;
}
