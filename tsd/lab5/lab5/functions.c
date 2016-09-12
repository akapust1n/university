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
    int j1;
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
    clock_t time_start=clock();
    clock_t time_start1=tick();
    for(int i=0;i<ia1.size();i++)
     ip[ia1[i]]=i+1;
    h=a.size();
    j1=-1;
    int y=ja.front();
    for(int i=0;i<h;i++)
    {
        if (i==y)
        {
            ja.pop_front();
            y=ja.front();
            j1++;
        }
      // if (ip[ia[i]]!=0)
      // {
        if(ip[j1]==0) continue;
            count1++;
        // cout<<a[i]<<" "<<a1[j1]<<" "<<ia[i]<<" "<<(ip[ia[i]]-1)<<endl;
           result[ia[i]]+=(a[i]*a1[ip[j1]-1]);
           cout<<" "<<a[i]<<" "<<a1[ip[j1]-1]<<" "<<ip[j1]<<" "<<j1<<endl;
            result1[ia[i]]=ia[i];
        //}
       // int size=ip.size();
        //for(int j=0;j<size;j++)
    }


clock_t time_end=clock();
clock_t time_end1=tick();
cout<<"Result:";
for(int i=0;i<max1;i++)
 if(result[i]!=0)   cout<<setw(5)<<result[i];
cout<<"\n       ";
for(int i=0;i<max1;i++)
   if (result[i]!=0)  cout<<setw(5)<<result1[i];
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
cout<<"Time "<<scientific<<(double(time_end-time_start))/CLOCKS_PER_SEC<<" in secunds, used clock() "<<endl;
cout<<"Time "<<scientific<<(double(time_end1-time_start1)/2900000)<<" in ticks, used tick()\n "<<endl;

return;
}
