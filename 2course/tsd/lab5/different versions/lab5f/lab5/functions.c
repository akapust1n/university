#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;
unsigned long long tick()
{ union ticks
  { unsigned long long tx;
    struct dblword { long tl,th; } dw; // little endian
  } t;
  asm("rdtsc\n": "=a"(t.dw.tl),"=d"(t.dw.th));
  return t.tx;
}
int  Max_element(vector<int> ar, int n)
{
    int max = ar[0]; //максимальный элемент в массиве чисел

    for (int i = 0; i < n; ++i)
    {
        if (ar[i] > max)
            max = ar[i];
    }

    return max;
}
void multiply(vector<int>ia, vector<int>a, list<int> ja,vector<int>ia1,vector <int> a1, vector<int> &result,vector <int>&result1)
{
    int h;
    int count1=0;
    int max1=std::max(Max_element(ia1,ia1.size()),Max_element(ia,ia.size()))+1;
    int max_1=Max_element(ia1,ia1.size())+1;
    int max_0=Max_element(ia,ia.size())+1;
   clock_t time=0;

   vector<int> uu(max1); // стоит подумать какой лучше размер сделать
    //ja.pop_front();

    int j=0;
   // cout<<(Max_element(ia1,ia1.size));
    result.resize(max1);
    result1.resize(max1);
    vector<int> ip(max1);
    //заполнение айп
    for(int i=0;i<ia1.size();i++)
     ip[ia1[i]]=i;
    h=a.size()+1;
    int j1=0;


//for(int y=0;y<10000;y++){
  // for (int h=0;h<result.size();h++) result[h]=0;
   // for (int h=0;h<result1.size();h++) result1[h]=0;
   list <int> yy;
  clock_t time_start=clock();
  clock_t time_start1=tick();
for(int j=0;j<max_0;j++)
    {
h=a.size()+1;
//cout<<"\n";
j1=-1;
yy=ja;
// cout<<stoka<<endl;
//yy.pop_front();
int stoka=yy.front();

//for(int i=0;i<max1;i++) uu[i]=0; ///апгреййд
for(int i=0;i<(h);i++) //я не знаю почему h-1, но иначе не работает -уже работает
{
    if (i==stoka) { // переход на следуюшую строчку
        j1++;
       // cout<<"z"<<stoka;
         yy.pop_front();
         stoka=yy.front(); //в последнем значении будет содержаться мусор, что, возможно, плохо
    }
    if (ip[j1]==0) continue; // UPGRADE своеобразный
if(ia[i]==((j%max_0))) //если столбцовый индекс определенный
 //  if(ia[i]==ia1[j%max_1])//если столбцовые индексы равны
       uu[j1]=a[i];
        a.erase(a.begin()+i);
        ia.erase(ia.begin()+i); //ЭКСПЕРИМЕНТ
}
//cout<<"\n";а
//for(int i=0;i<max1;i++)
//   cout<<uu[i];
//вычисление результата
 //по сути размер матрицы ограничен размером вектора для умножения, ПРИМЕМ ТАКОЕ ДОПУЩЕНИЕ, лол
int u=0;
 //cout<<"a1size"<<a1.size();
  for(int z=0;z<a1.size();z++)
    if(ia1[u]==z) {
       if (uu[z]!=0&&a1[u]!=0){//
           count1++;
        result[j]+=uu[z]*a1[u];
        result1[j]=j;
        //cout<<"z"<<z;

      } uu[z]=0;u++; // возможно, сюда стоит добавить обнуление, что упростит алгоритм -добавлено
    }
    }
//}

clock_t time_end=clock();
clock_t time_end1=tick();
cout<<"Result:";
for(int i=0;i<max1;i++)
 if(result[i]!=0)   cout<<setw(4)<<result[i];
cout<<"\n       ";
for(int i=0;i<max1;i++)
   if (result[i]!=0)  cout<<setw(4)<<result1[i];
cout<<endl;
//cout<<result1.size();
int count=0; //счетчик ненулевых резалтов
for(int i=0;i<result.size();i++)  if(result[i]!=0) count++;
/*cout<<"a1.size"<<a1.size()<<endl;
cout<<"a.size"<<a.size()<<endl;
cout<<"ia1.size"<<ia1.size()<<endl;
cout<<"ia.size"<<ia.size()<<endl;
cout<<"count"<<count<<endl;
cout<<"ja.size"<<ja.size()<<endl;*/
cout<<"Iterations: "<<count1<<endl;
cout<<"Memory "<<scientific<<(sizeof(int)*ip.size()+sizeof(int)*a1.size()+sizeof(int)*a.size()+sizeof(int)*ia1.size()+sizeof(int)*ia.size()+2*count*sizeof(int)+ja.size()*sizeof(int))<<" byte"<<endl;
cout<<"Time "<<scientific<<(double(time_end-time_start))/CLOCKS_PER_SEC<<" in secunds\n "<<endl;
cout<<"Time "<<scientific<<(double(time_end1-time_start1))/CLOCKS_PER_SEC<<" in nanosecunds\n "<<endl;

return;
}
