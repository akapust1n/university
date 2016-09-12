#ifndef MY_MAP_DICT_REAL_H
#define MY_MAP_DICT_REAL_H
#include <dict.h>
#include <my_exception.h>
//----------Деструктор------
template <typename MyMapType, typename MyMapType2>
dict<MyMapType, MyMapType2>::~dict()
{
   if (second)
        delete[] second;
}

template <typename MyMapType, typename MyMapType2>
bool dict<MyMapType, MyMapType2>::operator==(const dict& dict_temp) const
{
    return dict_temp.first == first;
}

template <typename MyMapType, typename MyMapType2>
bool dict<MyMapType, MyMapType2>::operator!=(const dict& dict_temp) const
{
    return dict_temp.first != first;
}
template <typename MyMapType, typename MyMapType2>
dict<MyMapType, MyMapType2>::dict()
    : first(0)
{
    second = new MyMapType2[1];
}
//-------Расширение массивa----------

template <typename MyMapType, typename MyMapType2>
void dict<MyMapType, MyMapType2>::grow()
{
    size += grow_size;
    MyMapType2* second_temp = new MyMapType2[size];
    if (!second_temp) {
        size--;
        throw memory_alloc_error();
    }
    for (size_t i = 0; i < size - 1; i++)
        second_temp[i] = second[i];
    delete[] second;

    second = second_temp;
}
//Изменение текущего значения
template <typename MyMapType, typename MyMapType2>
void dict<MyMapType, MyMapType2>::setcurrentMeaning(size_t i)
{
    if (i > 0 and i < size)
        currentMeaning = i;
    else
        throw(index_error());
}
template <typename MyMapType, typename MyMapType2>
 dict<MyMapType, MyMapType2>::dict( dict&& item)
 {
     this->first = item.first;
     this->second = new MyMapType2[item.getsize()];
     if(!this->second)
         throw (memory_alloc_error());
     for(int i =0 ;i<item.getsize();i++){
         this->second[i]=item.second[i];
     }
     delete [] item.second;
 }
 template <typename MyMapType, typename MyMapType2>
 dict<MyMapType, MyMapType2>::dict(const dict &item)
 {
    this->first = item.first;
     this->second = new MyMapType2[item.getsize()];
     if(!this->second)
         throw (memory_alloc_error());
     for(int i =0 ;i<item.getsize();i++){
         this->second[i]=item.second[i];
     }

 }
 template <typename MyMapType, typename MyMapType2>
 dict<MyMapType, MyMapType2>& dict<MyMapType, MyMapType2>::  operator=(const dict& item)
 {
     this->first = item.first;
     this->second = new MyMapType2[item.getsize()];
     if(!this->second)
         throw (memory_alloc_error());
     for(int i =0 ;i<item.getsize();i++){
         this->second[i]=item.second[i];
     }

 }

#endif // MY_MAP_DICT_REAL_H
