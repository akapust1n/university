#include "select.h"

int main(int argc, char **argv)

{
	int	sockfd;
	struct sockaddr_in servaddr;
	struct hostent * host;
	int len;
   
	if (argc != 2) {

		fprintf(stderr, "usage: %s server\n", argv[0]);

		exit(1);

} /* end if */
		host = gethostbyname(argv[1]);
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);
		servaddr.sin_port = htons(SERV_PORT);
		connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
		do {

            write(fileno(stdout),"> ", 3);	/* Prompt the user */

           if ((len=read(fileno(stdin), buf, BUFSIZ)) > 0) {
           	/* Get user input */
               write(sockfd, buf, len); /* Write to socket */
         if ((len=read(sockfd, buf, len)) > 0 ) /* If returned */
            write(fileno(stdout), buf, len);	/* display it. */
		}
    } while( buf[0] != '.' );
     printf("ds%d\n",len);
	close(sockfd);

	exit(0);

}