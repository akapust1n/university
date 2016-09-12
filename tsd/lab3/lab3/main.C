#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
FILE* fp=fopen("test1.txt","r");
double end_time ;
double   durationb;
//списки
char *p;
char b[10][20];
  int z=0;

bool check_kindofstack(char g[])
{
 if (!strcmp(g,"list") ||(!strcmp(g,"array")))
     return 1;
  else
     return 0;
}

bool  kindstack()
{
    char g[20];
    do
     {
        cout<<"Max size of stack is 10"<<endl;
         cout<<"Select the stack implementation(list or array):";
         cin>>g;
     }
      while (!check_kindofstack(g));
   return strcmp(g,"array")?1:0;
}

void menu(int &m, bool realisation)
{
    /// ИНТЕРФЕЙС
 //  cout<<"\nSelect the function works with a stack:"<<endl;
 //  cout<<"1)Add element"<<endl;
  // cout<<"2)Delete element"<<endl;
 //  cout<<"3)Show current stack"<<endl;
 //  cout<<"4)Show words in reverse order of the stack"<<endl;
//if (realisation) cout<<"5)Show adresses of free items\n";
//if (realisation)   cout<<"6)Exit\n>>";
//if (!realisation)   cout<<"5)Exit\n>>";
   fscanf(fp,"%d",&m);
 printf("%d lol\n",m);
    return;
}
///РАБОТА С МАССИВОМ
void add_array(char h[])
{
     if(p<b[0]) {cout<<"Stack is empty now";p=b[0];}
    if (p<=(b[9]))
    {
        strcpy(p,h);
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
    if (p>=b[0])
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
  if (p<b[0])
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
    char value[20];
    struct Node *next;
} ;

struct Nn {
    Node *p;
    struct Nn *next;

};

void push(Node **head,const char val[]) {
    Node *tmp =(Node *) malloc(sizeof(Node));
if (tmp == NULL) { //ну такое
        exit(-1);
    }
    tmp->next = *head;

  strcpy(tmp->value,val);
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
    int osv=0; // счетчик освобожденный адресов
    bool realization; //0-array, 1-list

    realization=kindstack();
cout<<endl;
//работаем с массивом
//пузыркьком
      double start_time =  clock();




    for(int i=0;i<10000;i++)
    {

      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      add_array( "21");
      del_array();
      del_array();
      del_array();
      del_array();
      del_array();
      del_array();
      del_array();
      del_array();
      del_array();
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
