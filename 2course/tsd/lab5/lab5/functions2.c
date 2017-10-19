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
   int i1=0;
   vector<int> uu(max1); // стоит подумать какой лучше размер сделать
    //ja.pop_front();

    int j=0;
   // cout<<(Max_element(ia1,ia1.size));
    result.resize(max1);
    h=a.size();
for(int j=0;j<h;j++)
    {
for(int i=0;i<h;i++)
{
if(ia[i]==j)
    uu[j]+=a[i]; //считаем тестового сумму всех строчек
}
    }
for(int i=0;i<max1;i++)
    cout<<uu[i]<<endl;
return;
}
