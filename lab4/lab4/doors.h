#ifndef DOORS_H
#define DOORS_H
#include <QApplication>
#include <QObject>
#include <statements.h>
class doors : public QObject {
    Q_OBJECT
public:
    doors();

public slots:
    void open();
    void close();
signals:
    void opened();
    void closed();
private slots:
};
#endif // DOORS_H
