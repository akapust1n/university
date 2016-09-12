#include <Matrixworks.h>

//
//		Вычисления над матрицами
//
//	Все матрицы представлены в виде одномерных векторов
// 4мерные матрицы используются потому, что матрица переноса в n-мерном
// пространстве имеет размер n+1 на n+1

#include <math.h>

//умножение вектора на матрицу
double* MatrixWorks::MultVectorXMatrix(double* V, double* M, int d)
{
    d++;
    double* res = new double[d];
    for (int i = 0; i < d; i++) {
        double s = 0;
        for (int j = 0; j < d; j++) {
            s += V[j] * M[j * d + i];
        }
        res[i] = s;
    }
    return res;
}

//умножение матрицы на матрицу

double* MatrixWorks::MultMatrixXMatrix(double*& M1, double* M2, int d)
{
    d++;
    double* res = new double[d * d];
    for (int i = 0; i < d; i++) {

        for (int j = 0; j < d; j++) {
            double s = 0;
            for (int k = 0; k < d; k++) {
                s += M1[i * d + k] * M2[k * d + j];
            }
            res[i * d + j] = s;
        }
    }
    return res;
}

//получение матрицы поворота вокруг оси X
double* MatrixWorks::Get3DRotateXMatrix(double ang)
{
    double* M = new double[16];
    if (!M)
        return 0;

    M[0] = 1;
    M[1] = 0;
    M[2] = 0;
    M[3] = 0;

    M[4] = 0;
    M[5] = cos(ang);
    M[6] = -sin(ang);
    M[7] = 0;

    M[8] = 0;
    M[9] = sin(ang);
    M[10] = cos(ang);
    M[11] = 0;

    M[12] = 0;
    M[13] = 0;
    M[14] = 0;
    M[15] = 1;
    return M;
}

//получение матрицы поворота вокруг оси Y
double* MatrixWorks::Get3DRotateYMatrix(double ang)
{
    double* M = new double[16];
    if (!M)
        return 0;

    M[0] = cos(ang);
    M[1] = 0;
    M[2] = sin(ang);
    M[3] = 0;

    M[4] = 0;
    M[5] = 1;
    M[6] = 0;
    M[7] = 0;

    M[8] = -sin(ang);
    M[9] = 0;
    M[10] = cos(ang);
    M[11] = 0;

    M[12] = 0;
    M[13] = 0;
    M[14] = 0;
    M[15] = 1;
    return M;
}

//получение матрицы поворота вокруг оси Z
double* MatrixWorks::Get3DRotateZMatrix(double ang)
{
    double* M = new double[16];
    if (!M)
        return 0;

    M[0] = cos(ang);
    M[1] = -sin(ang);
    M[2] = 0;
    M[3] = 0;

    M[4] = sin(ang);
    M[5] = cos(ang);
    M[6] = 0;
    M[7] = 0;

    M[8] = 0;
    M[9] = 0;
    M[10] = 1;
    M[11] = 0;

    M[12] = 0;
    M[13] = 0;
    M[14] = 0;
    M[15] = 1;
    return M;
}

//получение матрицы сдвига
double* MatrixWorks::Get3DShiftMatrix(double dx, double dy, double dz)
{
    double* M = new double[16];
    if (!M)
        return 0;

    M[0] = 1;
    M[1] = 0;
    M[2] = 0;
    M[3] = 0;

    M[4] = 0;
    M[5] = 1;
    M[6] = 0;
    M[7] = 0;

    M[8] = 0;
    M[9] = 0;
    M[10] = 1;
    M[11] = 0;

    M[12] = dx;
    M[13] = dy;
    M[14] = dz;
    M[15] = 1;
    return M;
}

//получение матрицы масштабирования
double* MatrixWorks::Get3DScaleMatrix(double scale)
{
    double* M = new double[16];
    if (!M)
        return 0;

    M[0] = scale;
    M[1] = 0;
    M[2] = 0;
    M[3] = 0;

    M[4] = 0;
    M[5] = scale;
    M[6] = 0;
    M[7] = 0;

    M[8] = 0;
    M[9] = 0;
    M[10] = scale;
    M[11] = 0;

    M[12] = 0;
    M[13] = 0;
    M[14] = 0;
    M[15] = 1;
    return M;
}
