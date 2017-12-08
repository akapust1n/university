#include "logger.h"
#include "string.h"
#include "structs.h"
#include <errno.h>
#include <time.h>
#include <unistd.h>

static int logger;
void openLog()
{
    logger = open(LOGFILE, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU | S_IRWXG);
}

void writeLog(int author, const char* message)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int len = strlen(message) + 30;
    char buf[len];
    bzero(buf, len);

    snprintf(buf, len, "\n%s %d : %s ", asctime(timeinfo), author, message);
    write(logger, buf, len);
}
void closeLog()
{
    close(logger);
}
