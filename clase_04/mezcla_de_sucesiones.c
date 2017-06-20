#include <stdio.h>
#include <stdlib.h>
// #define TAM(x) sizeof(x)/sizeof(x[0])

int main()
{
  int f[]={1,1,2,3,5};
  int p[]={2,3,5,7,11};
  int s[10];
  int i,j,k,a;

  for(i=0;i<10;i++)
    s[i]=-1;

  i=j=k=0;

  while(j<5 && i<5){
    if(f[i]<=p[j]){
      s[k]=f[i];
      k++;
      i++;
    } else {
      s[k]=p[j];
      k++;
      j++;
    }
  }

  a = (i>j)?j:i;


  for(;a<5;a++, k++){
    s[k]=p[a];
  }


  for(i=0;i<10;i++)
    printf("%d ", s[i]);


  printf("\n");
  puts("Presone enter para continuar")
  getchar();
  return 0;
}
