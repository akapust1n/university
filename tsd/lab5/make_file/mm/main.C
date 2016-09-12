#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ///создание файла
    //1%
    ofstream f("data27.txt");
    f<<"50"<<"\n";
    for(int i=0;i<49;i++)
        f<<setw(6)<<i;
    f<<" 99"<<"\n";
    for(int i=0;i<50;i++)
        f<<setw(6)<<i;

    f<<"\n5000\n";
    f<<endl;
    for(int j=0;j<50;j++)
    for(int i=0;i<100;i++)
        f<<setw(6)<<i;
    for(int j=0;j<50;j++)
    for(int i=0;i<100;i++)
        f<<setw(6)<<i;
    f<<endl;


    f<<"\n50\n";
    for(int i=0;i<50;i++)
    f<<setw(6)<<i*100;
    //f<<setw(6)<<"100";
   // f<<setw(6)<<"200";
   //f<<setw(6)<<"300";
    //f<<setw(6)<<"400";
    /*f<<setw(6)<<"500";
    f<<setw(6)<<"600";
    f<<setw(6)<<"700";
    f<<setw(6)<<"800";
    f<<setw(6)<<"900";*/
  /*  f<<setw(6)<<"1000";
    f<<setw(6)<<"1100";
    f<<setw(6)<<"1200";
    f<<setw(6)<<"1300";
    f<<setw(6)<<"1400";
    f<<setw(6)<<"1500";
    f<<setw(6)<<"1600";
    f<<setw(6)<<"1700";
    f<<setw(6)<<"1800";
    f<<setw(6)<<"1900";
    f<<setw(6)<<"2000";
    f<<setw(6)<<"2100";
    f<<setw(6)<<"2200";
    f<<setw(6)<<"2300";
    f<<setw(6)<<"2400";
    f<<setw(6)<<"2500";
    f<<setw(6)<<"2600";
    f<<setw(6)<<"2700";
    f<<setw(6)<<"2800";
    f<<setw(6)<<"2900";
    f<<setw(6)<<"3000";
    f<<setw(6)<<"3100";
    f<<setw(6)<<"3200";
    f<<setw(6)<<"3300";
    f<<setw(6)<<"3400";
    f<<setw(6)<<"3500";
    f<<setw(6)<<"3600";
    f<<setw(6)<<"3700";
    f<<setw(6)<<"3800";
    f<<setw(6)<<"3900";
    f<<setw(6)<<"4000";
    f<<setw(6)<<"4100";
    f<<setw(6)<<"4200";
    f<<setw(6)<<"4300";
    f<<setw(6)<<"4400";
    f<<setw(6)<<"4500";
    f<<setw(6)<<"4600";
    f<<setw(6)<<"4700";
    f<<setw(6)<<"4800";
    f<<setw(6)<<"4900";
    f<<setw(6)<<"5000";
    f<<setw(6)<<"5100";
    f<<setw(6)<<"5200";
    f<<setw(6)<<"5300";
    f<<setw(6)<<"5400";
    f<<setw(6)<<"5500";
    f<<setw(6)<<"5600";
    f<<setw(6)<<"5700";
    f<<setw(6)<<"5800";
    f<<setw(6)<<"5900";*/
    f.close();

    ///
    return a.exec();
}
