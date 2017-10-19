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
   int i1=0;
   vector<int> uu(a.size()); // стоит подумать какой лучше размер сделать
    //ja.pop_front();

    int j=0;
   // cout<<(Max_element(ia1,ia1.size));
    result.resize(Max_element(ia1,ia1.size()));
for(int i=0;i<a1.size();)
{
    h=ja.front();

    ja.pop_front();
    i1=0;
    cout<<endl;
do
 {//cout<<"\nutut2";

 //  cout<<ia[i]<<" vs "<<ia[i1]<<endl;
  // for(i1=0;i1<a1.size();i1++) //просмотр для каждого элемента
    //if (ia[i]==ia1[i1++]) result[j]+=a[i]*a1[i1];
  // if (((ia[i+1]-ia[i])>1)&&((i+1)<ia1.size())) j++; //может работает, а может и нет
}while (a[i++]!=h);
j++;
}
cout<<"--------------\n";
for(int i=0;i<j;i++)
    cout<<result[i]<<endl;
return;
}
