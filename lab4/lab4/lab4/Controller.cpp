#include <Controller.h>
#include <doors.h>
Controller::Controller()
{
    connect(&lft, SIGNAL(st_changed(state_lift)), this, SLOT(change_lift_st(state_lift)));
    connect(&lft, SIGNAL(show_lift()), &control_panel, SLOT(show()));
    connect(&lft, SIGNAL(hide_lift()), &control_panel, SLOT(hide()));

    connect(&lft, SIGNAL(floor_changed(int)), this, SLOT(floor_ch_slot(int)));
    connect(this, SIGNAL(floor_button_pushed(int)), &lft, SLOT(floor_but(int)));
    connect(this, SIGNAL(lift_button_pushed(int)), &lft, SLOT(lift_but(int)));


    connect(&control_panel,SIGNAL(hide_el()),this,SLOT(hide_slot()));
    connect(&control_panel,SIGNAL(hide_el()),&lft,SLOT(hide_panel()));
    connect(&control_panel,SIGNAL(show_el()),this,SLOT(show_slot()));
    connect(&control_panel,SIGNAL(show_el()),&lft,SLOT(show_panel());
    //connect(this,SIGNAL(hide()),&lft,);
    //connect(&control_panel,SIGNAL(hide_el2()),&lft,SLOT(hide_panel()));

    connect(&door, SIGNAL(opened()), &lft, SLOT(doors_opened_slot())); //получаем от дверей, что они открылись
    connect(&door, SIGNAL(closed()), &lft, SLOT(doors_closed_slot())); //получаем от дверей, что они закрылись
    //connect(&door, SIGNAL(closed()), &lft, SLOT
    connect(&lft, SIGNAL(open_doors()), &door, SLOT(open())); // двери получают сигнал открываться
    connect(&lft, SIGNAL(close_doors()), &door, SLOT(close())); //двери получают сигнал закрываться


}
void Controller::flor_btn_p(int flr)
{
    emit floor_button_pushed(flr);
}
void Controller::lift_btn_p(int flr)
{
    emit lift_button_pushed(flr);
}
void Controller::hide1()
{
    emit hide();
}
void Controller::show1()
{
    emit show();
}

void Controller::change_lift_st(state_lift a )
{
    emit  set_lift_st(a);
}

void Controller::floor_ch_slot(int a)
{
    emit floor_ch(a);
}

void Controller::show_slot()
{
   emit show();
}
void Controller::hide_slot()
{
    emit hide();
}
