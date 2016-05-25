#include "lift.h"

lift::lift()
{
    min_floor = 1;
    max_floor = 7;
    floor = 1;
    st = state_lift::wait;
    connect(this, SIGNAL(open_doors()), &door, SLOT(open())); // двери получают сигнал открываться
    connect(this, SIGNAL(close_doors()), &door, SLOT(close())); //двери получают сигнал закрываться
    connect(this, SIGNAL(arrived()), this, SLOT(arrived_slot())); //прибываем
    connect(&door, SIGNAL(opened()), this, SLOT(doors_opened_slot())); //получаем от дверей, что они открылись
    connect(&door, SIGNAL(closed()), this, SLOT(doors_closed_slot())); //получаем от дверей, что они закрылись
}
void lift::update()
{
    if (floor == dest) {
        set_st(state_lift::minor_wait);
        emit arrived();
        return;
    }
    QTime time;
    time.start();
    for (; time.elapsed() < 1000;) {
        qApp->processEvents();
    }
    floor += (dest - floor) / abs(dest - floor); //меняем этаж на 1
    floor_changed(floor);
}
void lift::arrived_slot()
{
    set_st(state_lift::doors_opening);
    emit open_doors();
}

void lift::doors_opened_slot()
{
}
void lift::doors_closed_slot()
{
}

void lift::set_st(state_lift a)
{
    st = a;
    emit st_changed(a);
}
