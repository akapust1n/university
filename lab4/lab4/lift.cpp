#include "lift.h"
#include <QMessageBox>

lift::lift()
{
    min_floor = 1;
    max_floor = 7;
    floor = 1;
    st = state_lift::wait;
    empty = false;
    connect(this, SIGNAL(open_doors()), &door, SLOT(open())); // двери получают сигнал открываться
    connect(this, SIGNAL(close_doors()), &door, SLOT(close())); //двери получают сигнал закрываться
    connect(this, SIGNAL(arrived()), this, SLOT(arrived_slot())); //прибываем
    connect(&door, SIGNAL(opened()), this, SLOT(doors_opened_slot())); //получаем от дверей, что они открылись
    connect(&door, SIGNAL(closed()), this, SLOT(doors_closed_slot())); //получаем от дверей, что они закрылись
}
void lift::arriv()
{
    QTime time;
    time.start();
    set_st(state_lift::minor_wait);

    for (; time.elapsed() < minor_wait_time;) {
        qApp->processEvents();
    }
    emit arrived();
}

void lift::update()
{
    if (floor == dest) { //прибываем
        arriv();
        return;
    }
    QTime time;
    time.start();
    for (; time.elapsed() < one_floor_time;) {
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
    set_st(state_lift::doors_opened);
    empty = !empty;
    if (empty == true) {
        emit show_lift();
    } else {
        set_st(state_lift::doors_closing);
        emit close_doors();
    }
}
void lift::doors_closed_slot()
{
    set_st(state_lift::wait);
    if ((!queue.isEmpty())) {
        dest = queue.first();
        queue.pop_front();
        set_st(state_lift::go);
        while (st == state_lift::go) {
            update();
        }
    } else {
        set_st(state_lift::wait); //или нет
    }
}

void lift::set_st(state_lift a)
{
    st = a;
    emit st_changed(a);
}
void lift::floor_but(int f1)
{
    queue.push_back(f1);
    if ((st == state_lift::wait) && (!queue.isEmpty())) {
        dest = queue.first();
        queue.pop_front();
        if (floor != dest) {
            set_st(state_lift::go);
            while (st == state_lift::go) {
                update();
            }
        } else {
            arriv();
        }
    }
}
void lift::lift_but(int f2)
{
    queue.push_front(f2);
    set_st(state_lift::doors_closing);
    emit hide_lift();
    //empt = full;
    emit close_doors();
}
