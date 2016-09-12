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
    getch();
   return 0;
}

int main()
{

    int i, j, n;
    FILE *fp=fopen("test.txt", "r");
 //создаем массив
    printf("Input n=\n");
    scanf("%d",&n);

     double **a =(double **)malloc(n* sizeof(double *)); // выделение памяти
          for (i=0; i<n; i++)
             a[i] = (double *)malloc(n * sizeof(double));

 //инициализируем

     double b[n], x[n]; //свободные члены
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
             fscanf(fp,"%lf",&a[i][j]);
            fscanf(fp,"%lf",&b[i]);
     }
     for(i=0;i<n;i++)
         printf("%lf\n",b[i]);
     for(int k=0; k < n-1; k++){
             // вычитаем по строкам
             for(int m=k+1; m < n; m++){
                 // если на диагонали элемент = 0, то поменяем местами строки
                 if(a[m][m] == 0) exchange(a, n, m, get_n_no_empty(a, n, m));

                 double koeficent=a[m][k]/a[0][k];
                 //вычисление новых коэфицентов уравнения
                 b[m] = b[m] - b[0] * koeficent;
                 for(int z=0; z <n; z++){
                     a[m][z] = a[m][k] - a[0][k] * koeficent;
                 }

             }
         }
         // ищем решения
         for(int m=n-1; m >= 0; m--){
             double sum=0;
             // идем по строке спаво налево, считая сумму корень*коэфицент, до текущего корня
             for(int i=n-1; i > m; i--){
                 sum += x[i] * a[m][i];
             }
             x[m] = (b[m] - sum)/a[m][m];
         }

         // вывод решений
         printf( "Solutions:\n");
         for(int i=0; i < n; i++)
            printf("%lf\n",x[i]);


     //сам метод


      free(a);


 return 0;
 }
