#include <stdio.h>
#include <stdlib.h>
#define COLUMNAS 3

int esRefelxiva(int n, int rel[][COLUMNAS])
{
  int reflexiva=0;
  int i;

  for(i=0;i<n;i++){
    if(rel[i][i]==0){
      reflexiva=1;
      break;
    }
  }
  return reflexiva;
}

int main()
{
  int n=3;
  char *reflexiva[]={"Es relfexiva","No es reflexiva"};
  int relacion[][COLUMNAS]={{1,0,0},
                            {0,1,0},
                            {0,0,1}};

  printf("%s\n", reflexiva[esRefelxiva(n,relacion)]);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
