#pragma once
#include "base.h"
#include <iostream>
#include <iterator.h>
#include <my_exception.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <type_traits>
#include <utility>
using namespace std;
//#define GROW_SIZE 30
#include <dict.h>

//--------------

template <typename MyMapType, typename MyMapType2, class Z = std::less<MyMapType> >
class my_map : public base {
    typedef dict<MyMapType, MyMapType2> U;

public:
    //Конструкторы
    my_map();
    my_map(const my_map& data);
    my_map(my_map&& data);
    my_map(size_t n, ...);
    //Деструктор
    ~my_map();

    //оператор доступа
    MyMapType2& operator[](MyMapType& key);
    const MyMapType2& operator[](MyMapType& key) const;

    //модификаторы
    void insert(iteratorM<U>& first, iteratorM<U>& last);
    void insert(const U& val);
    void erase(iteratorM<U>& position);
    void erase(MyMapType key);
    void erase(iteratorM<U>& first, iteratorM<U>& last);
    void swap(my_map& x);
    void clear();

    //итераторы
    iteratorM<U> begin();
    iteratorM<U> end();
    const_iteratorM<const U> cbegin() const;
    const_iteratorM<const U> cend() const;

    //операторы и их экваваленты
    my_map& operator=(const my_map& mymap);
    my_map& copy(const my_map& mymap);
    bool operator==(const my_map& mymap) const;
    bool operator!=(const my_map& mymap) const;
    bool equal(const my_map& mymap) const;
    bool not_equal(const my_map& mymap) const;
    //дублирование вставки/удаления
    void operator+(const my_map& mymap);
    void operator-(const my_map& mymap);

    //операции
    iteratorM<U> find(const MyMapType& key);
    const_iteratorM<const U> cfind(const MyMapType& key);
    MyMapType2 find_elem(const MyMapType& key);
    size_t count(const MyMapType& key) const;

private:
    dict<MyMapType, MyMapType2>* a;
    void insertion_sort(U* b, int n, Z u = Z());
    U& BinarySearch(U*& arr, int count, MyMapType element, Z u = Z());
    void grow();
    const int GROW_SIZE = 30;
    MyMapType2 non_element = 0;
};
