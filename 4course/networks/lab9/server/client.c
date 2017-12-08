#include "client.h"
#include "logger.h"

void setWritable(int fd, struct user* clients, int count);
int writeToBuffer(char* msg, struct epoll_event event);
int handleNoone(int authorSock, char* message);
int handleEpollin(int authorSock, char* message);
int sendOthers(struct user* clients, struct epoll_event event, int* count, char* message);
struct bdID* getFD(struct bdID* bd)
{
    for (int i = 0; i < 10; i++) {
        if (bd[i].isFree) {
            bd->isFree = false;
            return &bd[i];
        }
    }
    return 0;
}
int closeSocket(int socket, char* msg)
{
    //send(socket, msg, strlen(msg), 0);
    shutdown(socket, SHUT_WR);
    char buffer[1000];
    for (;;) {
        int res = read(socket, buffer, 1000);
        if (res < 0) {
            perror("Error read from socket");
            return ERR_SOCK_READ;
        }
        if (!res)
            break;
    }
    printf("before close\n");
    close(socket);
    return 0;
}

int newClient(int listener, int epollFD, struct user* clientsFD, int* numClients, struct bdID* bd)
{
    printf("NEW client\n");

    struct epoll_event event;
    socklen_t addrlen;
    event.events = EPOLLOUT | EPOLLIN | EPOLLRDHUP | EPOLLET;

    struct sockaddr clientaddr;
    int newClientSocket;
    if ((newClientSocket = accept(listener, (struct sockaddr*)&clientaddr, &addrlen)) < 0) {
        perror("Error accept client");
        return -ERR_ACCEPT_CLIENT;
    }
    if (fcntl(newClientSocket, F_SETFL, fcntl(newClientSocket, F_GETFD, 0) | O_NONBLOCK) < 0) {
        perror("Error non block socket");
        return -ERR_NON_BLOCK;
    };
    int reuse = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &(reuse), sizeof(int)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        return -ERR_REUSEADDR;
    }
    if ((*numClients + 1) < MAX_CLIENTS) {
        // event.data.fd = newClientSocket;
        event.data.ptr = (struct context*)malloc(sizeof(struct context));
        ((struct context*)event.data.ptr)->fd = newClientSocket;
        if (epoll_ctl(epollFD, EPOLL_CTL_ADD, newClientSocket, &event) < 0) {
            perror("Error epoll add");
            return -ERR_EPOLL_ADD;
        };
        if (numClients > MAX_CLIENTS2) {
            closeSocket(newClientSocket, "bye");
        }
        struct user temp = { .fd = newClientSocket, .m_context = event.data.ptr };
        temp.m_context->buffer = (struct cycloBuffer*)malloc(sizeof(struct cycloBuffer));
        temp.m_context->buffer->buffer = (char*)malloc(sizeof(char) * MSG_SIZE);
        temp.m_context->lastModification = clock();
        temp.m_context->bd = getFD(bd);
        // temp.m_context->uniq
        bzero(temp.m_context->buffer->buffer, MSG_SIZE);
        const char* heello = "hello";
        memmove(temp.m_context->buffer->buffer, heello, strlen(heello));
        temp.m_context->buffer->capacity = MSG_SIZE;
        clientsFD[*numClients] = temp;
        *numClients += 1;
        int sentBytes = 0;
        char* msg = "Hello\n";
        int len = strlen(msg);
        while (sentBytes < len) {
            sentBytes += send(clientsFD[*numClients - 1].fd, msg + sentBytes, len - sentBytes, 0);
            if (sentBytes == -1)
                break;
        }

    } else {
        closeSocket(newClientSocket, "cant add client");
    }
    return 0;
}

void removeClient(struct user* clients, int authorSock, int* count, struct epoll_event event, bool onlyRemove)
{

    int i = 0;
    for (; i < *count && clients[i].fd != authorSock; i++)
        ;

    if (i == *count)
        return -1;
    if (event.data.ptr)
        free(event.data.ptr);

    if (((struct context*)event.data.ptr)->buffer->buffer)
        free(((struct context*)event.data.ptr)->buffer->buffer);
    ((struct context*)event.data.ptr)->bd->isFree = true;
    //    if (((struct context*)event.data.ptr)->buffer)
    //        free(((struct context*)event.data.ptr)->buffer);
    printf("call remove\n");
    printf("%d i\n", i);
    if (!onlyRemove)
        closeSocket(authorSock, "bye");
    memmove(clients + i, clients + i + 1, sizeof(struct user) * ((*count) - i));
    *count -= 1;
}

int handleMessage(struct user* clients, struct epoll_event event, int* count)
{
    printf("HANDLE MESSAGE \n");
    int authorSock = ((struct context*)event.data.ptr)->fd;

    if (event.events & EPOLLRDHUP || event.events & EPOLLHUP || event.events & EPOLLERR) {
        removeClient(clients, authorSock, count, event, false);
        return 0;
    }
    printf("%d parent count \n", *count);
    printf("%d why \n", clients[0].m_context);

    char message[MSG_SIZE];
    bzero(message, MSG_SIZE);
    int len;
    struct context* temp = (struct context*)event.data.ptr;
    temp->lastModification = clock();

    if (event.events & EPOLLIN) {
        if ((len = handleEpollin(authorSock, message)) < 1 && errno != EAGAIN && errno != EWOULDBLOCK) {
            removeClient(clients, authorSock, count, event, false);
            return 0;
        }
        message[len] = '\0';
    }
    if (event.events & EPOLLOUT) {
        printf("EPOLLOUT \n");
        setWritable(authorSock, clients, *count);
    }

    return len;
}
void setWritable(int fd, struct user* clients, int count)
{
    for (int i = 0; i < count; i++) {
        if (clients[i].fd == fd) {
            clients[i].m_context->writable = true;
            break;
        }
    }
}

int handleEpollin(int authorSock, char* message)
{

    int recvBytes = 0;
    int numBytes = 0;
    while (recvBytes < MSG_SIZE - 2) { //можно сразу писать в кольцевой буфер
        numBytes = recv(authorSock, message + recvBytes, MSG_SIZE - recvBytes, 0);
        if (numBytes < 1) {
            break;
        }
        recvBytes += numBytes;
    }
    return recvBytes;
}
int sendOthers(struct user* clients, struct epoll_event event, int* count, char* message)
{
    int authorSock = ((struct context*)event.data.ptr)->fd;
    for (int i = 0; i < *count; i++) {
        if (clients[i].fd != authorSock) {
            append(clients[i].m_context->buffer, message, strlen(message));
            int sentBytes = 0;
            int numBytes = 0;
            char msg[MSG_SIZE];
            bzero(msg, MSG_SIZE);
            getData(clients[i].m_context->buffer, msg, MSG_SIZE);
            int len = strlen(msg);
            while (((struct context*)clients[i].m_context)->writable && sentBytes < len) { //while writable
                numBytes = send(clients[i].fd, msg + sentBytes, len - sentBytes, 0);
                if (numBytes != -1) {
                    sentBytes += numBytes;
                } else {
                    if (errno == EAGAIN || errno == EWOULDBLOCK)
                        ((struct context*)event.data.ptr)->writable = false;
                }
            }
            moveHead(clients[i].m_context->buffer, sentBytes);
            //  flush(clients[i].m_context);
        }
    }
    return 0;
}
