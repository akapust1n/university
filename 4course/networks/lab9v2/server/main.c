#include "client.h"
#include "structs.h"
#include <pthread.h>
#include <time.h>
#include <zdb/zdb.h>

int epollFD;
ConnectionPool_T pool;
int startListen(int port)
{
    int listener;
    if ((listener = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error socker create");
        exit(-ERR_SOCK_CREATE);
    }
    if (fcntl(listener, F_SETFL, fcntl(listener, F_GETFD, 0) | O_NONBLOCK) < 0) {
        perror("Error non block socket");
        exit(-ERR_NON_BLOCK);
    };
    int reuse = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &(reuse), sizeof(int)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        exit(-ERR_REUSEADDR);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listener, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Error socket bind");
        exit(-ERR_SOCK_BIND);
    }
    if (listen(listener, SOMAXCONN) < 0) {
        perror("Socket listen");
        exit(-ERR_SOCK_LISTEN);
    }
    printf("Start listen\n");
    return listener;
}
int createEpoll(int listenFD)
{
    int epollFD;

    if ((epollFD = epoll_create(1)) < 0) {
        perror("Error epoll create");
        exit(-ERR_EPOLL_CREATE);
    }

    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = listenFD;
    if (epoll_ctl(epollFD, EPOLL_CTL_ADD, listenFD, &event) < 0) {
        perror("Epoll fd add");
        exit(-ERR_EPOLL_ADD);
    }
    return epollFD;
}
void timer(void* arg)
{
    float TIMEOUT = 0.5;
    printf("start\n");
    struct user* clientsFD = (struct user*)arg;

    do {
        sleep(2);

        for (int i = 0; i < 11; i++) {
            int fd = clientsFD[i].fd;
            if (fd)
                printf("\n%d fd\n", fd);
            // printf("%d", clientsFD[i].m_context);
            if (clientsFD[i].m_context) {

                float diff = ((float)(clock() - clientsFD[i].m_context->lastModification)) * 1000 / CLOCKS_PER_SEC;
                printf("%f\n diff", diff);
                if (diff > TIMEOUT) {
                    shutdown(clientsFD[i].fd, SHUT_WR);

                    // closeSocket(clientsFD[i].fd, "bye");
                    //  epoll_ctl(epollFD, EPOLL_CTL_DEL, clientsFD[i].fd, 0);
                }
            }
        }
        printf("end\n");
    } while (1);
};
int main(int argc, char* argv[])
{
    int listener = startListen(PORT);
    int epollFD = createEpoll(listener);
    bd = (struct bdID*)malloc(sizeof(struct bdID) * 10);
    URL_T url = URL_new("mysql://localhost/lab9?user=root&password=1111");

    pool = ConnectionPool_new(url);
    ConnectionPool_start(pool);
    epollFD = createEpoll(listener);
    ResultSet_T result;
    Connection_T con = ConnectionPool_getConnection(pool);

    result = Connection_executeQuery(con, "SELECT fd  from Users LIMIT 10");
    int i = 0;
    while (ResultSet_next(result)) {
        bd[i].isFree = true;
        bd[i++].uniq = ResultSet_getString(result, 1);
    }

    struct epoll_event events[NUM_EVENTS];
    struct user* clientsFD = (struct user*)malloc(sizeof(struct user) * MAX_CLIENTS);
    int numFD, numClients = 0;
    pthread_t handle;
    if (!pthread_create(&handle, NULL, timer, (void*)clientsFD)) {
        printf("Thread create successfully !!!\n");
        if (!pthread_detach(handle))
            printf("Thread detached successfully !!!\n");
    }
    while (1) {

        if ((numFD = epoll_wait(epollFD, events, NUM_EVENTS, -1)) < 0) {
            perror("Error epoll_wait");
            // exit(-9);
        }
        for (int i = 0; i < numFD; i++) {
            if (events[i].data.fd == listener) {
                if (newClient(listener, epollFD, clientsFD, &numClients) < 0) {
                    perror("Can create new client!");
                }
            } else {
                if (handleMessage(clientsFD, events[i], &numClients) < 0) {
                    perror("Canе handle message!");
                }
            }
        }
    }
}
