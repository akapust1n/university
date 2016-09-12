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

int input_ind_file(vector<int> &ia, vector<int>&a, list<int> &ja, vector<int> &ia1, vector<int>& a1)
{
    int d, d1;
    int h;
    ifstream f("data22.txt");
//считываем вектор
f>>d;
ia1.resize(d);
a1.resize(d);

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
    ia.resize(d1);
    a.resize(d1);

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

int input_ind(vector <int>&ia, vector <int>&a, list<int> &ja, bool matrix_kind)
{
  int d, d1;
  int h;

  cout<<"Input number of non-zero elements of array:";
  cin>>d;
  if (d<=0) return 1;
  ia.resize(d);
  a.resize(d);


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
       if (h>d) {cout<<"Error, incorrect number of line"; return 1;}
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
