#ifndef LIFT_H
#define LIFT_H
#include <QApplication>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <doors.h>
#include <stats.h>

class Timer;
enum class state_lift { wait,
    go_empty,
    go_full,
    doors_opening,
    doors_closing,
    doors_opened,hide_panel,show_panel };

class lift : public QObject {
    Q_OBJECT
public:
    lift();
    int floor; //current
    int dest;
    friend class Timer;

private:
    int min_floor;
    int max_floor;
    state_lift st;
    bool empty;
    void set_st(state_lift a);
    int destination;
    QQueue<int> queue;
    bool update();
    Timer* timer;

signals:
    void floor_changed(int); //этаж изменился
    void open_doors(); //посылаем сигнал открыть двери
    void close_doors(); //посылаем сигнал закрыть двери
    void st_changed(state_lift); // состояние изменилось
    void arrived(); //посылаем сигнал прибытия
    void show_lift(); //показываем внутренности лифта
    void hide_lift(); //скрываем внутренности лифта
    void wait(); //ждем
    void wait_end();
    void lift_button_pushed(int);
    void floor_button_pushed(int);
   void  close_wh_hide();

public slots:
    void doors_opened_slot();
    void doors_closed_slot();
    void arrived_slot();
    void floor_but(int);
    void lift_but(int); //doors_closing state
    void waiting();
    void hide_panel();
    void show_panel();
};
class Timer {
public:
    lift* mylift;
    Timer(lift* temp){ mylift = temp; }
    void start_moving();
    void update();
};

#endif // LIFT_H
