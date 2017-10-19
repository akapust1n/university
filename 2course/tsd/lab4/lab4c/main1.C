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
//---------------------------------------------------------------------------
const double EndGenerateFReq        = 5; // Максимальное время генерации заявки 1-го типа.
const double UseRequest             = 4; // Максимальное время обработки заявки 1-го или 2-го типа.
const int    MaxSReqPos             = 3; // Не далее этого элемента заявка второго типа вернётся в очередь.
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
    double Time                   = 0.0; // Время, минимум между поступлением новой заявки и обработкой текущей.
    double TimeEnter              = 0.0; // Время прихода заявки.
    double TimeClearService       = 0.0; // Время освобождения ОА.
    double NextEventTime          = 0.0; // Время следующего события.
    double TotalTime              = 0.0; // Общее время моделирования.
    list<RequestType>::iterator PredSReq   = RequestQueue.begin(); // Этот итератор указывает на заявку,
                                                                   // перед которой надо вставить заявку 2го типа.
    double MiddleLenQueue      = 0.0; // Средняя длина после каждого вычисления.
    unsigned long CountOfCalcs =   0; // Количество вычислений.
    unsigned long countSecReqs =   0; // Количество заявок 2-го типа.
    unsigned long SumOfCalcs   =   0; // Сумма всех измерений.
    NextEventType NextEvent = Undef;
    while(true) {
        if(1000 == CountUseFReqs) break;

        // Выбираем событие.
        if(Enter == NextEvent) {
            TimeEnter = NextEventTime;
            TimeClearService = GenUseRequest();
        }
        else if(Clear == NextEvent) {
            TimeEnter = GenAddFReq();
            TimeClearService = NextEventTime;
        }
        else if(Undef == NextEvent) { //первый проход
            TimeEnter = GenAddFReq();
            TimeClearService = GenUseRequest();
        }
        //-----
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
            RequestQueue.push_back(FTypeReq);
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
            else if(TimeClearService == NextEventTime) NextEvent = Clear;

            if(secType == RequestQueue.front()) {
                // Обрабатываем заявку 2-го типа.
                TotalTime += Time;
                RequestQueue.pop_front();
                PredSReq = RequestQueue.begin();
                for(int i = 0; i != MaxSReqPos; i++) PredSReq++;
                if(MaxSReqPos >= RequestQueue.size()) RequestQueue.push_back(STypeReq);
                else RequestQueue.insert(PredSReq, STypeReq);
                countSecReqs++;
            }
            else if(firstType == RequestQueue.front()) {
                // Обрабатываем заявку 1-го типа.
                TotalTime += Time;
                CountUseFReqs++;
                RequestQueue.pop_front();
                SumOfCalcs += static_cast<int>(RequestQueue.size());
                CountOfCalcs++;
                if((0 == CountUseFReqs % 100)) {
                    MiddleLenQueue = (SumOfCalcs * 1.0) / CountOfCalcs;
                    cout << "----------" << endl;
                    cout << "[Count of requests]: " << CountUseFReqs << endl;
                    cout << "Now length of queue: " << static_cast<unsigned int>(RequestQueue.size()) << endl;
                    cout << "Now middle length of queue: " << MiddleLenQueue << endl;
                    cout << "[countSecReqs]: " << countSecReqs << endl; //количество заявко 2 типа
                }
            }
        }
    }
    cout << "----------" << endl << "Total modeling time: " << TotalTime << endl;
    cout << "1st type requests enter: " << Enter2QueueFReqs << endl;
    cout << "1st. type requests out: " << CountUseFReqs << endl;
    cout << "[countSecReqs]: " << countSecReqs << endl;
    int i;
    cin >> i;
    return 0;
}
