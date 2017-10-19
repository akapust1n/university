#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
//списки
char *p;
char b[11][20];
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
   cout<<"\nSelect the function works with a stack:"<<endl;
   cout<<"1)Add element"<<endl;
   cout<<"2)Delete element"<<endl;
   cout<<"3)Show current stack"<<endl;
   cout<<"4)Show words in reverse order of the stack"<<endl;
if (realisation) cout<<"5)Show adresses of free items\n";
if (realisation)   cout<<"6)Exit\n>>";
if (!realisation)   cout<<"5)Exit\n>>";
   cin>>m;

    return;
}
///РАБОТА С МАССИВОМ
void add_array()
{
     if(p<b[0]) {cout<<"Stack is empty now";p=b[0];}
    if (p<=(b[9]))
    { cout<<"\nInput element: ";
        scanf("%s",p);
        p=p+sizeof(b[0]);
        cout<<"\nElement was successfully added\n";
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
        cout<<"\nLast element was deleted\n";
        p-=sizeof(b[0]);
       }
    else
       cout<<"\nStack is empty now\n";
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

void push(Node **head) {
    Node *tmp =(Node *) malloc(sizeof(Node));
if (tmp == NULL) { //ну такое
        exit(-1);
    }
    tmp->next = *head;
    cout<<"\nInput element:";
    cin>>tmp->value;
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
    if(!realization)
    {
        do
   {
       menu(m,realization);
       switch (m)
       {
       case 1:
       { add_array();
           break;
          }
      case 2:
       {
        del_array();
        break;
       }
      case 3:{
           show_array();
           break;
       }
      case 4:{
          char *u=p;
          while (u>b[0]) u-=sizeof(b[0]);
          cout<<"\n Words:\n";
          while (u<p)
          {cout<<u<<endl;
              u+=sizeof(b[0]);
          }
          break;
       }
    }
    }while(m!=5);;
    }
    else
    {
        do
        { ///работа со списком
            menu(m,realization);
            switch(m){
            case 1:{
                if(z<10){
                    push(&list);
                    z++;
                    if (osv){ pop2(&ll); osv--;}//удаляем освобожденный адрес, если он был
                   // osv--; // не просили сделать второй стек, поэтому реализация некрасивая
                    cout<<"\nElement was succesfuly added"<<endl;
                }
                else
                    cout<<"Stack is full now";
                break;
            }
            case 2:{
                 if (z>0) {
                     push(&ll,list); osv++;
                     pop2(&list); z--;
                     cout<<"\nElement was removed from the top\n";
            } else
                     cout<<"\n Stack is empty now"<<endl;
            break;
            }
            case 3:{
                cout<<"\nCurrent stack:\n";
                Node *uu=list;
                while (uu!=NULL){

                cout<<uu->value<<"  "<<uu<<endl;
                pop1(&uu);
            }
                break;
            }
            case 4:{
                char y[10][20];
                int m=z;
                Node *uu=list;
                 cout<<"\n Words:\n";
                while (m--){
                    strcpy(y[m],uu->value);
                    pop1(&uu);
                }
                    for(m=0;m<z;m++)
                        cout<<y[m]<<endl;
                    break;
                }
            case 5:{
                cout<<"\nNow free memory"<<endl;
                Nn *uu=ll;
                while (uu!=NULL){
                cout<<uu->p<<"  "<<endl;
                pop1(&uu);
            }
            };
            }
        }while (m!=6);
    }
    return 0;
}
