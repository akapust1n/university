#pragma once
#include "base.h"
#include <iostream>
#include <iterator.h>
#include <my_exception.h>
#include <stdio.h>
#include <stdlib.h>
#include <type_traits>
#include <utility>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;
//#define GROW_SIZE 30

//--------реализация структуры для хранения
template <typename MyMapType, typename MyMapType2>
struct dict {
    dict();
    // ~dict(){}
    MyMapType first;
    MyMapType2 second;
    //dict & operator*() { return *ptr; }
    bool operator==(const dict& dict_temp);
    bool operator!=(const dict& dict_temp);
};

template <typename MyMapType, typename MyMapType2>
bool dict<MyMapType, MyMapType2>::operator==(const dict& dict_temp)
{
    return dict_temp.first == first and dict_temp.second == second;
}

template <typename MyMapType, typename MyMapType2>
bool dict<MyMapType, MyMapType2>::operator!=(const dict& dict_temp)
{
    return dict_temp.first != first or dict_temp.second != second;
}
template <typename MyMapType, typename MyMapType2>
dict<MyMapType, MyMapType2>::dict()
    : first(0)
    , second(0)
{
}
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
    MyMapType2& operator[](MyMapType& key) const;

    //модификаторы
    void insert(iteratorM<U>& first, iteratorM<U>& last);
    void insert(const U& val);
    void insert(iteratorM<U>& position, const U& val);
    void erase(iteratorM<U>& position);
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
    bool equal(const my_map& mymap) const;
    //дублирование вставки/удаления
    void operator+(const my_map& mymap);
    void operator-(const my_map& mymap);

    //операции
    iteratorM<U> find(const MyMapType& key);
    MyMapType2 find_elem(const MyMapType& key);
    size_t count(const MyMapType& key) const;

private:
    dict<MyMapType, MyMapType2>* a;
    void insertion_sort(U* b, int n, Z u = Z());
    MyMapType2 BinarySearch(U* arr, int count, MyMapType element, Z u = Z());
    void grow();
    const int GROW_SIZE = 30;
};
//-------------------------------Реализация-----------------

//------------Конструкторы-------------

template <class MyMapType, class MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>::my_map()
    : base()
    , a(0)
{
}

template <class MyMapType, class MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>::my_map(my_map&& dict)
    : base()
    , a(0)
{
    size = dict.size;
    max_size = dict.max_size;
    a = dict.a;
    dict.max_size = 0;
    dict.size = 0;
    dict.a = nullptr;
    /*a = new my_map[max_size];
    for (int i = 0; i < size; i++)
        a[i] = dict.a[i]; */
}

template <class MyMapType, class MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>::my_map(size_t n, ...)
    : base()
    , a(0)
{
    va_list ap; //Указатель на список параметров
    va_start(ap,n);
    while (n--) //--пока аргумент не равен нулю
    {
        U ival=va_arg(ap,U);
        insert(ival);

    };
}

//------------Деструктор---------
template <class MyMapType, class MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>::~my_map()
{
    //  ~base();
    delete[] a;
}
//- -------сортировка--------

template <class MyMapType, class MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::insertion_sort(U* a, int n, Z u)
{

    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && u(a[j].first, a[j - 1].first); --j)
            std::swap(a[j - 1], a[j]);
}
//---------------Поиск-------
template <class MyMapType, class MyMapType2, class Z>
MyMapType2 my_map<MyMapType, MyMapType2, Z>::BinarySearch(U* arr, int count, MyMapType element, Z u)
{
    int first = 0;
    int last = count; // Элемент в last не учитывается.
    while (first < last) {
        MyMapType mid = (first + last) / 2;
        if (element <= arr[mid].first)
            last = mid;
        else
            first = mid + 1; // Здесь отличие от BinarySearch1.
    }
    // Все элементы слева от first строго больше искомого.
    if (first == count || arr[first].first != element)
        throw value_error();
    return arr[first].second;
}
//-------Расширение массивa----------
template <class MyMapType, class MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::grow()
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
//-----------------Итераторы
template <class MyMapType, class MyMapType2, class Z>
iteratorM<dict<MyMapType, MyMapType2> > my_map<MyMapType, MyMapType2, Z>::begin()
{
    iteratorM<dict<MyMapType, MyMapType2> > tmp(a);
    return tmp;
}
template <class MyMapType, class MyMapType2, class Z>
iteratorM<dict<MyMapType, MyMapType2> > my_map<MyMapType, MyMapType2, Z>::end()
{
    iteratorM<dict<MyMapType, MyMapType2> > tmp(&a[size - 1]);
    return tmp;
}
template <class MyMapType, class MyMapType2, class Z>
const_iteratorM<const dict<MyMapType, MyMapType2> > my_map<MyMapType, MyMapType2, Z>::cbegin() const
{
    const_iteratorM<const dict<MyMapType, MyMapType2> > tmp(a);
    return tmp;
}
//-----------Оператор доступа
template <class MyMapType, class MyMapType2, class Z>
MyMapType2& my_map<MyMapType, MyMapType2, Z>::operator[](MyMapType& key) const
{
    static MyMapType2 non_element = 0;
    size_t number = 0;
    for (; number < size and a[number].first != key; number++)
        ;

    //   return a[number].second;
    return (number == size + 1 ? (non_element) : a[number].second);
}

//--------Модификаторы---------------------
//очистка словаря и освобождение памяти
template <class MyMapType, class MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::clear()
{
    delete[] a;
    size = 0;
    max_size = 0;
}

