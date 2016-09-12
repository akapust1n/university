#ifndef MATRIXWORKS_H
#define MATRIXWORKS_H


//умножение вектора на матрицу
double *MultVectorXMatrix(double *V, double *M, int d);

//умножение матрицы на матрицу
double *MultMatrixXMatrix(double *&M1, double *M2, int d);

//получение матрицы поворота вокруг оси Х
double *Get3DRotateXMatrix(double ang);

//получение матрицы поворота вокруг оси Y
double *Get3DRotateYMatrix(double ang);

//получение матрицы поворота вокруг оси Z
double *Get3DRotateZMatrix(double ang);

//получение матрицы сдвига
double *Get3DShiftMatrix(double dx, double dy, double dz);

double *Get3DScaleMatrix(double scale);
#endif // MATRIXWORKS_H
