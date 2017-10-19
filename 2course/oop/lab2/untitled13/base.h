#ifndef BASE_H
#define BASE_H
#include <stdlib.h>
class base {
public:
    //Работа с размером
    base();
    //~base(){};
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
#include <base_realis.h>

#endif // BASE_H
