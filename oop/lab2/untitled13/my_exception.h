#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <exception>
// Базовый класс исключений
class my_base_exception : public std::exception
{
};


// Класс ошибки памяти
class memory_alloc_error : public my_base_exception
{
public:
    memory_alloc_error();
    virtual const char* what() const throw();
};

// Класс ошибки индексации
class index_error : public my_base_exception
{
public:
    index_error();
    virtual const char* what() const throw();
};
// Класс ошибки типа
class type_error : public my_base_exception
{
public:
    type_error();
    virtual const char* what() const throw();
};
// Класс ошибки значения(ключа)
class value_error : public my_base_exception
{
public:
    value_error();
    virtual const char* what() const throw();
};
//------------------------------Реализация класса ошибки---------------------------
memory_alloc_error::memory_alloc_error()
{
}

const char* memory_alloc_error::what() const throw()
{
     return "memory alloc error \n";
}

//------------------------------Реализация класса индексации---------------------------
index_error::index_error()
{
}
const char* index_error::what() const throw()
{
     return "index error \n";
}
//------------------------------Реализация класса типа---------------------------
type_error::type_error()
{
}
const char* type_error::what() const throw()
{
     return "type error \n";
}
//------------------------------Реализация класса ошибки значения---------------------------
value_error::value_error()
{
}

const char* value_error::what() const throw()
{
     return "value key error \n";
}

#endif // MY_EXCEPTION_H
