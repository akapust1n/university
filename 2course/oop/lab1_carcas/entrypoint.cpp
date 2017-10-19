
#include "entrypoint.h"
#include "conversions.h"
#include "render.h"
#include <QtGui>
#include <redraw.h>
//#include "model.h"
//#include "actions.h"
#include "file_read.h"
#include <QGraphicsScene>

//применяем действие, переданное из интерфейса
eCodeFile Apply(eChangeAction action, uChangeData* data)
{
    static sModel model = initModel(); //текущая модель
    static sSavedModels S_models = initSavedModels();

    static eCodeFile res;

    switch (action) {
    case caLoad: //загрузка модели из файла
    {
        res = file_read(model, data->filename);
        break;
    }
    case caScale: //изменение масштаба модели
    {
        res = ChangeScale(model, data->scale);
        break;
    }
    case caSetRot: //установка углов поворота модели
    {
        // SetRotation(&changes, data->move);
        res = ChangeRotation(model, data->move);
        break;
    }
    case caShift: //изменение смещения модели
    {
        res = ChangeShift(model, data->move);
        break;
    }
    case caSwitchModel: //сменить модель на одну из предыдущих - заглушка
    {
        res = switchModel(model, S_models);
        break;
    }
    case caSaveModel: //сохранить модель - заглушка
    {
        res = SaveModel(model, S_models);
        break;
    }
    case caDelModels: //очистить память
    {
        res = DelModels(model, S_models);
        break;
    }
    case caDraw: //отрсовка
    {
        res = DrawModel(model, *data);
        break;
    }
    default:
        return cfUnknownAction;
    }

    return res;
}
