#include "Error.h"

FileError::FileError(){}

const char *FileError::what()
{
    return "LoaderError::incorrect input file";
}

OpenError::OpenError(){}

const char *OpenError::what()
{
    return "LoaderError::file not open";
}
