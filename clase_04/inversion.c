#include <stdio.h>
#include <stdlib.h>


int main()
{
  float inversion, tasa=.3;
  int anios, i;

  printf("%s\n", "Ingrese monto de inversion.");
  scanf("%f", &inversion);
  fflush(stdin);

  printf("%s\n", "Ingrese cantidad de anos.");
  scanf("%d", &anios);
  fflush(stdin);


  for(i=0;i<anios;i++){
    inversion+=inversion*tasa;
    printf("Anio %d, Cantidad acumulada %-5.2f\n", i+1, inversion);
  }

  puts("Presione enter para continuar");
  getchar();
  return 0;
}
