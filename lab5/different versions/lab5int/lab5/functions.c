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
int  Max_element(int ar[], int n)
{
    int max = ar[0]; //максимальный элемент в массиве чисел

    for (int i = 0; i < n; ++i)
    {
        if (ar[i] > max)
            max = ar[i];
    }

    return max;
}
void multiply(int ia[], int a[], list<int> ja, int ia1[], int a1[], int result[], int result1[], int &asize, int &asize1)
{
    int h;
    int max1=std::max(Max_element(ia1,asize1),Max_element(ia,asize))+1;
    int max_1=Max_element(ia1,asize1)+1;
    int max_0=Max_element(ia,asize)+1;
   clock_t time=0;

   vector<int> uu(max1); // стоит подумать какой лучше размер сделать
    //ja.pop_front();

    int j=0;
   // cout<<(Max_element(ia1,ia1.size));
    result=new int[max1];
    result1=new int [max1];
    h=asize+1;
    int j1=0;


for(int y=0;y<10000;y++){
   for (int h=0;h<max1;h++) result[h]=0;
    for (int h=0;h<max1;h++) result1[h]=0;

for(int j=0;j<max_0;j++)
    {

//cout<<"\n";
j1=-1;
list <int> yy=ja;
// cout<<stoka<<endl;
//yy.pop_front();
int stoka=yy.front();
for(int i=0;i<max1;i++) uu[i]=0;
for(int i=0;i<(h);i++) //я не знаю почему h-1, но иначе не работает -уже работает
{
    if (i==stoka) { // переход на следуюшую строчку
        j1++;

       // cout<<"z"<<stoka;
         yy.pop_front();
         stoka=yy.front(); //в последнем значении будет содержаться мусор, что, возможно, плохо


    }
if(ia[i]==((j%max_0))) //если столбцовый индекс определенный
 //  if(ia[i]==ia1[j%max_1])//если столбцовые индексы равны
       uu[j1]=a[i];



}
//cout<<"\n";
//for(int i=0;i<max1;i++)
//   cout<<uu[i];
//вычисление результата
 //по сути размер матрицы ограничен размером вектора для умножения, ПРИМЕМ ТАКОЕ ДОПУЩЕНИЕ, лол
int u=0;
  for(int z=0;z<asize1;z++)
    if(ia1[u]==z) {
       if (uu[z]!=0&&a1[u]!=0){
          clock_t time_start=tick();
        result[j]+=uu[z]*a1[u];
        clock_t time_end=tick();
        time+=(time_end-time_start);
        result1[j]=j;
        //cout<<"z"<<z;

      }u++;
    }
    }
}
cout<<"Result:";
for(int i=0;i<max1;i++)
    cout<<setw(4)<<result[i];
cout<<"\n       ";
for(int i=0;i<max1;i++)
    cout<<setw(4)<<result1[i];
cout<<endl;
//cout<<result1.size();
int count=0; //счетчик ненулевых резалтов
for(int i=0;i<max1;i++)  if(result[i]!=0) count++;
/*cout<<"a1.size"<<a1.size()<<endl;
cout<<"a.size"<<a.size()<<endl;
cout<<"ia1.size"<<ia1.size()<<endl;
cout<<"ia.size"<<ia.size()<<endl;
cout<<"count"<<count<<endl;
cout<<"ja.size"<<ja.size()<<endl;*/
cout<<"Memory "<<scientific<<(sizeof(int)*asize1+sizeof(int)*asize+sizeof(int)*asize1+sizeof(int)*asize+2*count*sizeof(int)+ja.size()*sizeof(int))<<" byte"<<endl;
cout<<"Time "<<scientific<<time/10000<<" ns"<<endl;
return;
}
