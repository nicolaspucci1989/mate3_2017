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


void bfs(int grafo[][VERTICES], int predecesor[], int distancia[], int raiz)
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


int padreDe(int vertice, int predecesores[])
{
  return predecesores[vertice];
}


void antecesoresDe(int vertice, int predecesores[])
{
  int i;

  // Desde el vertice a la raiz, imprimir sus predecesores
  for(i=vertice; predecesores[i]!=-1; i=predecesores[i])
    printf("%d ", predecesores[i]);
}


void hijosDe(int raiz,  int predecesores[])
{
  int i;
  for(i=0; i<VERTICES; i++)
    if(predecesores[i]==raiz)
      printf("%d ", i);
}


void hermanosDe(int vertice, int predecesor[])
{
  int padre = predecesor[vertice];
  int i;

  // Si tiene el mismo padre y no es un vertice repetido, son hermanos
  for(i=0;i<VERTICES;i++){
    if(padre == predecesor[i] && vertice != i)
      printf("%d ", i);
  }
}


int esTerminal(int vertice, int predecesores[])
{
  int i, res = 1;

  // Si el vertice es predecesor de algun nodo no es terminal
  for(i=0;i<VERTICES;i++)
    if(predecesores[i]==vertice)
      res = 0;

  return res;
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

      // No imprimirr el primero
      if(u!=raiz)
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
	int origen=0, i, vertice;
	int predecesores[VERTICES], distancia[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 1, 0, 0},
                          {1, 0, 0, 0, 0},
                          {1, 0, 0, 1, 1},
                          {0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0}};

  // Cargar predecesores
  for(i=0;i<VERTICES;i++){
    predecesores[i]=-1;
  }

  // Breadth first search para cargar predecesores y distancias.
  bfs(grafo, predecesores,distancia,origen);

  // Padre
  vertice = 3;
  printf("Padre de %d: %d",vertice,padreDe(vertice, predecesores));
  putchar('\n');

  // Antecesores
  vertice = 4;
  printf("Antecesores de %d: ", vertice);
  antecesoresDe(vertice,predecesores);
  putchar('\n');

  // Hijos
  vertice = 2;
  printf("Hijos de %d: ", vertice);
  hijosDe(vertice,predecesores);
  putchar('\n');

  // Terminal
  vertice = 4;
  printf("Vertice %d ", vertice);
  esTerminal(vertice,predecesores)?printf("si"):printf("no");
  printf(" es terminal\n");

  // Hermanos
  vertice = 4;
  printf("Hermanos de %d: ", vertice);
  hermanosDe(vertice, predecesores);
  putchar('\n');

  // Descendientes
  vertice = 2;
  printf("Descendientes de %d: ", vertice);
  descendientesDe(vertice, predecesores);
  return 0;
}
