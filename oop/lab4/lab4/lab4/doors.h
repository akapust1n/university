#ifndef DOORS_H
#define DOORS_H
#include <QApplication>
#include <QObject>
enum class door_state {
    opened,
    closed
};

class doors : public QObject {
    Q_OBJECT
public:
    doors();
    door_state state = door_state::closed;
public slots:
    void open();
    void close();
signals:
    void opened();     //двери открыты
    void closed();     //двери закрыты
private slots:
};
#endif // DOORS_H
