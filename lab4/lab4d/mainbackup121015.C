#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
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
int ai=0, bi=0;
int a[55], b[55]; //хранение адресов добавленных/удаленных элементов
struct Node //описание узла списка
{
int data; //информационное поле
Node *next; //указатель на следующий элемент
};
struct Queue //описание очереди
{
int size; //счетчик размера очереди
Node *first; //указатель на начало очереди
Node *last; //указатель на конец очереди
};
void Creation(Queue *Q) //создание очереди
{
Q->first=new Node;
Q->first->next=NULL;
Q->last=Q->first;
Q->size=0;
}
bool Full(Queue *Q) //проверка очереди на пустоту
{
if (Q->first==Q->last) return true;
else return false;
}
int Top(Queue *Q) //вывод начального элемента
{ if (!Full(Q))return Q->first->next->data;
else return 0;}
void Add(Queue *Q,int value) //добавление элемента
{

Q->last->next=new Node;
Q->last=Q->last->next;
Q->last->data=value; //добавление элемента в конец
Q->last->next=NULL; //обнуление указателя на следующий элемент
Q->size++;

}
void Delete(Queue *Q) //удаление элемента
{

Q->first=Q->first->next; //смещение указателя ----------------------------------------------добавить удаление
Q->size--;

}
int Size(Queue *Q) //размер очереди
{ return Q->size; }

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
   Q->size++;
           return;
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
    Queue Q; //список
    Creation(&Q); //создаем список
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
    Add(&Q,secType);
    while(true) {
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
//            cout<<"lol1";
            Add(&Q,FTypeReq);
           // cout<<"lol2";
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
              if (Q.size==1) WasteTime+=Time;} //Если очередь освобождается, а следующий элемент приходит слишком долго
            if(secType == Top(&Q)) {
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
                    cout << "Now length of queue: " << static_cast<unsigned int>(Q.size) << endl;
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
    cout << "Numbers of 2 runs 2nd type requests: " << countSecReqs << endl;
    cout << "Idle time: " << WasteTime << endl;
    int i;
    cin >> i;
    return 0;
}
