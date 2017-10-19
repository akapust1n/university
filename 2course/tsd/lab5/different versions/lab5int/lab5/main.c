#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;
extern int input_ind(int ia[], int a[], list<int> &ja, bool matrix_kind,int &asize);
extern bool check_kind(char kind[]);
extern void nice();
extern int input_ind_file(int ia[],int a[], list<int> &ja,int ia1[],int a1[],int &asize,int &asize1);
extern void multiply(int ia[], int a[], list<int> ja,int ia1[],int a1[],int result[],int result1[],int &asize,int &a1size);
//extern void stand_matr(vector<int>ia, vector<int>a, list<int> ja,vector<vector<int>> &a1);
extern unsigned long long tick(void);

extern int  Max_element(int ar[], int n);



int main()
{
    int kd=0;
    int asize;
    int asize1;
    char kind[20];
    int *ia; //первая матрица
    int * a;
    list<int> ja;
    int* ia1;
    int *a1;//вектор для умножения
   int* result; //вектор результата
    int *result1;
    cout<<"Multiplication of vector-line and matrix"<<endl;
    do {
    cout<<"Input matrix manual or from file?(file/manual):";
    kd=check_kind(kind);
    }
    while (!kd);

   switch (kd)
  {
   case 1:{

       input_ind_file(ia, a, ja,ia1,a1,asize,asize1);
       break;
   }
   case 2:{
    bool matrix_kind=0; //то бишь сначала у нас полноценная матрица-уже нет

    cout<<"\tInput vector for multiply"<<endl;
    while ( input_ind(ia1,a1,ja,matrix_kind,asize1))
    {
    cout<<"\nRepeat input"<<endl;
     nice();
    };


    nice();
     matrix_kind=1;
    cout<<"\tInput matrix"<<endl;
    while ( input_ind(ia,a,ja,matrix_kind,asize))
    {
    cout<<"\nRepeat input"<<endl;
     nice();
    };
    break;
    }
   }
   multiply(ia, a,  ja,ia1, a1,result, result1,asize,asize1);

  // double start_time=clock();
   //работаем с обычной матрицей
  int size=Max_element(ia,asize)+1;
  int size1=Max_element(ia1,asize1)+1;
  int size_n=Max_element(ia1,asize1)+1;
  int a_normal[size_n][size];

int a1_normal[size_n];
for(int j=0;j<size_n;j++)
for(int i=0;i<size_n;i++)
    a_normal[i][j]=0;
//художественно списываем из function кусок
int j1=0;
for(int j=0;j<size_n;j++)
{

//cout<<"\n";
j1=-1;
list <int> yy=ja;
// cout<<stoka<<endl;
//yy.pop_front();
int stoka=yy.front();

for(int i=0;i<(asize);i++) //если что-то не работает, поменять на a.size()+1
{
if (i==stoka) {
    j1++;

     yy.pop_front();
        stoka=yy.front(); //в последнем значении будет содержаться мусор, что, возможно, плохо
}

if(ia[i]==((j%size_n))) //если столбцовый индекс определенный
  { a_normal[j1][j]=a[i];
}
}
}
//переводим вектор в массив
for(int i=0;i<size_n;i++)
{
 a1_normal[i]=0;
}
int u=0;
for(int i=0;i<size1;i++)
{
  if(ia1[u]==i) {a1_normal[i]=a1[u]; u++;};
}
cout<<"\n\nVector in normal form";
for(int i=0;i<size1;i++)
    cout<<setw(4)<<a1_normal[i];
cout<<"\nMatrix in normal form";
for(int j=0;j<size_n;j++)
{cout<<endl;

for(int i=0;i<size_n;i++)
   cout<<setw(4)<<a_normal[j][i];
}
clock_t time1=0;
int out[size_n];
for(int y=0;y<10000;y++){




// выходной вектор
   // умножение элементов матрицы на вектор
   for (int ix = 0; ix < size_n; ix++)
   {
       out[ix] = 0;

       for (int jx = 0; jx < size1; jx++)
         {clock_t time3=tick();  out[ix] += a_normal[jx][ix] * a1_normal[jx];
       clock_t time4=tick();
       time1+=(time4-time3);}
   }
}
//clock_t time2=tick();
  // double end_time=clock();
   cout<<"\nResult of multiply in normal form:";
   for(int i=0;i<size_n;i++)
       cout<<setw(4)<<out[i];
cout<<endl;
   cout<<"Memory: "<<(sizeof(int)*size_n+sizeof(int)*size*size_n+sizeof(int)*size_n)<<" bytes"<<endl;
   cout<<"Time "<<time1/10000<<" ns";
return 0;
}
