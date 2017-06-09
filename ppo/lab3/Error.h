#ifndef ERROR_H
#define ERROR_H
#include <exception>

class BaseError: public std::exception
{
public:
    virtual const char* what() = 0;
};
class OpenError : public BaseError
{
public:
    OpenError();

    const char *what() override;
};

class FileError : public BaseError
{
public:
    FileError();

    const char* what() override;
};

#endif // ERROR_H
