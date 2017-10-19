#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "Type.h"

// Вычисление самой длинной подпоследовательности X и Y
void getfunc();
void getposl(char X[],int d)
{
  int iy=0;

  for (int i=0;i<d;i++){
      iy=rand()%10+64;
  X[i]=(char) iy;
  }
  X[d]='\0';

  return;
}

int main()
{
    int d;
    printf("Input size of  sequence: ");
    scanf("%d",&d);
    char X[d+2], Y[d+2];
   printf("Randomly generated sequence\n");
   getposl(X,d);
    printf("X:\n");
 printf("%s",X);
    printf("\n Y:\n");
    getposl(Y,d);
     printf("%s",Y);

    int  Nx = strlen(X);
    int  Ny = strlen(Y);

    int Len = LSC(X, Y, Nx, Ny);

    printf("\nLength = %d\n", Len);

    getchar();
    return 0;
}
