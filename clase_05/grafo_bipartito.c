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

void imprimirVertices(int colores[VERTICES])
{
  int i;

  printf("Vertices X.\n");
  for(i=0;i<VERTICES;i++)
    if(colores[i]==ROJO)
      printf("%d ",i);


  printf("\nVertices Y.\n");
  for(i=0;i<VERTICES;i++)
    if(colores[i]==AZUL)
      printf("%d ",i);
}


int esBipartito(int grafo[][VERTICES], int colores[VERTICES], int fuente){
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

    // Encontrar todos los vertices adyacentes sin color
    for(v=0;v<VERTICES;v++){
      // Si existe una arista de u a v y si el destino v no tiene color
      if(grafo[u][v] && colores[v]==SIN_COLOR){
        // Asignarle el color opuesto al vertice v adyacente de u
        colores[v] = AZUL - colores[u];
        encolar(&cola, v);
      }
      // Si existe una arista de u a v y el destino v tiene el
      // mismo color que u no es bipartito
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
  int colores[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 0, 1},
                          {1, 0, 1, 0},
                          {0, 1, 0, 1},
                          {1, 0, 1, 0}};

  esBipartito(grafo,colores,0)?imprimirVertices(colores):puts("No es bipartito");
  return 0;
}
