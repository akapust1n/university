#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

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
void multiply(vector<int>ia, vector<int>a, list<int> ja,vector<int>ia1,vector <int> a1, vector<int> &result)
{
    int h;
    int max1=std::max(Max_element(ia1,ia1.size()),Max_element(ia,ia.size()))+1;
    int max_1=Max_element(ia1,ia1.size())+1;
    int max_0=Max_element(ia,ia.size())+1;
   int i1=0;
   vector<int> uu(max1); // стоит подумать какой лучше размер сделать
    //ja.pop_front();

    int j=0;
   // cout<<(Max_element(ia1,ia1.size));
    result.resize(max1);
    h=a.size();
    int j1=0;



for(int j=0;j<max_0;j++)
    {

cout<<"\n";
j1=0;
list <int> yy=ja;
// cout<<stoka<<endl;
yy.pop_front();
int stoka=yy.front();
for(int i=0;i<max1;i++) uu[i]=0;
for(int i=0;i<(h);i++) //я не знаю почему h-1, но иначе не работает -уже работает
{  if (i!=(h-1)) cout<<stoka;
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
cout<<"hail";
for(int i=0;i<max1;i++)
    cout<<uu[i];
//вычисление результата
 //по сути размер матрицы ограничен размером вектора для умножения, ПРИМЕМ ТАКОЕ ДОПУЩЕНИЕ, лол
  for(int z=0;z<a1.size();z++)
    if(ia1[z]==z)  result[j]+=uu[z]*a1[z];
    }

for(int i=0;i<max1;i++)
    cout<<result[i]<<endl;
return;
}
