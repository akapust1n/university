#ifndef STRUCTS_H
#define STRUCTS_H
#include "cyclobuffer.h"
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define NUM_EVENTS 5000
#define PORT 8080
#define MAX_CLIENTS 150
#define MAX_CLIENTS2 10
#define MSG_SIZE 1024
#define CYCLOBUF_SIZE MSG_SIZE * 5
#define LOGFILE "logfile"

enum errors {
    ERR_SOCK_CREATE = 1,
    ERR_NON_BLOCK,
    ERR_REUSEADDR,
    ERR_SOCK_BIND,
    ERR_SOCK_LISTEN,
    ERR_EPOLL_CREATE,
    ERR_ACCEPT_CLIENT,
    ERR_EPOLL_ADD,
    ERR_SOCK_READ,
    ERR_READ_MSG,
    ERR_SOCK_CLOSE
};
struct bdID {
    char* uniq;
    bool isFree;
};
struct context {
    bool writable;
    int fd;
    struct bdID* bd;
    clock_t lastModification;
    struct cycloBuffer* buffer;
};
struct user {
    int fd;
    struct context* m_context;
};
int globNumClients;

struct bdID* bd;
#endif // STRUCTS_H
