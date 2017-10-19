//
//		Непосредственно отрисовка модели
//
#include "render.h"
#include "canvasworks.h"
#include "conversions.h"
#include <QGraphicsScene>
#include <entrypoint.h>
#include <file_read.h>
#include <draw_lines.h>

//отрисовка модели на мольберте с указанными параметрами
eCodeFile DrawModel(sModel& mdl, uChangeData data)
{
    if (mdl.vertices == 0)
        return cfModelNotLoaded;
    //переводим точки модели в точки холста
    sConvertedPoints* conv = ConvertPoints(&mdl);
    if (!conv)
        return cfUnknownAction;
    ClearScene(data.scene);
    DrawEdges(conv, data, mdl);

    delete conv;
    return cfFine;
}
