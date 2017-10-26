#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	const char* server_name = "localhost";
	const int server_port = 8876;

	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;

	//записываем имя сервера в sin_addr
	inet_pton(AF_INET, server_name, &server_address.sin_addr);

	server_address.sin_port = htons(server_port);

	int sock;
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("could not create socket\n");
		return 1;
	}
	if (argc < 2) {
		printf("Must pass an argument!\n");
		return -1;
	}
	const char* data_to_send = argv[1];

	int len = sendto(sock, data_to_send, strlen(data_to_send), 0,
	    (struct sockaddr*)&server_address, sizeof(server_address));

	char buffer[150];
	len = 149;
	recvfrom(sock, buffer, len, 0, NULL, NULL);

	buffer[len] = '\0';
	printf("recieved: '%s'\n", buffer);

	close(sock);
	return 0;
}