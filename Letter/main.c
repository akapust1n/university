#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__("rdtsc": "=A"(d));

    return d;
}

using namespace std;
double end_time ;
double   durationb;
//списки
int *p;
int b[10];
  int z=0;





///РАБОТА С МАССИВОМ
void add_array(int h)
{
     if(p<(&b[0])) {cout<<"Stack is empty now";p=&b[0];}
    if (p<=(&b[9]))
    {
        *p=h;
        p=p+sizeof(b[0]);

}
            else
    {
        cout<<"\nStack is full now"<<endl;
    }

//cout<<(&p+sizeof(b[0]))<<" x \n";
    return;
}
void del_array()
{
    if (p>=(&b[0]))
    {
       // cout<<"\nLast element was deleted\n";
        p-=sizeof(b[0]);
       }
    else
      // cout<<"\nStack is empty now\n";
    return ;

}


void show_array()
{
    cout<<"\n Current stack:"<<endl;
  if (p<&b[0])
      return ;
  char *u=p;
   u-=sizeof(b[0]);
    while (u>=b[0])
    {
    cout<<u<<endl;
    u-=sizeof(b[0]);
    }
    return;
}
///РАБОТА СО СПИСКОМ
struct Node {
    int value;
    struct Node *next;
} ;

struct Nn {
    Node *p;
    struct Nn *next;

};

void push(Node **head,const int val) {
    Node *tmp =(Node *) malloc(sizeof(Node));
if (tmp == NULL) { //ну такое
        exit(-1);
    }
    tmp->next = *head;

  tmp->value=val;
    *head = tmp;
}
void push(Nn **head,Node *y) {
    Nn *tmp =(Nn *) malloc(sizeof(Nn));
if (tmp == NULL) { //ну такое
        exit(-1);
    }
    tmp->next = *head;
    tmp->p=y;
    *head = tmp;
}
template < typename T>
T* pop1(T **head) {
    T *out;
    if ((*head) == NULL) {
        exit(-1);
    }
    out = *head;
    *head = (*head)->next;
    return out;
}
template < typename T>
void pop2(T** head) {
    T *out;

    if (*head == NULL) {
        exit(-1);
    }

    out = *head;
    *head = (*head)->next;
    free(out);
    return ;
}
Node *list=0;
Nn   *ll=0;
int main()
{
    int m;
    int z=0;

    bool realization; //0-array, 1-list

    //realization=kindstack();
cout<<endl;
//работаем с массивом
//пузыркьком
      double start_time =  clock();




    for(int i=0;i<10000;i++)
    {

      add_array(21);
      del_array();

    }

             end_time = clock();
             cout<<m<<endl;
           durationb=end_time - start_time;
                 // cout<<"time"<<scientific<<durationb/10000<<" ms\n";
                 // cout<<i;
                  //if (i==9) {m=6;
           cout<<"time "<<scientific<<durationb/10000<<" ms\n";
           cout<<sizeof(Node)<<" "<<sizeof(b);
        //}while (m!=6);





    return 0;
}

