#ifndef STRUCTURES_H
#define STRUCTURES_H
enum class pick {
    pick_mash,
    pick_pov,
    pick_sdvig,
    pick_open
};
struct new_params {
    double fx, fy, fz; //угол поворота
    double dx, dy, dz; //смещение модели
    double M; //масштаб отрисовки
    new_params()
        : fx(0)
        , fy(0)
        , fz(0)
        , dx(0)
        , dy(0)
        , dz(0)
        , M(1)
    {
    }
};
struct sConvertedPoints {
    int count; //число точек
    int* Xs; //X i-й точки
    int* Ys; //Y i-й точки
    sConvertedPoints()
        : count(0)
        , Xs(0)
        , Ys(0)
    {
    }
};
struct sPoint3d {
    double x, y, z; //координаты тчоек
    sPoint3d()
        : x(0)
        , y(0)
        , z(0)
    {
    }
};


#endif // STRUCTURES_H
