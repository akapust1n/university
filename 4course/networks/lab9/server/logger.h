#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
void openLog();
void closeLog();
void writeLog(int author, const char* message);

#endif // LOGGER_H
