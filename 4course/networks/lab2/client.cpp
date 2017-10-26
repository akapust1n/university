#include "arpa/inet.h"
#include "sys/socket.h"
#include "sys/types.h"
#include <cstring>
#include <iostream>
#include <netdb.h>
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
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent* server;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("ERROR opening socket");
		return -1;
	}

	server = gethostbyname(SERVER_ADDRES);
	if (server == NULL) {
		printf("ERROR, no such host\n");
		return -1;
	}
	bzero((char*)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char*)server->h_addr,
	    (char*)&serv_addr.sin_addr.s_addr,
	    server->h_length);

	serv_addr.sin_port = htons(SERVER_PORT);
	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR connecting");
		return -1;
	}

	FILE* file;
	int c = 0;
	std::string text;
	file = fopen("test.txt", "r");
	if (file) {
		while ((c = getc(file)) != EOF)
			text += c;
		fclose(file);
	} else {
		perror("ERROR file open");
		return -4;
	}
	size_t size = text.size();
	char buf[BUFFER];
	for (unsigned int i = 0; i < size; i += BUFFER - 1) {
		bzero(buf, BUFFER);
		for (unsigned int j = 0; (j < BUFFER - 1) && (j < size); j++) {
			buf[j] = text[i + j];
		}
		if (write(sockfd, buf, strlen(buf)) < 0) {
			perror("ERROR writing to socket");
			return -1;
		}
		std::string temp(buf);
		std::cout << buf << std::endl;
		sleep(1);
	}
	close(sockfd);
	return 0;
}