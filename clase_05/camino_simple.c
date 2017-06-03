#include <stdio.h>
#include <stdlib.h>
#define VERTICES 4
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


int caminoSimple(int grafo[][VERTICES], int fuente, int destino){
  int visitado[VERTICES];
  int res=FALSO;
  struct FIFO cola;
  int i;
  int u;
  cola.primero = cola.ultimo = 0;
  // Marcar todos los vertice como no visitados
  for(i=0;i<VERTICES;i++)
    visitado[i]=FALSO;

  // Marcar el vertice actual como visitado y encolarlo
  visitado[fuente]=VERDADERO;
  encolar(&cola,fuente);

  while (!estaVacio(&cola)) {
    // Sacar un vertice de la cola. Imprimirlo
    u = quitar(&cola);
    printf("%d ", u);

    // Obtener todos los vertices adyacentes al vertice v
    // Si un nodo adyacente no fue visitado marcarlo como visitado y encolarlo
    for(i=grafo[u][0]; i<VERTICES; i++){
      // Si el nodo adyacente es el destino, retornar VERDADERO
      if(i==destino){
        res = VERDADERO;
        break;
      }

      // Si no seguir con buscando con BFS
      if(!visitado[i]){
        visitado[i] = VERDADERO;
        encolar(&cola, i);
      }
    }
  }

  return res;
}

int main()
{
  int grafo[][VERTICES] = {{0, 1, 0, 1},
                          {1, 0, 0, 1},
                          {1, 0, 0, 0},
                          {0, 1, 0, 1}};
  if(!caminoSimple(grafo, 0,3))
		printf("No existe un camino.");

	putchar('\n');

  return 0;
}
