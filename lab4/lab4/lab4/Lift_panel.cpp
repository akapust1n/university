#include <Lift_panel.h>
#include <QMessageBox>
void Control_panel::show()
{

    if (c_state == panel_state::hide) {
        c_state = panel_state::shown;
        emit show_el();
        return;
    }
}
void Control_panel::hide()
{

    if (c_state == panel_state::shown) {
        c_state = panel_state::hide;
        emit hide_el();
        return;
    }
}

