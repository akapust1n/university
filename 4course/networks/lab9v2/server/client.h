#ifndef CLIENT_H
#define CLIENT_H
#include "structs.h"
int newClient(int lisneter, int epollFD, struct user* clientsFD, int* numClients);
int handleMessage(struct user* clients, struct epoll_event event, int* count);
#endif // CLIENT_H
