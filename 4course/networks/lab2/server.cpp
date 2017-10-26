#include "arpa/inet.h"
#include "sys/socket.h"
#include "sys/types.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <string>
#include <strings.h>
#include <zconf.h>

#define SERVER_PORT 8080
#define SERVER_ADDRES "localhost"
#define BUFFER 100

int main(int argc, char* argv[])
{
	int sockfd, newsockfd;
	socklen_t clilen;

	struct sockaddr_in serv_addr, cli_addr;
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("ERROR opening socket");
		return -1;
	}
	bzero((char*)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(SERVER_PORT);

	if (bind(sockfd, (struct sockaddr*)&serv_addr,
	        sizeof(serv_addr))
	    < 0) {
		perror("ERROR on binding");
		return -2;
	}

	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,
	    (struct sockaddr*)&cli_addr, &clilen);
	if (newsockfd < 0) {
		perror("ERROR on accept");
		return -3;
	}

	printf("server: got connection from %s port %d\n",
	    inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

	std::string text;

	while (true) {
		char buffer[BUFFER];
		bzero(buffer, BUFFER);
		if (read(newsockfd, buffer, BUFFER - 1) < 0) {
			perror("ERROR reading from socket");
			return -3;
		}
		if (strlen(buffer) != 0) {
			text.append(buffer);
			std::cout << text << std::endl;
		}
	}
}