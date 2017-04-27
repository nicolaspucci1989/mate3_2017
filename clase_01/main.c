#include <stdio.h>
#include <stdlib.h>
#define COLUMNAS 3

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

int esRefelxiva(int n, int rel[][COLUMNAS])
{
  int reflexiva=0;
  int i;

  for(i=0;i<n;i++){
    if(rel[i][i]==0){
      reflexiva=1;
      break;
    }
  }

  return reflexiva;
}

int antisimetrica(int n, int rela[][COLUMNAS])
{
  int i,j;
  int anti=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(rela[i][j]==1 && rela[j][i]==1){
        anti=1;
        i=n;break;
      }
    }
  }
  return anti;
}


int transitiva(int n, int m[][COLUMNAS])
{
  int transi=0;
  int i,j,k;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(m[i][j])
        for(k=0;k<n;k++)
          if(m[j][k]==1 && m[i][k]!=1)
            transi=1;

  return transi;
}


int main(){


  char *cartel[] = {"reflex", "no reflex"};
  char *cartel2[] = {"anti", "no anti"};
  char *cartel3[] = {"transitiva", "no transitiva"};
  int n = 10;
  int conjuntoA[n];
  char conjuntoB[n];
  struct relacion rel[n];
  int dominio[n];
  char imagen[n];
  int rela[3][3]={{1,0,1},
                  {0,1,0},
                  {0,1,1}};
  //
  // inicalizarRelacion(n, rel);
  // inicializarImagen(n,imagen);
  // inicializarDominio(n,dominio);
  //
  //
  // ingresoConjuntoA(n,conjuntoA);
  // fflush(stdin);
  // ingresoConjuntoB(n,conjuntoB);
  // ingresoRelacion(n,rel);
  //
  //
  // obtenerDominio(n,dominio,conjuntoA,conjuntoB,rel);
  // obtenerImagen(n,imagen,conjuntoA,conjuntoB,rel);
  //
  // imprimirDominio(n,dominio);
  // imprimirImagen(n,imagen);


  printf("%s\n", cartel[esRefelxiva(3,rela)]);
  printf("%s\n", cartel2[antisimetrica(3,rela)]);
  printf("%s\n", cartel3[transitiva(3,rela)]);
  fflush(stdin);
  putchar('\n');
  puts("Presione enter.");
  getchar();
  return 0;
}
