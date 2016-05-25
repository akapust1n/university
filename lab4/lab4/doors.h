#ifndef DOORS_H
#define DOORS_H
#include <QApplication>
#include <QObject>
#include <statements.h>
class doors : public QObject {
    Q_OBJECT

public:
    doors();

private:
    state statement;
public slots:
    void open();
    void close();
signals:
    void change_st(state);
    void opened();
    void closed();
private slots:
    void set_st(state);
};
#endif // DOORS_H
