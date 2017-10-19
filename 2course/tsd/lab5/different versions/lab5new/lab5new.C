#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

int check_kind(char kind[])
{
   cin>>kind;

if (!strcmp(strlwr(kind),"file")||(kind[0]=='f')){return 1;}
else
    if (!strcmp(strlwr(kind),"manual")||kind[0]=='m')
    return 2;
return 0;
}

int input_file(vector<int> &ia, vector<int>& a, list<int> &ja,vector<int>) //true-матрица, иначе- вектор
{
    int d;
    ifstream f("data.txt");
    f>>d;
    ia.resize(d);
    a.resize(d);
    if (d<=0) return 1; //некорректное коилчество элементов вектора
    for(int i=0;i<d;i++) //вводим вектор
    {
      f>>ia[i];
      if(ia[i]<0) return 2; //отрицательный номер столбца
    }
    for(int i=0;i<d;i++)
    {
      f>>a[i];
    }
   if(kind)
   {
       ind d1;
       f>>d1;
       if(d1>d) return 3; //zero-lines
       int h;
       for(int i=0;i<d1;i++)
       {
           f>>h;
           if(h>d) return 4; //incorrect number of line
           ja.push_back(h);
       }
   }
    return 0;
}

int main()
{
    int kd;
    char kind[20];
    vector<int>ia; //первая матрица
    vector<int> a;
    list<int> ja;
    vector<int>ia1;
    vector<int>a1;//вектор для умножения
   vector<int>result; //вектор результата
    vector<int>result1;

    //input
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
    return 0;
}
