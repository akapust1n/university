#ifndef STRUCTURES_H
#define STRUCTURES_H
enum class pick
{
  pick_mash,pick_pov,pick_sdvig,pick_open
};
struct new_params
{
    double fx, fy, fz; //угол поворота
    double dx, dy, dz; //смещение модели
    double M; //масштаб отрисовки
};

#endif // STRUCTURES_H
