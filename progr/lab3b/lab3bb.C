#include <stdio.h>

//  Метод Холецкого
int Chol(double **m, double x[],int n)
{


    int i, j;


     double **L =(double **)malloc((n+1)* sizeof(double *));//  нижняя диагональная матрица
          for (i=0; i<=n; i++)
             L[i] = (double *)malloc((n+1) * sizeof(double));
    //  получение нижней диагональной матрицы
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int r = 0; r < j; r++)
                L[i][j]  += (L[i][r])*L[j][r];
           L[i][j]  = (*(*(m+i) + j))- L[i][j]/L[j][j];
        }
        for(int k = 0; k < i; k++)
            L[i][i] += L[i][k]*L[i][k];
        L[i][i] = sqrt(*(*(m+i) + i) - L[i][i]);
        L[i][n] = *(*(m+i) + n);
    }
    //  printm(L,n);

    // решение Ly=b
    for(int i = 0; i < n; i++)
    {
        if(i != 0)  //  первая строка
        for(int j = 0; j <= n-i; j++)
            L[i][n] -= L[i][j]*(*(x+j));
        *(x+i) = L[i][n]/L[i][i];
    }

    // получение транспонированной матрицы
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            L[i][j] =L[j][i];
            L[j][i] = 0;
        }
        L[i][n]= *(x+i);
    }
    // printm(L,n);

    // Решение Ltx = y
    for(int i = n-1; i>=0; i--)
    {
        if(i != n-1)  //  последняя строка
        for(int j = i+1; j<n; j++)
            L[i][n] -= L[i][j]*(*(x+j));
        *(x+i) = L[i][n]/L[i][i];
    }

   // free_mat(L,n); // освобождение памяти матрицы L
    return 0;
}

//ввод
int main(){
    int i, j, n;

    printf("Input n=");
    scanf("%d",&n);
    double x[n];
     double **L =(double **)malloc((n+1)* sizeof(double *)); // выделение памяти
          for (i=0; i<=n; i++)
             L[i] = (double *)malloc((n+1) * sizeof(double));
    //  получение нижней диагональной матрицы
     for(i=0;i<n;i++)
     {
         for(j=0;j<=n;j++)
             scanf("%lf",&L[i][j]);}
         Chol(L,x, n);
         for(int y=0;y<n;y++) printf("\n%lf",x[y]);
            //fscanf(fp,"%lf",&b[i]);



    return 0;
}
