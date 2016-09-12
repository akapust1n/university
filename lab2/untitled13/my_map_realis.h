#include <dict_realis.h>
#include <my_map.h>
#pragma once
//-------------------------------Реализация-----------------

//------------Конструкторы-------------

template <class MyMapType, class MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>::my_map()
    : base()
    , a(nullptr)
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
    va_start(ap, n);
    while (n--) //--пока аргумент не равен нулю
    {
        U ival = va_arg(ap, U);
        insert(ival);
    };
}

//------------Деструктор---------
template <class MyMapType, class MyMapType2, class Z>
my_map<MyMapType, MyMapType2, Z>::~my_map()
{
    //  ~base();
   // delete[] a;
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
dict<MyMapType, MyMapType2>& my_map<MyMapType, MyMapType2, Z>::BinarySearch(U*& arr, int count, MyMapType element, Z u)
{
    int first = 0;
    int last = count;
    while (first < last) {
        MyMapType mid = (first + last) / 2;
        if (element <= arr[mid].first)
            last = mid;
        else
            first = mid + 1;
    }
    // Все элементы слева от first строго больше искомого.
    if (first == count|| arr[first].first != element )
        throw value_error();

    return arr[first];
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
MyMapType2& my_map<MyMapType, MyMapType2, Z>::operator[](MyMapType& key)
{

    try {
        BinarySearch(a, size, key).second[BinarySearch(a, size, key).getcurrentMeaning()];
    } catch (value_error) {
        return non_element;
    }

    return BinarySearch(a, size, key).second[BinarySearch(a, size, key).getcurrentMeaning()];
}
template <class MyMapType, class MyMapType2, class Z>
const MyMapType2& my_map<MyMapType, MyMapType2, Z>::operator[](MyMapType& key) const
{

    try {
        BinarySearch(a, size, key).second[BinarySearch(a, size, key).getcurrentMeaning()];
    } catch (value_error) {
        return non_element;
    }

    return BinarySearch(a, size, key).second[BinarySearch(a, size, key).getcurrentMeaning()];
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
void my_map<MyMapType, MyMapType2, Z>::insert(const U &val)
{
    size++;
    dict<MyMapType,MyMapType2> *temp = nullptr ;
    if (size >= max_size)
        grow();
    try {
       temp =& BinarySearch(a, size, val.first);
    }
   /* catch(...)
    {
        std::cout<<"any";
    }*/
    catch (value_error) {
        a[size - 1] = val;
        insertion_sort(a, size);
        return;
    }
    temp->grow();
    temp->setcurrentMeaning(temp->getcurrentMeaning()+1);
    temp->setSecond(val.cgetSecond());
    return;

}
template <class MyMapType, class MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::insert(iteratorM<U>& first, iteratorM<U>& last)
{
    for (iteratorM<U> i = first; i <= last; i++) {
        insert(i.value());
    }
}

//------Удаление элемента(ов)

template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::erase(MyMapType key)
{
    int element_search = -1;
    for (size_t i = 0; i < size and element_search != i; i++) {
        if (a[i].first == key)
            element_search = i;
    }
    for (size_t i = element_search; i < size; i++)
        a[i] = a[i + 1];
    size--;
}

template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::erase(iteratorM<dict<MyMapType, MyMapType2> >& position)
{
    // cout<<*position.ptr->first;
    int element_search = -1;
    for (size_t i = 0; i < size and element_search != i; i++) {
        if (a[i].first == *position.value().first)
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

    return BinarySearch(a, size, key).getSecond();
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
template <typename MyMapType, typename MyMapType2, class Z>
const_iteratorM<const dict<MyMapType, MyMapType2> > my_map<MyMapType, MyMapType2, Z>::cfind(const MyMapType& key)
{
    const_iteratorM<U> start(cbegin());
    const_iteratorM<U> end_(cend());
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
bool my_map<MyMapType, MyMapType2, Z>::operator!=(const my_map& mymap) const
{
    if (size != mymap.size)
        return 0;
    for (size_t i = 0; i < size; i++)
        if (a[i] != mymap.arr[i])
            return 1;
    return 0;
}
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
template <typename MyMapType, typename MyMapType2, class Z>
bool my_map<MyMapType, MyMapType2, Z>::not_equal(const my_map& mymap) const
{
    if (size != mymap.size)
        return 0;
    for (size_t i = 0; i < size; i++)
        if (a[i] != mymap.arr[i])
            return 1;
    return 0;
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
/*
//если такого значения нет, то сбрасывается до максимального
template <typename MyMapType, typename MyMapType2, class Z>
void my_map<MyMapType, MyMapType2, Z>::cmpWithGlobalMeaning(size_t index, U obj)
{
    if (index > -1 and obj.getsize() > index)
        obj.setcurrentMeaning(index);
    else if (obj.setcurrentMeaning(obj.getsize() - 1))
        ;
}
*/
