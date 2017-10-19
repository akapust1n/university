#define LISTENQ 1024 /* 2nd argument to listen() */

#define MAXLINE 4096 /* max text line length */

#define MAXSOCKADDR 128 /* max socket address structure size */

#define BUFFSIZE 8192 /* buffer size for reads and writes */



/* Define some port number that can be used for client-servers */

#define SERV_PORT 9877 /* TCP and UDP client-servers */

#define SERV_PORT_STR "9877" /* TCP and UDP client-servers */

#define UNIXSTR_PATH "/tmp/unix.str" /* Unix domain stream cli-serv */

#define UNIXDG_PATH "/tmp/unix.dg" /* Unix domain datagram cli-serv */

#include <sys/types.h> /* basic system data types */

#include <sys/socket.h> /* basic socket definitions */

#include <sys/time.h> /* timeval{} for select() */

#include <time.h> /* timespec{} for pselect() */

#include <netinet/in.h> /* sockaddr_in{} and other Internet defns */

#include <arpa/inet.h> /* inet(3) functions */

#include <errno.h>

#include <fcntl.h> /* for nonblocking */

#include <netdb.h>

#include <signal.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/stat.h> /* for S_xxx file mode constants */

#include <sys/uio.h> /* for iovec{} and readv/writev */

#include <unistd.h>

#include <sys/wait.h>

#include <sys/un.h> /* for Unix domain sockets */

static char buf[BUFSIZ]; /* Buffer for messages */