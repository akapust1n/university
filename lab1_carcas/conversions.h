#ifndef CONVERSIONS_H
#define CONVERSIONS_H


#include "file_read.h"
//смещение модели
struct sMove
{
    double dx;
    double dy;
    double dz;
   // sMove(): dx(0), dy(0), dz(0) {}
};

//параметры переотрисовки
struct sRenderData
{
    double fx, fy, fz; //угол поворота
    double dx, dy, dz; //смещение модели
    double M; //масштаб отрисовки
    //sRenderData(): fx(0), fy(0), fz(0), dx(0), dy(0), dz(0), M(1) {}
};

//точки в целочисленных координатах
//используются при непосредственно отрисовке
struct sConvertedPoints
{
    int count;	//число точек
    int *Xs;	//X i-й точки
    int *Ys;	//Y i-й точки
   // sConvertedPoints(): count(0), Xs(0), Ys(0) {}
};
sConvertedPoints* ConvertPoints(sModel *points);
void ClearConvertedPoints(sConvertedPoints *converted);
#endif // CONVERSIONS_H
