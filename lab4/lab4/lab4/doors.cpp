#include "doors.h"
#include "QTime"
#include <stats.h>
#include <QMessageBox>
doors::doors() :
    QObject()
{
}
void doors::open(){
    if(state==door_state::closed){

     QTime time;
     time.start();
     for(;time.elapsed() < time_open_door;)
     {
        qApp->processEvents();
     }
     state = door_state::opened;
     emit opened();
    }
}

void doors::close(){

    if(state==door_state::opened)
    {
    QTime time;
    time.start();
    for(;time.elapsed() < time_close_door;)
    {
       qApp->processEvents();
    }
    state = door_state::closed;
    emit closed();
    }
}


