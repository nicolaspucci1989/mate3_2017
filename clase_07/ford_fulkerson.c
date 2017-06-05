#include <stdio.h>
#include <stdlib.h>
// Definiciones basicas

#define NODO_INICIALIZADO 0  // Nodo inicializado
#define NODO_EN_COLA 1 // Nodo en cola
#define NODO_ALCANZADO 2 // Nodo alcanzado
#define MAX_NODOS 20
#define INFINITO 10000

// Declaraciones

void formatoDeArchivo(){
  printf("\nFormato de archivo de entrada:\n");
  printf("<cantidad de nodos> <cantidad de vertices> <fuente> <sumidero>\n");
  printf("<vertice 1> <vertice 2> <capacidad>\n");
  printf(".\n.\n.\n");
  printf("<vertice n> <vertice m> <capacidad>\n");
}

int min (int x, int y) { // devuelve el minimo de x e y
  return x<y ? x : y;
}

// Una cola LIFO para Breadth-First Search

void agregarElemento (int x, int cola[], int *ultimo, int estado[]) {
  cola[*ultimo] = x;
  *ultimo += 1;
  estado[x] = NODO_EN_COLA;
}

int quitarElementoMasReciente (int cola[], int *cabeza, int estado[]) {
  int x = cola[*cabeza];
  *cabeza += 1;
  estado[x] = NODO_ALCANZADO;
  return x;
}

// Breadth-First Search para el camino de aumento
// devuelve verdadero o falso
int bfs (int fuente, int sumidero, int numeroDeNodos,
        int flujo[MAX_NODOS][MAX_NODOS], int capacidad[MAX_NODOS][MAX_NODOS],
        int predecesor[])
{
  int estado[MAX_NODOS]; // necesario para breadth-first search
  int nodoU,nodoV;
  int cabeza,ultimo;
  int cola[MAX_NODOS+2];


  // Inicializar estado de los nodos
  for (nodoU = 0; nodoU < numeroDeNodos; nodoU++) {
    estado[nodoU] = NODO_INICIALIZADO;
  }


  cabeza = ultimo = 0;
  agregarElemento(fuente, cola, &ultimo, estado);
  predecesor[fuente] = -1; // -1 como centinela, llegada.


  while (cabeza!=ultimo) { // mientras la lista no este vacia
    nodoU = quitarElementoMasReciente(cola, &cabeza, estado);
		// Buscar todos los nodos inicializados adyacentes v. Si la capacidad
  	// de u a v en la red residual es positiva,
    // agregar v a la cola.


    for (nodoV = 0; nodoV < numeroDeNodos; nodoV++) { // por cada nodo del grafo
      // Si el nodo no esta en cola y no fue alcanzado, y se puede aumentar el flujo
      if (estado[nodoV]==NODO_INICIALIZADO && capacidad[nodoU][nodoV]-flujo[nodoU][nodoV]>0) {
        agregarElemento(nodoV, cola, &ultimo, estado);
        predecesor[nodoV] = nodoU;
      }
    }

  }
  // Si llegamos al sumidero, significa que
  // existe un camino de aumento.
  return estado[sumidero]==NODO_ALCANZADO;
}

// Algoritmo Ford-Fulkerson
int flujoMaximo (int fuente, int sumidero, int numeroDeNodos,
                int capacidad[MAX_NODOS][MAX_NODOS])
{
  int i,j, nodo;
  int flujo[MAX_NODOS][MAX_NODOS];     // matriz de flujo
  int predecesor[MAX_NODOS];  // array para guardar el camino de aumento
                                 // por cada nodo el vecino

	// Inicializar flujo cero.
  int flujoMaximo = 0;
  for (i=0; i< numeroDeNodos; i++) {
    for (j=0; j< numeroDeNodos; j++) {
      flujo[i][j] = 0;
    }
  }

  // Mientras exista un camino de aumento
  // incrementar el flujo a lo largo de esta ruta
  while (bfs(fuente,sumidero,numeroDeNodos,flujo,capacidad,predecesor)) {
    int incremento = INFINITO;


    // Desde el sumidero hasta llegar a la funete siguiendo el camino de aumento
    for (nodo=sumidero; predecesor[nodo]>=0; nodo=predecesor[nodo]) {
    // Determinar la cantidad por la cual podemos incrementar el flujo
      incremento = min(incremento,capacidad[predecesor[nodo]][nodo]
                                  -flujo[predecesor[nodo]][nodo]);
    }


    // Ahora incrementar el flujo a lo largo del camino de aumento
    for (nodo=numeroDeNodos - 1; predecesor[nodo]>=0; nodo=predecesor[nodo]) {
      flujo[predecesor[nodo]][nodo] += incremento;
      flujo[nodo][predecesor[nodo]] -= incremento;
    }
    flujoMaximo += incremento;
  }
  //  Si no hay un camino de aumento. Hemos finalizado.
  return flujoMaximo;
}

void leerArchivo(char* archivo, int* fuente, int* sumidero,
                int *numeroDeNodos, int capacidad[MAX_NODOS][MAX_NODOS])
{
  int numeroDeVertices;
  int verticeA, verticeB, capacidadAB,i,j;
  FILE* input = fopen(archivo,"r");
  // leer el numero de nodos y vertices
  fscanf(input,"%d %d %d %d", numeroDeNodos,&numeroDeVertices,
                              fuente, sumidero);
  // inicializar la matriz de capacidades en 0
  for (i=0; i< *numeroDeNodos; i++) {
    for (j=0; j< *numeroDeNodos; j++) {
      capacidad[i][j] = 0;
	   }
  }
  // leer capacidad de los vertices
  for (i = 0; i < numeroDeVertices; i++) {
	   fscanf(input,"%d %d %d",&verticeA,&verticeB,&capacidadAB);
	    capacidad[verticeA][verticeB] = capacidadAB;
  }
  fclose(input);
}

int main (int argc, char* argv[]) {
  int fuente, sumidero;

  if (argc <= 1) { // si no hay argumento, error
   printf("USO: maxflw <nombre de archivo>\n");
   formatoDeArchivo();
   exit(1);
  } else {
  // char* archivo = argv[1];
  int numeroDeNodos;
  int capacidad[MAX_NODOS][MAX_NODOS]; // matriz de capacidad
  leerArchivo(argv[1], &fuente, &sumidero, &numeroDeNodos, capacidad);
  printf("Flujo maximo: %d\n",flujoMaximo(fuente, sumidero, numeroDeNodos, capacidad));
  }
  return 0;
}
