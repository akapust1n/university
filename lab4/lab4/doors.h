#ifndef DOORS_H
#define DOORS_H
#include <QObject>
#include <QApplication>
 enum class state{st_opening,st_closing, st_opened, st_closed};

class doors: public QObject{
    Q_OBJECT

public:
  doors();

private:
    state statement;
public slots:
  void open();
  void close();
signals:
  void change_st(int);
  void opened();
  void closed();
private slots:
  void set_st(state);
};
#endif // DOORS_H
