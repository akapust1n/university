#ifndef CONVERTER_H
#define CONVERTER_H
#include <structures.h>
#include <SceneObjects.h>
#include <Matrixworks.h>
#include <QPoint>
class Converter{
public:
     virtual sConvertedPoints *getConvertedPoints(PrototypeModel *a){}

};
class ConcreteConverter1:public Converter{
public:
    virtual sConvertedPoints *getConvertedPoints(ConcreteModel1 *a, ConcreteCamera1 *camera1);
private:
    MatrixWorks mt;
    double* GetConversionMatrix(ConcreteModel1 *data);
    sConvertedPoints* AllocateConvertedPoints(int count);
    void Convertation(sConvertedPoints*& conv, ConcreteModel1* points, double* ConvMatrix, ConcreteCamera1 *camera1);
    QPoint ConvertSinglePoint(sPoint3d p, double* ConvMatrix);
    double* MultVectorXMatrix(double* V, double* M, int d);

};

#endif // CONVERTER_H
