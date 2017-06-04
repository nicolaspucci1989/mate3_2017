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


int caminoSimple(int grafo[][VERTICES], int predecesor[], int fuente, int destino){
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

  while (!estaVacio(&cola)) {
    // Sacar un vertice de la cola.
    u = quitar(&cola);

    // Obtener todos los vertices adyacentes al vertice v
    // Si un nodo adyacente no fue visitado marcarlo como visitado y encolarlo
    for(i=0; i<VERTICES; i++){
			if(grafo[u][i]==1 && visitado[i]==FALSO){
        visitado[i] = VERDADERO;
				predecesor[i]=u;
        encolar(&cola, i);
      }
    }
  }

  return visitado[destino]==VERDADERO;
}

int main()
{
	int i, destino=3;
	int predecesores[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 1, 0},
                          {1, 0, 0, 0},
                          {1, 0, 0, 1},
                          {0, 0, 1, 0}};

  if(!caminoSimple(grafo, predecesores, 0,destino))
		printf("No existe un camino.");
	else{
		printf("existe camino\n");
		for(i=destino;predecesores[i]!=-1;i=predecesores[i])
			printf("%d ",predecesores[i]);
	}

	putchar('\n');

  return 0;
}
