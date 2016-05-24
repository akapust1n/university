#ifndef LIFT_H
#define LIFT_H
#include <doors.h>
#include <stats.h>
#include <QObject>
#include <QApplication>
enum class state_lift { wait,
    go,
    doors_opening,
    doors_closing,
    doors_opened,
    minor_wait };
class lift : public QObject {
    Q_OBJECT
public:
    lift();

private:
    int min_floor;
    int max_floor;
    int cur_floor;
    int dest;
    doors door;
    state_lift st;
    //emp empt;
    int destination;
    //QQueue<int> queue;
    void update();
signals:
    void floor_changed(int);
    void open_doors();
    void close_doors();
    void st_changed(int);
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
