#include "lift.h"


lift::lift()
{
    min_floor = 1;
    max_floor = 7;
    cur_floor = 1;
    st = state_lift::wait;
    connect(this,SIGNAL(open_doors()),&door,SLOT(open())) ;// двери получают сигнал открываться
    connect(this,SIGNAL(close_doors()),&door,SLOT(close())); //двери получают сигнал закрываться
    connect(this,SIGNAL(arrived()),this,SLOT(arrived_slot())); //прибываем
    connect(&door,SIGNAL(opened()),this,SLOT(doors_opened_slot())); //получаем от дверей, что они открылись
    connect(&door,SIGNAL(closed()),this,SLOT(doors_closed_slot())); //получаем от дверей, что они закрылись
}
void lift::arrived_slot(){

}

void lift::doors_opene_slot(){
}
void lift::doors_closed_slot(){
}

/*
void lift::set_st(state_lift a){
    st =  a;
    //emit st_changed(a);
}*/
