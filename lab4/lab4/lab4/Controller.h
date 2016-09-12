#ifndef CONTROLLER
#define CONTROLLER
#include "Lift_panel.h"
#include "lift.h"
class Controller : public QObject {
    Q_OBJECT
signals:
    void floor_button_pushed(int);
    void lift_button_pushed(int);
    void set_lift_st(state_lift st);
    void hide();
    void show();
    void floor_ch(int);
public slots:
    void change_lift_st(state_lift a);
    void floor_ch_slot(int a);
    void hide_slot();
    void show_slot();

public:
    Controller();
    //интерфейс
    void flor_btn_p(int flr); //нажата кнопка снаружи лифта
    void lift_btn_p(int flr); //нажата кнопка внутри лифта
    void hide1();             //скрыть панель выбора этажа
    void show1();             //показать панель выбора этажа
private:
    lift lft;
    doors door;
    Control_panel control_panel;

};

#endif // CONTROLLER
