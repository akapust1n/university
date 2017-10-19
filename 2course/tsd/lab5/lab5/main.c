#include <iostream>
#include <windows.h>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;
extern int input_ind(vector <int>&ia, vector <int>&a, list<int> &ja, bool matrix_kind);
extern bool check_kind(char kind[]);
extern void nice();
extern int input_ind_file(vector<int>&ia,vector<int>&a, list<int> &ja,vector<int>& ia1,vector<int>&a1);
extern void multiply(vector<int>ia, vector<int>a, list<int> ja,vector<int>ia1,vector <int> a1, vector<int> &result,vector <int>&result1);
//extern void stand_matr(vector<int>ia, vector<int>a, list<int> ja,vector<vector<int>> &a1);
extern unsigned long long tick(void);

extern int  Max_element(vector<int>  ar, int n);


int main()
{
    int kd=0;
    char kind[20];
    vector<int>ia; //первая матрица
    vector<int> a;
    list<int> ja;
    vector<int>ia1;
    vector<int>a1;//вектор для умножения
   vector<int>result; //вектор результата
    vector<int>result1;

    cout<<"Multiplication of vector-line and matrix"<<endl;

    do {
    cout<<"Input matrix manual or from file?(file/manual):";
    kd=check_kind(kind);
    }
    while (!kd);

   switch (kd)
  {
   case 1:{

       input_ind_file(ia, a, ja,ia1,a1);
       break;
   }
   case 2:{
    bool matrix_kind=0; //то бишь сначала у нас полноценная матрица-уже нет

    cout<<"\tInput vector for multiply"<<endl;
    while ( input_ind(ia1,a1,ja,matrix_kind))
    {
    cout<<"\nRepeat input"<<endl;
     nice();
    };


    nice();
     matrix_kind=1;
    cout<<"\tInput matrix"<<endl;
    while ( input_ind(ia,a,ja,matrix_kind))
    {
    cout<<"\nRepeat input"<<endl;
     nice();
    };
    break;
    }
   }
   multiply(ia, a,  ja,ia1, a1,result, result1);

  // double start_time=clock();
   //работаем с обычной матрицей
  int size=Max_element(ia,ia.size())+1;
  int size1=Max_element(ia1,ia1.size())+1;
  int size_n=std::max(Max_element(ia1,ia1.size()),Max_element(ia,ia.size()))+1;

vector<vector<int> > a_normal(size_n, std::vector<int>(size_n)); // возможно, стоит поменять размеры местами
//int a_normal[size_n][size];
vector <int> a1_normal(size_n);
int count2=0;
for(int j=0;j<size_n;j++)
for(int i=0;i<size;i++)
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

for(int i=0;i<(a.size());i++) //если что-то не работает, поменять на a.size()+1
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
if(size1<15){
cout<<"\n\nVector in normal form";
for(int i=0;i<size1;i++)
    cout<<setw(4)<<a1_normal[i];
cout<<"\nMatrix in normal form";
for(int j=0;j<size_n;j++)
{cout<<endl;

for(int i=0;i<size;i++)//если не работает ,поставить size_n
   cout<<setw(4)<<a_normal[j][i];
}
}
clock_t time1=0;
vector<int> out(size_n);
clock_t time_start=clock();
//for(int y=0;y<10000;y++){
clock_t time_start1=tick();



// выходной вектор
   // умножение элементов матрицы на вектор
   for (int ix = 0; ix < size_n; ix++)
   {
       out[ix] = 0;

       for (int jx = 0; jx < size; jx++) //если не работает, поставит size
         { // clock_t time3=tick();
           count2++;out[ix] += a_normal[jx][ix] * a1_normal[jx];
           //clock_t time4=tick();
          // time1+=(time4-time3);
       ;

   }}
//}
clock_t time_end1=tick();
clock_t time_end=clock();
//clock_t time2=tick();
  // double end_time=clock();
 if(size1<15){ cout<<"\nResult of multiply in normal form:";
   for(int i=0;i<size_n;i++)
       cout<<setw(4)<<out[i];}
cout<<endl;
cout<<"Iterations: "<<count2<<endl;
   cout<<"Memory: "<<(sizeof(int)*a1_normal.size()+sizeof(int)*size_n*size_n+sizeof(int)*out.size())<<" bytes"<<endl;
   cout<<"Time "<<(double(time_end-time_start))/CLOCKS_PER_SEC<<" in secunds, used clock()"<<endl;
   cout<<"Time "<<scientific<<(double(time_end1-time_start1)/2900000)<<" in ticks, used tick()\n "<<endl;

return 0;
}
