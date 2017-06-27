#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
};

typedef struct Nodo nodo;



void inicializarNodo( nodo *n )
{
    n->dato=-1;
    n->izq=NULL;
    n->der=NULL;
}


void inicializarGrafo( nodo arbol[], int tam)
{
    int i;

    for(i=0;i<tam;i++){
        inicializarNodo(&(arbol[i]));
    }
}


void imprimirNodo( nodo n)
{
   printf("%d ",n.dato);
   n.izq==NULL?printf("NULL "):printf("%d ",n.izq->dato);
   n.der==NULL?printf("NULL "):printf("%d ",n.der->dato);
}


void imprimirArbol( nodo arbol[], int tam)
{
    int i;

    for(i=0;i<tam;i++){
        imprimirNodo(arbol[i]);
    }
}

int main()
{
    int tam=3;
    nodo n;    

    inicializarNodo(&n);
    imprimirNodo(n);

  return 0;
}
