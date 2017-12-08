#ifndef CLIENT_H
#define CLIENT_H
#include "structs.h"
int newClient(int lisneter, int epollFD, struct user* clientsFD, int* numClients, struct bdID* bd);
int handleMessage(struct user* clients, struct epoll_event event, int* count);
void removeClient(struct user* clients, int authorSock, int* count, struct epoll_event event, bool onlyRemove);
int closeSocket(int socket, char* msg);

#endif // CLIENT_H
