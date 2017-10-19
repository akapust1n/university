#include <stdio.h>
#include <string.h>
#include "Type.h"
typedef struct  {
char tag[11];
 element_t kids[35];
int kids_count;
} element_t ;
// Вычисление длины самой длинной последовательности
int LSC_Length(char *X, char *Y, int N, int M, char B[][M+1])
{
    int  C[N+1][M+1];  // Матрица для расчета длины самой длинной
                       // общей подпоследовательности X и Y

    for (int I = 0; I <= N; I++)
        C[I][0] = 0;
    for (int I = 0; I <= M; I++)
        C[0][I] = 0;
    for (int I = 1; I <= N; I++)
       for (int J = 1; J <= M; J++)
          if (X[I-1] == Y[J-1])
          {
                C[I][J] = C[I-1][J-1] + 1;
                B[I][J] = '\\';
          }
          else
            if (C[I-1][J] >= C[I][J-1])
            {
                C[I][J] = C[I-1][J];
                B[I][J] = '|';
            }
            else
            {
                C[I][J] = C[I][J-1];
                B[I][J] = '-';
            }

    return C[N][M];
}

// Построение самой длинной последовательности
int Print_LSB(int M, char B[][M+1], char *X, int I, int J)
{
    if (I == 0 || J == 0)
        return 0;
    if (B[I][J] == '\\')
    {
        Print_LSB(M, B, X, I-1, J-1);
        printf("%c ", X[I-1]);
    }
    else if (B[I][J] == '|')
    {
        Print_LSB(M, B, X, I-1, J);
    }
    else
    {
        Print_LSB(M, B, X, I, J-1);
    }
    return 0;
}

// Вычисление самой длинной подпоследовательности X и Y
int LSC(char *X, char *Y, int N, int M)
{
    char B[N+1][M+1];  // Массив для вычисления самой длинной
                       // подпоследовательности X и Y

    int Length = LSC_Length(X, Y, N, M, B);

    printf("\nLCS: ");
    Print_LSB(M, B, X, N, M);

    return Length;
}
