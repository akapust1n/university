#include "doors.h"
#include "QTime"
#include <stats.h>
doors::doors() :
    QObject()
{
    statement = state::st_closed;
    QObject::connect(this,SIGNAL(change_st(int)),this,SLOT(set_st(int)));
}

void doors::open(){
     emit set_st(state::st_opening);
     QTime time;
     time.start();
     for(;time.elapsed() < time_open_door;)
     {
        qApp->processEvents();
     }
     emit opened();
     emit set_st(state::st_opened);
}

void doors::close(){
    emit set_st(state::st_closing);
    QTime time;
    time.start();
    for(;time.elapsed() < time_close_door;)
    {
       qApp->processEvents();
    }
    closed();
    emit set_st(state::st_closed);
}

void doors::set_st(state st){
    statement = st;
}
