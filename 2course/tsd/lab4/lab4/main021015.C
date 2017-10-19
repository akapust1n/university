#include <iostream>
#include <cstdlib>
using namespace std;

template <class T> const T& min (const T& a, const T& b) {
  return !(b<a)?a:b;     // or: return !comp(b,a)?a:b; for version (2)
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin); // забавный рандом
}
struct Node
{
  int val;
  Node *next;

};

void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->val = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void pop(Node **head) {
    Node* prev = NULL;

    if (head == NULL) {
        cout<<"Error"; //никогда не сработает ,по идее
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
    return ;
}
Node *list=0;

int buffer[5];
int *Border_line1=buffer;
int *Border_line4=&buffer[4];
int *Pin=Border_line1;
int *Pout=Border_line1;
//*Pout=0;
void add_el(int *Pin,int value) //добавляем элемент в массив на текущий адрес Pin
{
if ((Pin+1)>Border_line4) {
    *Pin=value;
    Pin=Border_line1;

} else
{
    *Pin=value;
    Pin++;

}
    return;
}
int del_el(int *Pout) //удаляем элемент из списка==тупо увеличивает Pout закольцовано
{
    int value=*Pout;
if ((Pout+1)>Border_line4) {
    Pout=Border_line1;
} else
    Pout++;
    return  value;
}

int main()
{
    srand(0);
    int sum1=0;
    double tz=fRand(0,5),toa=fRand(0,4),t, OA_time=0,val=2;
    t=min(tz,toa);
    for(int i=0;i<10;i++){
    if (t==tz) //пришла заявка
    { add_el(Pin,val);
        if (OA_time<=0) {
           val=*Pout;
            del_el(Pout);
            OA_time+=fRand(0,4);
        }
      }
        else
        {
        val=*Pout;
         del_el(Pout);
        }
    cout<<val;
    }
}
    return 0;
}
