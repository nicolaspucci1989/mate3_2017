#ifndef HEADER_H
#define HEADER_H

#define TAMVECTOR(x) ((sizeof x) / (sizeof *x))
#define ELEMENTOS_A 4
#define ELEMENTOS_B 4
#define ELEMENTOS_RELACION 2

struct relacion {
  int x;
  char y;
};

int estaEnLaRelacionX(int elementoX, struct relacion rel[]);
int estaEnB(char n, char conjuntoB[]);
int estaEnDominio(int n, struct relacion rel[], char conjuntoB[]);
void imprimirDominio(int v[]);
void imprimirImagen(char v[]);
void ingresoConjuntoA(int conjuntoA[]);
void ingresoConjuntoB(char conjuntoB[]);
void ingresoRelacion(struct relacion rel[]);
#endif
