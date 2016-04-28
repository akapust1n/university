#pragma once
#include <conversions.h>
#include <QtWidgets>
#include "file_read.h"
//перечислитель команд: загрузить из файла, масштабировать, вращать,
// перемещать, сменить модель, сохранить модель, удалить модели, отрисовка
enum eChangeAction { caLoad, caScale,  caSetRot, caShift,caSwitchModel,caSaveModel,caDelModels, caDraw};

//передаваемые вместе с командой данные
struct uChangeData
{
    sMove move;		//смещение
    double scale;	//масштаб
    char filename[200];	//имя файла для открытия
    QGraphicsScene *scene;
    uChangeData():  scale(0) {}
};
struct uLinePoints{
    int x1;
    int y1;
    int x2;
    int y2;
};

//непосредственно обработчик всех и всяческих изменений
eCodeFile Apply(eChangeAction action, uChangeData *data);


