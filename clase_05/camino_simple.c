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

    // Obtener todos los vertices adyacentes al vertice u
    // Si un nodo adyacente no fue visitado marcarlo como visitado y encolarlo
    for(i=0; i<VERTICES; i++){
			if(grafo[u][i] && !visitado[i]){
        visitado[i]=VERDADERO;
				predecesor[i]=u;
        encolar(&cola, i);
      }

    }

  }

  return visitado[destino]==VERDADERO;
}


void impresion(int predecesores[], int vector[], int origen, int destino)
{
  int j=VERTICES-1,i;

  for (i = 0; i < VERTICES; i++)
    vector[i]=-1;

  vector[j] = destino;
	for(j=j-1, i=destino; predecesores[i]!=-1; i=predecesores[i], j--){
    vector[j]=predecesores[i];
  }

  for (i = 0; i < VERTICES; i++)
    if(vector[i]!=-1)
      printf("%d ", vector[i]+1);

}


int main()
{
	int destino=3, origen=0, vector[VERTICES];
	int predecesores[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 1, 0},
                          {1, 0, 0, 0},
                          {1, 0, 0, 1},
                          {0, 0, 1, 0}};

  if(!caminoSimple(grafo, predecesores, origen,destino))
		printf("No existe un camino.");
	else{
		printf("existe camino\n");
    impresion(predecesores,vector,origen,destino);
	}

  return 0;
}
