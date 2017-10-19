#include "select.h"

int main(int argc, char** argv)

{

    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char line[MAXLINE];
    socklen_t clilen;

    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;

    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //any port

    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);  //max number connections

    maxfd = listenfd; /* initialize */

    maxi = -1; /* index into client[] array */
    //printf("%d SIZE\n",FD_SETSIZE);

    for (i = 0; i < FD_SETSIZE; i++)

        client[i] = -1; /* -1 indicates available entry */

    FD_ZERO(&allset); //clear new set

    FD_SET(listenfd, &allset);

    for (;;) {

        rset = allset; /* structure assignment */

        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(listenfd, &rset)) { /* new client connection */

            clilen = sizeof(cliaddr);

            connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen); //create connection

            printf("new client connected with fd #%d\n", connfd);

            for (i = 0; i < FD_SETSIZE; i++)

                if (client[i] < 0) {

                    client[i] = connfd; /* save descriptor */

                    break;
                }

            if (i == FD_SETSIZE) {

                perror("too many clients");

                exit(4);

            } /* end if */

            FD_SET(connfd, &allset); /* add new descriptor to set */

            if (connfd > maxfd)

                maxfd = connfd; /* for select */

            if (i > maxi)

                maxi = i; /* max index in client[] array */

            if (--nready <= 0)

                continue; /* no more readable descriptors */
        }

        for (i = 0; i <= maxi; i++) { /* check all clients for data */

            if ((sockfd = client[i]) < 0)

                continue;

            if (FD_ISSET(sockfd, &rset)) {

                if ((n = read(sockfd, line, MAXLINE)) == 0) {

                    /*connection closed by client */

                    printf("connection by a client with fd #%d\n", sockfd);

                    close(sockfd);

                    FD_CLR(sockfd, &allset);

                    client[i] = -1;

                } else

                    printf("The following line echoed to client with fd #%d\n",

                        sockfd);

                write(sockfd, line, n);

                write(1 /*stdout*/, line, n);

                if (--nready <= 0)

                    break; /* no more readable descriptors */
            }
        }
    }
}
