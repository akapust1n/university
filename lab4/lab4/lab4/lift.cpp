#include "lift.h"
#include <QMessageBox>
//void Timer
lift::lift()
{
    timer = new Timer(this);
    min_floor = 1;
    max_floor = 7;
    floor = 1;
    set_st(state_lift::wait);
    empty = false;
    connect(this, SIGNAL(arrived()), this, SLOT(arrived_slot())); //прибываем
    connect(this, SIGNAL(wait()), this, SLOT(waiting()));
    //connect(this,SIGNAL(wait_end()),this,SLOT(floor_but(int)));
    connect(this, SIGNAL(lift_button_pushed(int)), this, SLOT(lift_but(int)));
    connect(this, SIGNAL(floor_button_pushed(int)), this, SLOT(floor_but(int)));
    connect(this, SIGNAL(close_wh_hide()), this, SLOT(hide_panel()));
}

bool lift::update()
{
    if (st == state_lift::go_full or st == state_lift::go_empty) {
        if (floor == dest) { //прибываем
            // emit arrived();
            return false;
        }
        QTime time;
        time.start();
        for (; time.elapsed() < one_floor_time;) {
            qApp->processEvents();
        }
        floor += (dest - floor) / abs(dest - floor); //меняем этаж на 1
        emit floor_changed(floor);
        return true;
    }
    return false;
}
void lift::arrived_slot()
{
    if (st == state_lift::go_full or st == state_lift::go_empty  or st == state_lift::doors_closing) {
        set_st(state_lift::wait);
        emit wait();
    }
}

void lift::doors_opened_slot()
{
    if (st == state_lift::doors_opening) {
        set_st(state_lift::doors_opened);
        empty = !empty; //довозим до цели
        if (empty == true) {
            emit show_lift();
        } else {
            emit close_wh_hide();
        }
    }
}

void lift::doors_closed_slot()
{

    if ((st == state_lift::hide_panel or st == state_lift::doors_closing) and (!queue.isEmpty())) {
        if (!empty) {
            emit floor_button_pushed(0);
            return;
        }
        set_st(state_lift::go_full);
        timer->start_moving();
    }

    emit arrived();
}
void lift::waiting()
{
    if (st == state_lift::wait) {
        set_st(state_lift::doors_opening);
        QTime time;
        time.start();
        for (; time.elapsed() < minor_wait_time;) {
            qApp->processEvents();
        }
        emit open_doors();
    }
}

void lift::set_st(state_lift a)
{
    st = a;
    emit st_changed(a);
}
void lift::floor_but(int f1) //STATE GO-ARRIVE
{
    if (f1 != 0)
        queue.push_back(f1);

    if ((st == state_lift::wait or st == state_lift::doors_closing)) {
        set_st(state_lift::go_empty);
        timer->start_moving();
        emit arrived();
    };
}
void lift::hide_panel()
{
    if (st == state_lift::hide_panel or st == state_lift::doors_opened) {
        set_st(state_lift::doors_closing);
        emit close_doors();
    }
}
void lift::show_panel()
{
    if(st==state_lift::doors_opened){
        set_st(state_lift::show_panel);
       emit close_wh_hide();
    }

}

void lift::lift_but(int f2) //STATE doors_closing
{
    if (st == state_lift::doors_opened) {
        if (f2 != 0)
            queue.push_front(f2);

        set_st(state_lift::hide_panel);
        emit hide_lift();
    }
}
//Timer------------------------------------------------------------------

void Timer::start_moving()
{
    mylift->dest = mylift->queue.first();
    mylift->queue.pop_front();
    while (mylift->update()) {
    }
}
