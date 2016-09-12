#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <fstream>
#include <string.h>
#include <ctime>
#include <stdlib>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
enum RequestType {firstType = 1, secType = 2}; // Тип заявки.
enum NextEventType {Undef, Clear, Enter}; // Тип следующего события: очистка ОА или поступление новой заявки.
//---------------------------------------------------------------------------
// Заявка: тип.
struct Request {
    RequestType ReqType;
};

struct Node //описание узла списка
{
int data; //информационное поле
Node *next; //указатель на следующий элемент
};
int ai=0, bi=0;
Node *a[1500], *b[1500]; //хранение адресов добавленных/удаленных элементов
const int N=500; //количество элементов массив
struct Queue1
{
int data[N]; //массив данных(ну на всякий случай побольше)
int last; //указатель на начало
};
struct Queue //описание очереди СПИСОК
{
int size; //счетчик размера очереди
Node *first; //указатель на начало очереди
Node *last; //указатель на конец очереди
};
void Creation(Queue1 *Q) //создание очереди МАССИВ
{ Q->last=0; }
void Creation(Queue *Q) //создание очереди список
{

 Q->first=new Node;
b[bi++]=Q->first;
Q->first->next=NULL;
Q->last=Q->first;
Q->size=0;
}
bool Full(Queue *Q) //проверка очереди на пустоту
{
if (Q->first==Q->last) return true;
else return false;
}

int Top(Queue1 *Q) //вывод начального элемента МАССИВ
{ return Q->data[0]; }
int Size(Queue1 *Q) //размер очереди МАССИВ
{ return Q->last; }
int Size(Queue *Q) //размер очереди
{ return Q->size; }
int Top(Queue *Q) //вывод начального элемента
{ if (!Full(Q))return Q->first->next->data;
else return 0;}
void Add(Queue1 *Q, int val) //добавление элемента МАССИВ
{
Q->data[Q->last++]=val;
}
void Add(Queue *Q,int value) //добавление элемента
{

Q->last->next=new Node;

Q->last=Q->last->next;
if (bi<1499) b[bi++]=Q->last; //ну формально надо бы на Q->last->next
Q->last->data=value; //добавление элемента в конец
Q->last->next=NULL; //обнуление указателя на следующий элемент
Q->size++;

}
void Delete(Queue1 *Q) //удаление элемента МАССИВ
{
for (int i=0; i<Q->last && i<N; i++) //смещение элементов
Q->data[i]=Q->data[i+1]; Q->last--;
}
void Delete(Queue *Q) //удаление элемента
{
Node *z=Q->first;
if (ai<1499) a[ai++]=Q->first;

Q->first=Q->first->next; //смещение указателя ----------------------------------------------добавить удаление

free(z);
Q->size--;

}
void arrayRotateRight(int array[], int size) {
   int temp = array[--size];

   while ( size > 0 ) array[size--] = array[size-1];

   array[0] = temp;
 }
void Insert(Queue1 *Q, int number, int value) //вставка элемента МАССИВ //наверное, правильно
{
    int p=0;

   // cout<<Size(Q);

 //   int temp = Q->data[size];
 //  Q->data[number]=value;
//while ( size > (number) ) Q->data[size--] = Q->data[size-1];
//Q->data[Q->last++]=temp;
if (Size(Q)>3) Q->data[Q->last++]=1;
else
   {Q->data[Q->last++]=2; return;}
Q->data[3]=value;

 // cout<<Size(Q);
return ;
}

void Insert(Queue *Q, int number, int value)
{
  int p=0;
  Node *y;
  y=Q->first;

  while (p!=number)
  {
    p++;
   y=y->next;
}
  Node *z=y->next;
   y->next=new Node;

   y->next->next=z;
   y->next->data=value;

   b[bi++]=y->next;

   Q->size++;

           return;
  }


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
         cout<<"Select the stack implementation(list or array):";
         cin>>g;
     }
      while (!check_kindofstack(g));
   return strcmp(g,"array")?1:0;
}

