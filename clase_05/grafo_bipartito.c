#include <stdio.h>
#include <stdlib.h>
#define VERTICES 4
#define SIN_COLOR -1
#define ROJO 0
#define AZUL 1
#define VERDADERO 1
#define FALSO 0

// Cola FIFO
struct FIFO{
  int elementos[100];
  int primero;
  int ultimo;
};


void encolar(struct FIFO *cola, int vertice)
{
  cola->elementos[cola->ultimo] = vertice;
  cola->ultimo++;
}


int quitar(struct FIFO *cola)
{
  int retorno = cola->elementos[cola->primero];
  cola->primero++;
  return retorno;
}


int estaVacio(struct FIFO *cola){
  return cola->primero == cola->ultimo;
}


int esBipartito(int grafo[][VERTICES], int fuente){
  int colores[VERTICES];
  int i;
  int u,v;
  int res = VERDADERO;
  struct FIFO cola;
  cola.primero = cola.ultimo = 0;


  for(i=0;i<VERTICES;i++){
    colores[i]=SIN_COLOR;
  }

  colores[fuente]=AZUL;

  encolar(&cola, fuente);

  while(!estaVacio(&cola)){
    u = quitar(&cola);

    for(v=0;v<VERTICES;v++){
      if(grafo[u][v] && colores[v]==SIN_COLOR){
        colores[v] = AZUL - colores[u];
        encolar(&cola, v);
      }
      else if(grafo[u][v] && colores[v] == colores[u]){
        res = FALSO;
        break;
      }
    }
  }
  return res;
}

int main()
{
  int grafo[][VERTICES] = {{0, 1, 0, 1},
                          {1, 0, 1, 0},
                          {0, 1, 0, 1},
                          {1, 0, 1, 0}};

  esBipartito(grafo,0)?puts("Es Bipartito"):puts("No es bipartito");

  return 0;
}
