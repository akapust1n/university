#ifndef LIFT_PANEL
#define LIFT_PANEL
#include <QObject>
enum class panel_state {
    hide,
    shown
};

class Control_panel : public QObject {
    Q_OBJECT
public:
    panel_state c_state=panel_state::hide;
signals:
    void show_el();
    void hide_el();
    void hide_el2();
public slots:
    void show();
    void hide();

};

#endif // LIFT_PANEL
