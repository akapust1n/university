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
    new_params():fx(0),fy(0),fz(0),dx(0),dy(0),dz(0),M(1){}
};

#endif // STRUCTURES_H