//-----Вставка элемента--------
template <class MyMapType, class MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::insert(const U& val)
{
    bool flag = 0;
    for (size_t i = 0; i < size and !flag; i++) {
        if (a[i].first == val.first)
            flag = 1;
    }
    if (!flag)

        size++;
    if (size >= max_size)
        grow();
    a[size - 1] = val;
    insertion_sort(a, size);
}

template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::insert(iteratorM<dict<MyMapType, MyMapType2> >& position, const U& val)
{
    position.value() = val;
}

//------Удаление элемента(ов)
template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::erase(iteratorM<dict<MyMapType, MyMapType2> >& position)
{
    // cout<<*position.ptr->first;
    int element_search = -1;
    for (size_t i = 0; i < size and element_search != i; i++) {
        if (a[i] == *position)
            element_search = i;
    }
    for (size_t i = element_search; i < size; i++)
        a[i] = a[i + 1];
    size--;
}

template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::erase(iteratorM<U>& first, iteratorM<U>& last)
{
    int element_search_first = -1;
    for (size_t i = 0; i < size and element_search_first != i; i++) {
        if (a[i] == *first)
            element_search_first = i;
    }

    int element_search_second = -1;
    for (size_t i = element_search_first; i < size and element_search_second != i; i++) {
        if (a[i] == *last)
            element_search_second = i;
    }
    if (element_search_first == -1 or element_search_second == -1 or element_search_first > element_search_second)
        throw index_error();
    size_t range = element_search_second - element_search_first + 1;

    for (size_t i = element_search_first; i <= element_search_second; i++)
        a[i] = a[i + range];
    U* b = new U[size - range];
    if (!b)
        throw memory_alloc_error();
    for (int i = 0; i < (size - range); i++)
        b[i] = a[i];
    delete[] a;
    a = b;
    size -= range;
}

//-----------очистка------------

template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::swap(my_map& x)
{
    U* temp = new U[size];
    if (!temp)
        throw memory_alloc_error();
    for (size_t i = 0; i < size; i++) {
        temp[i] = a[i];
    }
    delete[] a;
    a = new U[x.get_size()];
    if (!temp)
        throw memory_alloc_error();

    iteratorM<dict<MyMapType, MyMapType2> > z1(x.begin());
    iteratorM<dict<MyMapType, MyMapType> > z1_end(x.end());
    for (size_t i = 0; z1 <= z1_end; ++z1, i++) {
        a[i] = z1.value();
    }
    int temp_size = size;
    size = x.get_size();
    x.size = 0;
    x.max_size = 0;
    if (!temp)
        throw memory_alloc_error();

    for (size_t i = 0; i < temp_size; i++) {
        x.insert(temp[i]);
    }

    delete[] temp;
    return;
}
//-----------------------прочие функци--------
//----------поиск
template <typename MyMapType, typename MyMapType2, class Z>
MyMapType2 my_map<MyMapType, MyMapType2, Z>::find_elem(const MyMapType& key)
{
    return BinarySearch(a, size, key);
}

template <typename MyMapType, typename MyMapType2, class Z>
iteratorM<dict<MyMapType, MyMapType2> > my_map<MyMapType, MyMapType2, Z>::find(const MyMapType& key)
{

    iteratorM<U> start(begin());
    iteratorM<U> end_(end());
    for (; start <= end_ and start.value().first != key; ++start)
        ;

    if (start == end_ and start.value().first != key)
        throw index_error();
    return start;
}

//количество элементов(максимум 1)
template <typename MyMapType, typename MyMapType2, class Z>
size_t my_map<MyMapType, MyMapType2, Z>::count(const MyMapType& key) const
{
    size_t i = 0;
    for (; i < size and a[i].first != key; i++)
        ;
    return i == size ? 0 : 1;
}

//------операторы
//оператор равенства
template <typename MyMapType, typename MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>& my_map<MyMapType, MyMapType2, Z>::operator=(const my_map& mymap)
{
    delete[] a;

    size = mymap.size;
    max_size = mymap.max_size;
    a = new U[size];
    if (!a)
        throw(memory_alloc_error());

    for (int i = 0; i < mymap.size; i++)
        a[i] = mymap.a[i];

    return *this;
}
template <typename MyMapType, typename MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>& my_map<MyMapType, MyMapType2, Z>::copy(const my_map& mymap)
{
    delete[] a;

    size = mymap.size;
    max_size = mymap.max_size;
    a = new U[size];
    if (!a)
        throw(memory_alloc_error());

    for (int i = 0; i < mymap.size; i++)
        a[i] = mymap.a[i];

    return *this;
}
//оператор сравнения
template <typename MyMapType, typename MyMapType2, class Z>
bool my_map<MyMapType, MyMapType2, Z>::operator==(const my_map& mymap) const
{
    if (size != mymap.size)
        return 0;
    for (size_t i = 0; i < size; i++)
        if (a[i] != mymap.arr[i])
            return 0;
    return 1;
}
template <typename MyMapType, typename MyMapType2, class Z>
bool my_map<MyMapType, MyMapType2, Z>::equal(const my_map& mymap) const
{
    if (size != mymap.size)
        return 0;
    for (size_t i = 0; i < size; i++)
        if (a[i] != mymap.arr[i])
            return 0;
    return 1;
}
//-------добавление элемента---------
template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::operator+(const my_map& mymap)
{
    insert(mymap);
}

//------удаление элемента
template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::operator-(const my_map& mymap)
{
    erase(find(mymap));
}
