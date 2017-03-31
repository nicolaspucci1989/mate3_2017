#include <stdio.h>
#include <stdlib.h>
#define ELEMENTOS_A 4
#define ELEMENTOS_B 4
#define ELEMENTOS_RELACION 2
#define TAMVECTOR(x) ((sizeof x) / (sizeof *x))

struct relacion {
  int x;
  char y;
};


  // segun un x que pertenece al conjunto A
  // si x esta relacionado con algun b que pertenece a B
  // x esta en el dominio

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


int main(){
  int conjuntoA[] = {1, 2, 3, 8};
  // int conjuntoA[ELEMENTOS_A];
  char conjuntoB[] = {'a' ,'b', 'j', 'k'};
  // char conjuntoB[ELEMENTOS_B];
  struct relacion rel[]= {{1,'b'}, {8, 'k'}};
  // struct relacion rel[ELEMENTOS_RELACION];
  // int dominio[ELEMENTOS_A] = {-1, -1, -1, -1};
  // char imagen[ELEMENTOS_B] = {-1, -1, -1, -1};

  if(estaEnDominio(conjuntoA[3], rel, conjuntoB))
  // if(estaEnLaRelacionX(conjuntoA[0], rel) != -1)
    printf("%s\n", "Esta en dominio");
  else
    printf("%s\n", "No esta en dominio");
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
