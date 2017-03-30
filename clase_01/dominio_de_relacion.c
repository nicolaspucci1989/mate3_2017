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


int estaEnImagen(char elementoB, char conjuntoB[])
{
  int i;
  char res=-1;

  //por cada elemento del conjuto B
  //esta el elementoB?
  for(i=0; i<ELEMENTOS_B; i++){
    if(conjuntoB[i] == elementoB){
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


void buscarImagen(struct relacion rel[], char conjuntoB[], char imagen[])
{
  int i, j=0;


  for(i=0; i<ELEMENTOS_RELACION; i++){
    if(estaEnImagen(rel[i].elementoY, conjuntoB)){
      imagen[j] = rel[i].elementoY;
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
    scanf("%d", &rel[i].elementoX);
    fflush(stdin);
    scanf("%c", &rel[i].elementoY);
    fflush(stdin);
  }
}


int main(){
  // int conjuntoA[] = {1, 2, 3, 8};
  int conjuntoA[ELEMENTOS_A];
  // char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  char conjuntoB[ELEMENTOS_B];
  // struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  struct relacion rel[ELEMENTOS_RELACION];
  int dominio[ELEMENTOS_A] = {-1, -1, -1, -1};
  char imagen[ELEMENTOS_B] = {-1, -1, -1, -1};


  printf("Ingrese %d elementos del conjunto A\n", ELEMENTOS_A);
  ingresoConjuntoA(conjuntoA);
  fflush(stdin);


  printf("Ingrese %d elementos del conjunto B\n", ELEMENTOS_B);
  ingresoConjuntoB(conjuntoB);


  printf("ingrese %d elementos de la relacion", ELEMENTOS_RELACION);
  ingresoRelacion(rel);


  buscarDominio(rel, conjuntoA, dominio);
  buscarImagen(rel, conjuntoB, imagen);

  imprimirDominio(dominio);
  imprimirImagen(imagen);


  fflush(stdin);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