const double EndGenerateFReq=5; // Максимальное время генерации заявки 1-го типа.
const double UseRequest=4; // Максимальное время обработки заявки 1-го или 2-го типа.
const int    MaxSReqPos=3; // Не далее этого элемента заявка второго типа вернётся в очередь.
//---------------------------------------------------------------------------
// RandTime() генерирует случайное число.
double RandTime() {
    double Val = (rand() * 1.0) / RAND_MAX;
    return Val;
}
//---------------------------------------------------------------------------
// MinTime возвращается из 2-х значений.
double MinTime(double T1, double T2) {
    return (T1 > T2) ? T2 : T1;
}
//---------------------------------------------------------------------------
// GenAddFReq() генерирует время прихода следующей заявки 1-го типа.
double GenAddFReq() {
    double Val = RandTime();
    double Time = (EndGenerateFReq ) * Val;
    return Time;
}
// GenUseRequest() генерирует время обработки заявки 2-го типа
double GenUseRequest() {
    double Val = RandTime();
    double Time = (UseRequest ) * Val ;
    return Time;
}
//---------------------------------------------------------------------------
int main() {

    srand(static_cast<unsigned int>(time(NULL)));
    list<RequestType> RequestQueue;
    RequestType STypeReq = secType;
    RequestType FTypeReq = firstType;
    RequestQueue.push_back(STypeReq);
    unsigned int CountFReqs       =   0; // Количество обработанных заявок 1-го типа для вывода статистики.
    unsigned int CountUseFReqs    =   0; // Количество обработанных заявок 1-го типа.
    unsigned int Enter2QueueFReqs =   0; // Количество заявок 1-го типа вошедших в систему.
    double WasteTime = 0;                //Время простоя аппарата
    double Time = 0.0;                   // Время, минимум между поступлением новой заявки и обработкой текущей.
    double TimeEnter= 0.0;              // Время прихода заявки.
    double TimeClearService = 0.0;      // Время освобождения ОА.
    double NextEventTime = 0.0;        // Время следующего события.
    double TotalTime = 0.0;             // Общее время моделирования.
   // list<RequestType>::iterator PredSReq   = RequestQueue.begin(); // Этот итератор указывает на заявку,
    Node *PredSReq;                                                             // перед которой надо вставить заявку 2го типа.
    double MiddleLenQueue = 0.0; // Средняя длина после каждого вычисления.
    unsigned long countSecReqs = 0; // Количество заявок 2-го типа.
    unsigned long SumOfCalcs = 0;  // Сумма всех измерений.
    NextEventType NextEvent = Undef;
    //cout<<"lol0";
    // ВЫБОР РЕАЛИЗАЦИИ
    textcolor(red);
    cprintf("ss");
    double start_time=clock();
    bool real=kindstack(); //true-list , false-array
   Queue Q; //список
    Queue1 Q1;
    if (real) //
    {
      Creation(&Q); //создаем список
        Add(&Q,secType);
    }
    else
    {
Creation(&Q1);
    Add(&Q1,secType);
    }

    while(true) {
        //cout<<"lol";
         //cout<<Size(&Q1);
        if(1000 == CountUseFReqs) break;

        // Выбираем событие.
        if(Enter == NextEvent) { //накопление
            TimeEnter = NextEventTime;
            TimeClearService = GenUseRequest();
                    //+TimeClearService-TimeEnter;
        }
        else if(Clear == NextEvent) {
            TimeEnter = GenAddFReq();
            TimeClearService = NextEventTime;
        }
        else if(Undef == NextEvent) { //первый проход
            TimeEnter = GenAddFReq();
            TimeClearService = GenUseRequest();
        }

        Time = MinTime(TimeEnter, TimeClearService);
        if(Time == TimeEnter) {

            // Следующее событие за текущим.
            TotalTime += Time;
            TimeEnter = GenAddFReq();
            TimeClearService = GenUseRequest();
            NextEventTime = MinTime(TimeEnter, TimeClearService);
            if(TimeEnter == NextEventTime) NextEvent = Enter;
            else if(TimeClearService == NextEventTime) NextEvent = Clear;

            // Добавляем заявку первого типа.
           // RequestQueue.push_back(FTypeReq);
          if (real)  Add(&Q,FTypeReq); else Add(&Q1,FTypeReq);
            CountFReqs++; // Увеличиваем счётчик заявок 1-го типа, для вывода статистики и выхода из цикла.
            Enter2QueueFReqs++;
            continue;
        }
        else if(Time == TimeClearService) {
            // Следующее событие за текущим.
            TimeEnter = GenAddFReq();
            TimeClearService = GenUseRequest();
            NextEventTime = MinTime(TimeEnter, TimeClearService);
            if(TimeEnter == NextEventTime) NextEvent = Enter;
            else if(TimeClearService == NextEventTime)
            {NextEvent = Clear;
             if (real){ if (Size(&Q)==1) WasteTime+=Time; } //Если очередь освобождается, а следующий элемент приходит слишком долго
             else {if (Size(&Q1)==1) WasteTime+=Time;} }}
          if (real ) {if(secType == Top(&Q)) { //очень плохая реализация полиморфизма
                //cout<<"SSSSSSSSSSSSSSSSS";
                // Обрабатываем заявку 2-го типа.
                TotalTime += Time;
                Delete(&Q);
                PredSReq = Q.first;
                for(int i = 0; i != MaxSReqPos; i++) PredSReq->next;
                if(MaxSReqPos >= Size(&Q)) Add(&Q,STypeReq);
                else Insert(&Q,MaxSReqPos, STypeReq);
                countSecReqs++;
            }
            else if(firstType == Top(&Q)) {
                // Обрабатываем заявку 1-го типа.
                TotalTime += Time;
                CountUseFReqs++;
                Delete(&Q);
                SumOfCalcs += static_cast<int>(Q.size);
                if((0 == CountUseFReqs % 100)) {
                    MiddleLenQueue = (SumOfCalcs * 1.0) / CountUseFReqs;
                    cout << "----------" << endl;               
                    cout << "[Count of  output requests]: " << CountUseFReqs << endl;
                    cout << "[Count of input requests  ]: " << Enter2QueueFReqs <<endl;
                    cout << "Now length of queue: " << static_cast<unsigned int>(Size(&Q)) << endl;
                    cout << "Now middle length of queue: " << MiddleLenQueue << endl;
                    cout << "Now middle time of being request in queue: "<<TotalTime/(countSecReqs+Enter2QueueFReqs)<<endl;
                    cout << "Numbers of 2 runs 2nd type requests: " << countSecReqs << endl; //количество заявко 2 типа
                }
            }
        }
    else
    {if(secType == Top(&Q1)) {
                //cout<<"SSSSSSSSSSSSSSSSS";
                // Обрабатываем заявку 2-го типа.
                TotalTime += Time;
                Delete(&Q1);
                if(MaxSReqPos >= Size(&Q1)) Add(&Q1,STypeReq);
                else Insert(&Q1,MaxSReqPos, STypeReq);

                countSecReqs++;
            }
            else if(firstType == Top(&Q1)) {
                // Обрабатываем заявку 1-го типа.
                TotalTime += Time;
                CountUseFReqs++;
                Delete(&Q1);
                SumOfCalcs += static_cast<int>(Size(&Q1));
                if((0 == CountUseFReqs % 100)) {
                    MiddleLenQueue = (SumOfCalcs * 1.0) / CountUseFReqs;
                    cout << "----------" << endl;
                    cout << "[Count of  output requests]: " << CountUseFReqs << endl;
                    cout << "[Count of input requests  ]: " << Enter2QueueFReqs <<endl;
                    cout << "Now length of queue: " << static_cast<unsigned int>(Size(&Q1)) << endl;
                    cout << "Now middle length of queue: " << MiddleLenQueue << endl;
                    cout << "Now middle time of being request in queue: "<<TotalTime/(countSecReqs+Enter2QueueFReqs)<<endl;
                    cout << "Numbers of 2 runs 2nd type requests: " << countSecReqs << endl; //количество заявко 2 типа
                }
            }
    }
    }
    cout << "\n----------" << endl << "Total modeling time: " << TotalTime << endl;
    cout << "Accuracy for input requests(calculation of output): " << (UseRequest/2*(1000+countSecReqs)/(Enter2QueueFReqs+countSecReqs)) <<" %"<<endl;
    cout << "1st type requests in: " << Enter2QueueFReqs << endl;
    cout << "1st. type requests out: " << CountUseFReqs << endl;
    cout << "Numbers of  runs 2nd type requests: " << countSecReqs << endl;
    cout << "Idle time: " << WasteTime << endl;
     double end_time=clock();
     double durationb=(end_time - start_time);
     cout<<"Real time "<<scientific<<durationb<<"  ms"<<endl;
     cout<<sizeof(Node);
 if (real) {  cout <<"Show adresses of  elements(Y/N)? ";
    char b1;
    cin>>b1;
    if (b1=='Y')
    { ofstream fout("adr.txt");
        for (int i=0;i<1000;i++)
           fout<<a[i]<<"  "<<b[i]<<endl;
        fout.close();
        cout<<"You can see adresses in file adr.txt";}}

    return 0;
}
