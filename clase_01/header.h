#ifndef HEADER_H
#define HEADER_H

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
int estaEnImagen(char n, struct relacion rel[], int conjuntoA[]);
int estaEnA(int n, int conjuntoA[]);
int estaEnLaRelacionY(char elementoY, struct relacion rel[]);
#endif
