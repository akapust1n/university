#ifndef BASE_H
#define BASE_H
#include <stdlib.h>
class base {
public:
    //Работа с размером
    base();
    ~base(){};
    size_t get_size() const;
    bool is_empty() const;
    size_t get_maxsize() const;


protected:
    size_t size;
    size_t max_size;
};
base::base()
    : size(0)
    , max_size(0)
{
}
//получение размера
size_t base::get_size() const
{
    return size;
}
//проверка на пустоту
bool base::is_empty() const
{
    return (size == 0) ? 1 : 0;
}
//получение максимального размера
size_t base::get_maxsize() const
{
    return max_size;
}

#endif // BASE_H
