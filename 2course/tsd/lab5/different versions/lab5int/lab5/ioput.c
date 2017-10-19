#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <algorithm>
#include <fstream>
//#include <iterator>
using namespace std;

void nice()
{
 cout<<"\n";
for(int i=0;i<80;i++) cout<<"-";
cout<<"\n";
return;
}

int check_kind(char kind[])
{
   cin>>kind;

if (!strcmp(strlwr(kind),"file")||(kind[0]=='f')){return 1;}
else
    if (!strcmp(strlwr(kind),"manual")||kind[0]=='m')
    return 2;
return 0;
}

int input_ind_file(int ia[], int a[], list<int> &ja,int ia1[],int a1[],int &asize,int &a1size)
{
    int d, d1;
    int h;
    ifstream f("data20.txt");
//считываем вектор
f>>d;
cout<<"lol";
ia1=new int[d];
a1=new int [d];
a1size=d;
for (int i=0;i<d;i++)
{
    f>>ia1[i];
    if (ia1[i]<0) { cout<<"Error"; return 1;}
}

for (int i=0;i<d;i++)
    f>>a1[i];
       //считываем матрицу
    f>>d1;
    //if (d1>d) {cout<<"Error. Size of matrix should be less then size of vector"; return 1;}
     ia=new int[d1];
    a=new int[d1];
   asize=d;
    for (int i=0;i<d1;i++)
    {
        f>>ia[i];
        //cout<<sizeof(ia);
        if (ia[i]<0) { cout<<"Error_u"; return 1;}
    }

    for (int i=0;i<d1;i++)
        f>>a[i];

    f>>d1;

   //cout<<d1<<"u";
    for(int i=0;i<d1;i++)
    {
        f>>h;
        //
        //cout<<"hm"<<h;
        if(ja.front()>h&&i!=0)
        {
            cout<<"Error";
            return 1;
        }
        ja.push_back(h);
    }



  return 0;
}

int input_ind(int ia[], int a[], list<int> &ja, bool matrix_kind,int &asize)
{
  int d, d1;
  int h;

  cout<<"Input number of non-zero elements of array:";
  cin>>d;
  if (d<0) return 1;
   ia=new int[d];
  a=new int[d];
 asize=d;


     cout<<"Input vector of number of colums(number must be positive):\n ";
  for (int i=0;i<d;i++)
  {
      cin>>ia[i];
      if (ia[i]<0) { cout<<"Error"; return 1;}
  }


  cout<<"\nEnter vector of values:\n";
  for (int i=0;i<d;i++)
      cin>>a[i];

  if (matrix_kind){ //расширение функционала, в случае если у нас всего лишь одномерный массив
  cout<<"Enter number of lines:";
  cin>>d1;
  if (d1>d)
  {cout<<"There are full-zero lines, it is error";
      return 1;
  }

  cout<<"Enter  components , which begins with the description of a new line:"<<endl;
  for(int i=0;i<d1;i++)
  {
      cin>>h;

      if(ja.front()>h&&i!=0)
      {
          cout<<"Error";
          return 1;
      }
      ja.push_back(h);
  }
  }

return 0;
}
