#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>

using namespace std;

double RandD(double l, double r);//функция вещественного рандома
int RandI(int);//функция целочисленного рандома
void OA(int &ochered,int &z1_in,int &z1_out,double &t1,double &t2,double &AT,double &sr_izm,double &sr_summ, int &summ); //обслуживающий аппарат
int main()
{
    srand(time(NULL));
    setlocale (LC_ALL,"Russian");

    int summa_zayavok_1_tipa=0, ochered=0, z1_in=0,z1_out=0,n2=0,count=0;//z1_in(z1_out) - количество вошедших (и вышедших) заявок 1-го типа,n2 - место в очереди заявки 2 типа
    double t1=RandD(0,5),t2=RandD(0,4), all_times=0, sr_izm=0, sr_summ=0,z2_time=0;//sr_summ и sr_izm - это сумма очередей и количество изменений очереди(для подсчета ср.длины)

    z2_time=RandD(0,4);
    n2=RandI(5);
    all_times+=z2_time;
    sr_summ++;
    count++;
    while (summa_zayavok_1_tipa!=1000)
    {
        if(n2==-10)
            n2=((ochered>0)&&(ochered<4))?rand()%(5-ochered) +ochered:RandI(5);//выявления местаположения заявки второго типа
        else n2--;
        if(n2>0)
        {
            OA(ochered, z1_in, z1_out, t1, t2, all_times,sr_izm,sr_summ,summa_zayavok_1_tipa);
            sr_izm++;
            sr_summ+=ochered;
        }
        else
        {
            z2_time=RandD(0,4);
            all_times+=z2_time;
            count++;
            n2=-10;
        }
        if (((summa_zayavok_1_tipa%100)==0)&&(summa_zayavok_1_tipa!=0))
        {
            cout << "processed: " << summa_zayavok_1_tipa << " заявок" <<endl;
            cout << "the average length of the queue: " << sr_summ/sr_izm <<endl;
        }
    }
    cout << "Общее время моделирования: " << all_times <<endl;
    cout << "Количество вошедших заявок 1-го типа:" << z1_in<< endl;
    cout << "Количество вышедших заявок 1-го типа:" << z1_out << endl;
    cout << count<<endl;

    return 0;
}


double RandD(double l, double r){
  int l_ = l * 10 * 10;
  int r_ = r * 10 * 10;
  return static_cast<double>(rand() % (r_ - l_) + l_) / 100;
}
int RandI(int num_int)
{
    return rand() % num_int+1;
}
void OA(int &ochered,int &z1_in,int &z1_out,double &t1,double &t2,double &AT,double &sr_izm,double &sr_summ,int &summ)
{
    t1=RandD(0,5);
    t2=RandD(0,4);
    if (t1<t2)
    {
        ochered++;
        z1_in++;
    } else
            {
                ochered--;
                AT+=t2;
                z1_out++;
                summ++;
    }

}
