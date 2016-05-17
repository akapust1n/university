#ifndef CONVERTER_H
#define CONVERTER_H
#include <structures.h>
#include <SceneObjects.h>
#include <Matrixworks.h>
#include <QPoint>
class Converter{
public:
     virtual sConvertedPoints *getConvertedPoints(PrototypeModel *a) = 0;

};
class ConcreteConverter1:public Converter{
public:
    sConvertedPoints *getConvertedPoints(ConcreteModel1 *a);
private:
    MatrixWorks mt;
    double* GetConversionMatrix(ConcreteModel1 *data);
    sConvertedPoints* AllocateConvertedPoints(int count);
    void Convertation(sConvertedPoints*& conv, ConcreteModel1* points, double* ConvMatrix);
    QPoint ConvertSinglePoint(sPoint3d p, double* ConvMatrix);
    double* MultVectorXMatrix(double* V, double* M, int d);

};

#endif // CONVERTER_H
