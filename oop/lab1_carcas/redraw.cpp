#include "conversions.h"
#include "matrixworks.h"
#include "render.h"

//поворот модели
eCodeFile ChangeRotation(sModel& renderdata, sMove move)
{
    if (renderdata.vertices == 0)
        return cfModelNotLoaded;

    renderdata.fx += move.dx;
    renderdata.fy += move.dy;
    renderdata.fz += move.dz;
    return cfFine;
}
eCodeFile SetRotation(sModel& renderdata, sMove angle)
{
    if (renderdata.vertices == 0)
        return cfModelNotLoaded;

    renderdata.fx = angle.dx;
    renderdata.fy = angle.dy;
    renderdata.fz = angle.dz;
    return cfFine;
}
eCodeFile ChangeScale(sModel& renderdata, double scale)
{
    if (renderdata.vertices == 0)
        return cfModelNotLoaded;

    renderdata.M *= scale; // в случае чего, вернуть обычное равно
    return cfFine;
}

eCodeFile ChangeShift(sModel& renderdata, sMove move)
{
    if (renderdata.vertices == 0)
        return cfModelNotLoaded;
    renderdata.dx += move.dx;
    renderdata.dy += move.dy;
    renderdata.dz += move.dz;
    return cfFine;
}
void update_model_info(sModel& model)
{
    model.dx = 0;
    model.dy = 0;
    model.dz = 0;
    model.fx = 0;
    model.fy = 0;
    model.fz = 0;
    model.M = 1;
    return;
}

eCodeFile DelModels(sModel& model, sSavedModels& smodels)
{
    if (model.vertices == 0)
        return cfModelNotLoaded;
    if (model.x)
        delete[] model.x;
    if (model.y)
        delete[] model.y;
    if (model.z)
        delete[] model.z;

    if (smodels.x)
        delete[] smodels.x;
    if (smodels.y)
        delete[] smodels.y;
    if (smodels.z)
        delete[] smodels.z;
    if (smodels.dx)
        delete[] smodels.dx;
    if (smodels.dy)
        delete[] smodels.dy;
    if (smodels.dz)
        delete[] smodels.dz;
    if (smodels.fx)
        delete[] smodels.fx;
    if (smodels.fy)
        delete[] smodels.fy;
    if (smodels.fz)
        delete[] smodels.fz;
    if (smodels.M)
        delete[] smodels.M;
    if (smodels.border)
        delete[] smodels.border;
    return cfFine;
}

eCodeFile SaveModel(sModel model, sSavedModels& S_models) //заглушка
{
    if (model.vertices == 0)
        return cfModelNotLoaded;

    return cfFine;
}
sModel initModel()
{
    sModel m;
    m.dx = 0;
    m.dy = 0;
    m.dz = 0;
    m.fx = 0;
    m.fy = 0;
    m.fz = 0;
    m.M = 1;
    m.vertices = 0;
    m.x = 0;
    m.y = 0;
    m.z = 0;
    return m;
}
sSavedModels initSavedModels()
{
    sSavedModels m;
    m.dx = 0;
    m.dy = 0;
    m.dz = 0;
    m.fx = 0;
    m.fy = 0;
    m.fz = 0;
    //*m.M = 1;
    m.vertices = 0;
    m.x = 0;
    m.y = 0;
    m.z = 0;
    m.border = 0;
    return m;
}
eCodeFile switchModel(sModel s, sSavedModels m)
{
    eCodeFile res = cfFine;
    return res;
}
