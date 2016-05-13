#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <exception>
// Базовый класс исключений
class my_base_exception : public std::exception
{
};
// Класс ошибки чтения файла
class file_read_error : public my_base_exception
{
public:
    file_read_error();
    virtual const char* what() const throw();
};
// Класс ошибки памяти
class memory_alloc_error : public my_base_exception
{
public:
    memory_alloc_error();
    virtual const char* what() const throw();
};



//------------------------------Реализация класса ошибки---------------------------
memory_alloc_error::memory_alloc_error()
{
}
//------------------------------Реализация класса чтения файла---------------------------
const char* file_read_error::what() const throw()
{
     return "file read  error \n";
}

const char* memory_alloc_error::what() const throw()
{
     return "memory alloc error \n";
}



#endif // MY_EXCEPTION_H
