#include "doors.h"
#include "QTime"
//#include "QMessageBox"
doors::doors() :
    QObject()
{
    statement = state::st_closed;
    QObject::connect(this,SIGNAL(change_st(int)),this,SLOT(set_st(int)));
}

void doors::open(){
     //statement = st_opening;
     emit set_st(state::st_opening);
     QTime time;
     time.start();
     for(;time.elapsed() < 1000;)
     {
        qApp->processEvents();
     }
     emit opened();
     //QMessageBox::information(NULL,QObject::tr("Внимание!"),tr("Невозможно построить четырехугольник, т.к. слишком мало вершин."));
     //statement = st_opened;
     emit set_st(state::st_opened);
}

void doors::close(){
    //statement = st_closing;
    emit set_st(state::st_closing);
    QTime time;
    time.start();
    for(;time.elapsed() < 1000;)
    {
       qApp->processEvents();
    }
    closed();
    //statement = st_closed;
    emit set_st(state::st_closed);
}

void doors::set_st(state st){
    statement = (state)st;
}
