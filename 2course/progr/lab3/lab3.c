#include <stdio.h>
#include <stdlib.h>

void exchange(double **mas, int razmer,int from, int to){
    for(int i=0; i < razmer; i++){
        mas[from][i] = mas[from][i] + mas[to][i];
        mas[to][i] = mas[from][i] - mas[to][i];
        mas[from][i] = mas[from][i] - mas[to][i];
    }
}

// определяем ближайшую строку с не 0 диоганалью вниз
int get_n_no_empty(double **a, int razmer, int begin){
    for(int i=begin+1; i < razmer; i++){
        if(a[i][i] != 0){
            return i;
        }
    }

    printf("Error");

   exit(-1);
}
int main()
{

    int i, j, n;
 //FILE *fp=fopen("test.txt", "r");
 //создаем массив
    printf("Input n=");
    scanf("%d",&n);

     double **a =(double **)malloc((n+1)* sizeof(double *)); // выделение памяти
          for (i=0; i<=n; i++)
             a[i] = (double *)malloc((n+1) * sizeof(double));

 //инициализируем

     double  x[n]; //свободные члены
     for(i=0;i<n;i++)
     {
         for(j=0;j<=n;j++)
             scanf("%lf",&a[i][j]);
            //fscanf(fp,"%lf",&b[i]);
     }


     double tmp;
     for (i=0; i<n; i++)
          {
            tmp=a[i][i];
              for (j=n;j>=i;j--)
                  a[i][j]/=tmp;
                for (j=i+1;j<n;j++)
               {
                    if(a[j][j] == 0) exchange(a, n, j, get_n_no_empty(a, n, j));
                  tmp=a[j][i];
                    for (int k=n;k>=i;k--)
                  a[j][k]-=tmp*a[i][k];
               }
           }
         // ищем решения
     x[n-1] = a[n-1][n];
          for (i=n-2; i>=0; i--)
            {
                x[i] = a[i][n];
                for (j=i+1;j<n;j++) x[i]-=a[i][j]*x[j];
            }

         // вывод решений
          //освобождаем память


         for (int i = 0; i <=n; i++)
          free(a[i]);
          free(a);

         printf( "Solutions:\n");

         for(int i=0; i < n; i++)
            printf("%lf\n",x[i]);
//free(a[0]);

 return 0;
 }
