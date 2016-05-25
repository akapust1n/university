#include "doors.h"
#include "QTime"
#include <stats.h>
doors::doors() :
    QObject()
{
}

void doors::open(){
     QTime time;
     time.start();
     for(;time.elapsed() < time_open_door;)
     {
        qApp->processEvents();
     }
     emit opened();
}

void doors::close(){
    QTime time;
    time.start();
    for(;time.elapsed() < time_close_door;)
    {
       qApp->processEvents();
    }
    emit closed();
}


