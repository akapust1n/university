#ifndef MY_MAP_DICT_REAL_H
#define MY_MAP_DICT_REAL_H
#include <dict.h>
template <typename MyMapType, typename MyMapType2>
bool dict<MyMapType, MyMapType2>::operator==(const dict& dict_temp)
{
    return dict_temp.first == first ;
}

template <typename MyMapType, typename MyMapType2>
bool dict<MyMapType, MyMapType2>::operator!=(const dict& dict_temp)
{
    return dict_temp.first != first ;
}
template <typename MyMapType, typename MyMapType2>
dict<MyMapType, MyMapType2>::dict()
    : first(0)
    , second(0)
{
}
//-------Расширение массивa----------
template <typename MyMapType, typename MyMapType2>
dict<MyMapType, MyMapType2>::grow()
{
    max_size += GROW_SIZE;
    U* b = new U[max_size];
    if (!b) {
        size--;
        throw memory_alloc_error();
    }
    for (size_t i = 0; i < size - 1; i++)
        b[i] = a[i];
    delete[] a;

    a = b;
}

#endif // MY_MAP_DICT_REAL_H
