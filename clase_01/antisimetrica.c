#include <stdio.h>
#include <stdlib.h>
#define COLUMNAS 3


int esAntisimetrica(int n, int rela[][COLUMNAS])
{
  int i,j;
  int anti=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(rela[i][j]==1 && rela[j][i]==1){
        anti=1;
        i=n;break;
      }
    }
  }
  return anti;
}

int main()
{
  int n=3;
  char *antisimetrica[]={"Es antisimetrica","No es antisimetrica"};
  int relacion[][COLUMNAS]={{1,0,0},
                            {0,1,0},
                            {0,0,1}};

  printf("%s\n", antisimetrica[esAntisimetrica(n,relacion)]);
  puts("Presione enter para continuar");
  getchar();
  return 0;
}
