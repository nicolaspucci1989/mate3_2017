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


void caminoSimple(int grafo[][VERTICES], int predecesor[], int distancia[], int raiz)
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
  visitado[raiz]=VERDADERO;
  encolar(&cola,raiz);
	predecesor[raiz]=-1;
  distancia[raiz]=0;

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

void descendientesDe(int raiz, int predecesores[])
{
  int i, u;
  struct FIFO cola;
  cola.primero = cola.ultimo = 0;

  // A partir de la raiz busco los descendientes
  // Poner vertice en cola
  encolar(&cola,raiz);

  // Mientras la cola no este vacia
  while(!estaVacio(&cola)){

      // quitar un elemento
      u = quitar(&cola);

      // imprimirlo
      printf("%d ", u);

      // buscar descendientes y ponerlos en cola
      for(i=0;i<VERTICES;i++)
        // Si u es predecesor de i, ponerlo en cola.
        if(predecesores[i]==u)
          encolar(&cola,i);
  }
}


int main()
{

	int raiz=0, i;
	int predecesores[VERTICES], distancia[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 1, 0, 0},
                          {1, 0, 0, 0, 0},
                          {1, 0, 0, 1, 1},
                          {0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0}};

  for(i=0;i<VERTICES;i++){
    predecesores[i]=-1;
  }
  caminoSimple(grafo, predecesores,distancia,raiz);
  for(i=0;i<VERTICES;i++){
    printf("%d ", predecesores[i]);
  }
  raiz=3;

  printf("\ndescendientes de %d\n", raiz);
  descendientesDe(raiz, predecesores);
  return 0;
}
