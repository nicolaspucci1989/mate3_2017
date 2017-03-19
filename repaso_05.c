//Almacenar 16 numeros aleatoreos en una matriz de 4x4.
//Mostrar por pantalla la suma de los pares e impares.
//Con menu de opciones, no permitir ver resultados si no se ingresaron datos.
#include <stdio.h>
#include <stdlib.h>
#define FILAS 2
#define COLUMNAS 2
#define SALIDA 0


int menu()
{
  int opcion;
  printf("%s\n%s\n%s\n%s\n","1-Ingresar datos.",
                            "2-Ver suma par.",
                            "3-Ver suma impar",
                            "0-Salir");
  scanf("%d", &opcion);


  return opcion;
}


void ingresoDatos(int m[][COLUMNAS])
{
  int i, j;
  for(i=0; i<FILAS; i++){
    for(j=0; j<FILAS; j++){
      scanf("%d", &m[i][j]);
    }
  }
}


void imprimirMatriz(int m[][COLUMNAS])
{
  int i, j;
  for(i=0; i<FILAS; i++){
    for(j=0; j<FILAS; j++){
      printf("%d ", m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}


int verSumaPar(int m[][COLUMNAS])
{
  int i,j;
  int acum = 0;

  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      if(m[i][j]%2 == 0)
        acum = acum + m[i][j];
    }
  }
  return acum;
}


int verSumaImpar(int m[][COLUMNAS])
{
  int i,j;
  int acum = 0;

  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      if(m[i][j]%2 != 0)
        acum = acum + m[i][j];
    }
  }
  return acum;
}


int main()
{
  int matriz[FILAS][COLUMNAS];
  int opcion;
  while((opcion = menu()) != SALIDA){
    switch (opcion) {
      case 1:
        printf("Ingrese %d valores\n", FILAS*COLUMNAS);
        ingresoDatos(matriz);
        break;
      case 2:
        printf("Suma de valores pares %d\n", verSumaPar(matriz));
        break;
      case 3:
        printf("Suma de valores impares %d\n", verSumaImpar(matriz));
        break;
      default:
        puts("Opcion incorrecta");
    }
  }
  return 0;
}
