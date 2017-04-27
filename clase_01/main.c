#include <stdio.h>
#include <stdlib.h>
#define TAMANIO(x) ((sizeof x) / (sizeof *x))

struct relacion {
  int x;
  char y;
};

void obtenerDominio(int n, int dominio[], int conjuntoA[],
                  char conjuntoB[], struct relacion rel[])
{
  int i,h,j,k;
  for(i=0,h=0;i<n && conjuntoA[i]!=-1;i++)
    for(j=0;j<n && rel[j].x!=-1;j++)
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

  for(i=0,h=0;i<n && conjuntoB[i]!=-1;i++)
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


void inicalizarRelacion(int n, struct relacion rel[])
{
  int i;
  for(i=0;i<n;i++)
    rel[i].x = rel[i].y = -1;
}


void ingresoConjuntoA(int n, int conjuntoA[])
{
  int i=0,aux=1;

  printf("Ingrese conjunto A, fin con -1.\n");
  while(i<n && aux!=-1){
    printf("$ ");
    scanf("%d", &aux);
    conjuntoA[i]=aux;
    i++;
  }

}


void ingresoConjuntoB(int n, char conjuntoB[])
{
  int i=0;
  char aux=1;

  printf("Ingrese conjunto B, fin con Z.\n");
  while(i<n && aux!='Z'){
    printf("$ ");
    scanf("%c", &aux);
    conjuntoB[i]=aux;
    i++;
    fflush(stdin);
  }
}


void ingresoRelacion(int n, struct relacion rel[])
{
  int i=0;
  printf("Ingrese la relacion\n");
  printf("Ingrese elemento x\n$");
  scanf("%d", &rel[i].x);
  while(i<n && rel[i].x!=-1){
    fflush(stdin);
    printf("Ingrese elemento y\n$");
    scanf("%c", &rel[i].y);
    fflush(stdin);
    i++;
    printf("Ingrese elemento x\n$");
    scanf("%d", &rel[i].x);
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


  int n = 10;
  int conjuntoA[n];
  char conjuntoB[n];
  struct relacion rel[n];
  int dominio[n];
  char imagen[n];

  inicalizarRelacion(n, rel);
  inicializarImagen(n,imagen);
  inicializarDominio(n,dominio);


  ingresoConjuntoA(n,conjuntoA);
  fflush(stdin);
  ingresoConjuntoB(n,conjuntoB);
  ingresoRelacion(n,rel);


  obtenerDominio(n,dominio,conjuntoA,conjuntoB,rel);
  obtenerImagen(n,imagen,conjuntoA,conjuntoB,rel);

  imprimirDominio(n,dominio);
  imprimirImagen(n,imagen);

  fflush(stdin);
  putchar('\n');
  puts("Presione enter.");
  getchar();
  return 0;
}
