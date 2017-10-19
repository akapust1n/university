#ifndef FILE_READ_H
#define FILE_READ_H
#include <fstream>
#define NODE_COUNT 2
using namespace std;
//структура точки
struct sPoint3d {
    double x, y, z; //координаты тчоек
    sPoint3d()
        : x(0)
        , y(0)
        , z(0)
    {
    }
};

//массив куда считываем точки
//размер массива в два раза больше количества ребер
//то бишь в элементах 0-1 храним первое ребро, в 2-3 второе и тд
struct sModel {
    int vertices;
    int edge_num;
    double* x;
    double* y;
    double* z;
    int *links;
    double fx, fy, fz; //угол поворота
    double dx, dy, dz; //смещение модели
    double M; //масштаб отрисовки
    // sModel(): x(0), y(0), z(0), vertices(0),fx(0), fy(0), fz(0), dx(0), dy(0), dz(0), M(1) {}
};
struct sSavedModels {
    int vertices;
    double* x;
    double* y;
    double* z;
    int* border;
    double *fx, *fy, *fz; //угол поворота
    double *dx, *dy, *dz; //смещение модели
    double* M; //масштаб отрисовки
    //sSavedModels(): x(0), y(0), z(0), vertices(0),fx(0), fy(0), fz(0), dx(0), dy(0), dz(0), M(0), border(0) {}
};
struct sPointsList {
    int count; //количество вершин
    sPoint3d* pointsArray; //массив вершин
};
//перечислитель результата обработки файла с моделью: ошибок нет, файл не найден, поврежден,
//не хватает памяти, неизвестная ошибка
enum eCodeFile { cfFine,
    cfNotFound,
    cfCorrupted,
    cfOutOfMemory,
    cfUnknownAction, cfModelNotLoaded };

struct file_data {
    ifstream model1;
};

eCodeFile file_read(sModel& model, const char* filename);
eCodeFile read_3points(file_data& m, sModel& model, int i);
eCodeFile read_2points(file_data& m, sModel& model, int i);


#endif // FILE_READ_H
