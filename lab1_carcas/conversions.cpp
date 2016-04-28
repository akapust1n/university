//
//		Преобразования модели в набор точек на экране
//

#include "conversions.h"
#include "canvasworks.h"
#include "file_read.h"
#include "matrixworks.h"
#include <QtWidgets> //сможно убрать потом
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
//создаёт матрицу преобразований: сдвиг х ротЗ х ротУ х ротХ х масштаб
double* GetConversionMatrix(sModel* data)
{
    double* ShiftMatrix = Get3DShiftMatrix(data->dx, data->dy, data->dz); //смещение от О
    if (!ShiftMatrix) {
        return 0;
    }
    double* RotateZMatrix = Get3DRotateZMatrix(data->fz); //поворот вокруг OZ
    if (!RotateZMatrix) {
        delete ShiftMatrix;
        return 0;
    }
    double* RotateYMatrix = Get3DRotateYMatrix(data->fy); //поворот вокруг OY
    if (!RotateYMatrix) {
        delete RotateZMatrix;
        delete ShiftMatrix;
        return 0;
    }
    double* RotateXMatrix = Get3DRotateXMatrix(data->fx); //поворот вокруг OX
    if (!RotateXMatrix) {
        delete ShiftMatrix;
        delete RotateYMatrix;
        delete RotateZMatrix;
        return 0;
    }
    double* ScaleMatrix = Get3DScaleMatrix(data->M); //масштабировние относительно О
    if (!ScaleMatrix) {
        delete ShiftMatrix;
        delete RotateZMatrix;
        delete RotateYMatrix;
        delete RotateXMatrix;
        return 0;
    }

    //матрицы получены - собираем из них исходную
   //память новая не выделяется, результат умножения сохраняется в первый параметр
    double* matr1 = MultMatrixXMatrix(ShiftMatrix, RotateZMatrix, 3); // Shift х
    // Z
    if (!matr1) {
        delete ShiftMatrix;
        delete RotateZMatrix;
        delete RotateYMatrix;
        delete RotateXMatrix;
        delete ScaleMatrix;
        return 0;
    }
    double* matr2 = MultMatrixXMatrix(matr1, RotateYMatrix, 3); // x Y
    if (!matr2) {
        delete ShiftMatrix;
        delete RotateZMatrix;
        delete RotateYMatrix;
        delete RotateXMatrix;
        delete ScaleMatrix;
        //delete matr1;
        return 0;
    }
    double* matr3 = MultMatrixXMatrix(matr2, RotateXMatrix, 3); // x X
    if (!matr3) {
        delete ShiftMatrix;
        delete RotateZMatrix;
        delete RotateYMatrix;
        delete RotateXMatrix;
        delete ScaleMatrix;
        //delete matr2;
        //delete matr1;
        return 0;
    }
    double* res = MultMatrixXMatrix(matr3, ScaleMatrix, 3); // x Scale
    if (!res) {
        delete ShiftMatrix;
        delete RotateZMatrix;
        delete RotateYMatrix;
        delete RotateXMatrix;
        delete ScaleMatrix;
        //delete matr1;
        //delete matr2;
        //delete matr3;
        return 0;
    }

    delete ShiftMatrix;
    delete RotateZMatrix;
    delete RotateYMatrix;
    delete RotateXMatrix;
    delete ScaleMatrix;
    //delete matr1;
   // delete matr2;
    //delete matr3;

    return res;
}

//преобразует единственную точку в точку на экране
sCanvasPoint ConvertSinglePoint(sPoint3d p, double* ConvMatrix, bool& error)
{
    sCanvasPoint res;
    error = false;
    double* pVector = new double[4]; //представление точки в виде вектора
    if (!pVector) { // 4 координаты нужны для использования матрицы переноса
        error = true;
        return res;
    }
    pVector[0] = p.x;
    pVector[1] = p.y;
    pVector[2] = p.z;
    pVector[3] = 1;

    //умножаем вектор точки на матрицу преобразований - получаем новую точку в
    //векторном представлении
    double* conversion = MultVectorXMatrix(pVector, ConvMatrix, 3);
    delete pVector;

    if (!conversion) {
        error = true;
        return res;
    }

    res.x = (int)floor(conversion[0]);
    res.y = (int)floor(conversion[1]);
    delete conversion;

    return res;
}

sConvertedPoints* AllocateConvertedPoints(int count)
{
    sConvertedPoints* conv = new sConvertedPoints;
    if (!conv)
        return 0;

    int* Xs = new int[count]; //массив координат Х
    if (!Xs) {
        delete conv;
        return 0;
    }
    int* Ys = new int[count]; //массив координат У
    if (!Ys) {
        delete conv;
        delete Xs;
        return 0;
    }

    conv->count = count;
    conv->Xs = Xs;
    conv->Ys = Ys;
    return conv;
}
//false в случае удачного конвертирования
//true - byfxt
bool Convertation( sConvertedPoints*& conv,sModel* points, double* ConvMatrix)
{
    bool error = false;
    for (int i = 0; i < points->vertices  && !error; i++) {
        sPoint3d temp;
        temp.x = points->x[i];
        temp.y = points->y[i];
        temp.z = points->z[i];

        sCanvasPoint point = ConvertSinglePoint(temp, ConvMatrix, error);
        conv->Xs[i] = point.x;
        conv->Ys[i] = point.y;
    }
    return error;
}

//преобразует трёхмерные точки в точки на экране
sConvertedPoints* ConvertPoints(sModel* points)
{
    sConvertedPoints* conv = AllocateConvertedPoints(points->vertices ); //структура точек на экране
                                                                            //память чиститься на уровень выше
    if (!conv)
        return 0;

    double* ConvMatrix = GetConversionMatrix(points); //матрица преобразований

    if (!ConvMatrix) {
        delete conv;
        return 0;
    }
    if (Convertation( conv, points,ConvMatrix))  //преобразуем точки
        return 0;

    delete ConvMatrix;

    return conv;
}

//очищает структуру преобразованных точки
void ClearConvertedPoints(sConvertedPoints* converted)
{
    delete converted->Xs;
    delete converted->Ys;
    delete converted;
}
