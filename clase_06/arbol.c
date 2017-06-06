#include <stdio.h>
#include <stdlib.h>
#define VERTICES 5
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


void caminoSimple(int grafo[][VERTICES], int predecesor[], int distancia[], int fuente)
{
  int visitado[VERTICES];
  struct FIFO cola;
  int i,u;

	// Inicializar cola
  cola.primero = cola.ultimo = 0;

  // Marcar todos los vertice como no visitados
  for(i=0;i<VERTICES;i++)
    visitado[i]=FALSO;

  // Marcar el vertice actual como visitado y encolarlo
  visitado[fuente]=VERDADERO;
  encolar(&cola,fuente);
	predecesor[fuente]=-1;
  distancia[fuente]=0;

  while (!estaVacio(&cola)) {
    // Sacar un vertice de la cola.
    u = quitar(&cola);

    // Obtener todos los vertices adyacentes al vertice u
    // Si un nodo adyacente no fue visitado marcarlo como visitado y encolarlo
    for(i=0; i<VERTICES; i++){
			if(grafo[u][i] && !visitado[i]){
        visitado[i]=VERDADERO;
				predecesor[i]=u;
        distancia[i]=distancia[u]+1;
        encolar(&cola, i);
      }

    }

  }

}


int main()
{
	int destino=3, origen=0, aux[VERTICES];
	int predecesores[VERTICES], distancia[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0}};

  caminoSimple(grafo, predecesores,distancia,origen);
  for(destino=0;destino<VERTICES;destino++)
    printf("%d\n", distancia[destino]);
  return 0;
}
