#ifndef LIFT_H
#define LIFT_H
#include <QApplication>
#include <QObject>
#include <QTime>
#include <doors.h>
#include <stats.h>
#include <QQueue>

class lift : public QObject {
    Q_OBJECT
public:
    lift();

private:
    int min_floor;
    int max_floor;
    int floor; //current
    int dest;
    doors door;
    state_lift st;
    //emp empt;
    void set_st(state_lift a);
    int destination;
    QQueue<int> queue;
    void update();
signals:
    void floor_changed(int);
    void open_doors();
    void close_doors();
    void st_changed(state_lift); // состояние изменилось
    void arrived();
    void show_lift();
    void hide_lift();

public slots:
    void doors_opened_slot();
    void doors_closed_slot();
    void arrived_slot();
    void floor_but(int);
    void lift_but(int);
};

#endif // LIFT_H
