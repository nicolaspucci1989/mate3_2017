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


int padreDe(int vertice, int predecesores[])
{
  return predecesores[vertice];
}


void antecesoresDe(int vertice, int predecesores[])
{
  int i;

  for(i=vertice; i > 0; i=predecesores[i])
    printf("%d\n", predecesores[i]+1);
}


void hijosDe(int raiz,  int predecesores[])
{
  int i;
  printf("Hijos de %d\n", raiz+1);
  for(i=0; i<VERTICES; i++)
    if(predecesores[i]==raiz)
      printf("%d ", i+1);
}


void hermanosDe(int vertice, int predecesor[])
{
  int padre = predecesor[vertice];
  int i;

  // Si tiene el mismo padre, son hermanos
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


int main()
{
	int origen=0, i;
	int predecesores[VERTICES], distancia[VERTICES];
  int grafo[][VERTICES] = {{0, 1, 1, 0, 0},
                          {1, 0, 0, 0, 0},
                          {1, 0, 0, 1, 1},
                          {0, 0, 0, 1, 0},
                          {0, 0, 0, 1, 0}};

  for(i=0;i<VERTICES;i++){
    predecesores[i]=-1;
  }
  caminoSimple(grafo, predecesores,distancia,origen);
  for(i=0;i<VERTICES;i++)
    printf("Predecesor %d: %d\n", i+1, padreDe(i,predecesores));
  putchar('\n');
  antecesoresDe(4,predecesores);
  putchar('\n');
  hijosDe(2,predecesores);
  putchar('\n');
  esTerminal(4,predecesores)?printf("Si"):printf("No");
  printf(" es terminal\n");
  printf("Hermanos de 4\n");
  hermanosDe(4, predecesores);
  return 0;
}
