#include <arpa/inet.h>
#include <array>
#include <bitset>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

typedef std::array<int, 4> array_s;

std::vector<array_s> ip;
int toInt(char* buffer, int len)
{
	int rank = 1;
	int result = 0;
	for (int i = len - 1; i >= 0; i--) {
		result += ((int)(buffer[i] - '0')) * rank;
		rank *= 10;
	}
	return result;
}
void readfile(std::string filename)
{
	std::ifstream file(filename);
	std::string adress;
	std::string delimiter = ".";
	std::string token;

	size_t pos = 0;

	while (std::getline(file, adress)) {
		array_s adressStruct;
		int counter = 0;
		while ((pos = adress.find(delimiter)) != std::string::npos) {
			token = adress.substr(0, pos);
			adressStruct[counter] = std::stoi(token);
			counter++;
			adress.erase(0, pos + delimiter.length());
		}
		adressStruct[counter] = std::stoi(adress);
		ip.push_back(adressStruct);
	};
}
std::string convert(array_s adress, bool isHex)
{
	std::string result;
	for (auto adr : adress) {
		//std::string binary = std::bitset<9>(128).to_string(); //to binary

		std::string number;
		std::stringstream ss;
		if (isHex) {
			ss << std::hex << adr;
		} else {
			ss << std::oct << adr;
		}
		ss >> number;
		std::cout << number << "HEX" << std::endl;
		result += number + ".";
	}
	result.pop_back(); //remove last .
	return result;
}
std::string toBinary(array_s adress)
{
	std::string result = "128";
	for (auto adr : adress) {
		std::string temp = std::bitset<32>(adr).to_string();
		if (result.find("1", 0) != std::string::npos) {
			temp.substr(result.find("1", 0));
		} else {
			temp = "0";
		}
		result += temp + ".";
	}
	result.pop_back(); //remove last .
	return result;
}
int main(int argc, char* argv[])
{
	//техническая информация
	int SERVER_PORT = 8876;

	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;

	server_address.sin_port = htons(SERVER_PORT);

	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	int sock;
	if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("could not create socket\n");
		return 1;
	}
	if ((bind(sock, (struct sockaddr*)&server_address,
	        sizeof(server_address)))
	    < 0) {
		printf("could not bind socket\n");
		return 1;
	}

	struct sockaddr_in client_address;
	int client_address_len = 0;
	//------------
	//read file
	readfile("ip");
	std::cout << convert(ip[1], true);

	while (true) {
		char buffer[150];
		std::cout << "label__" << std::endl;
		int len = recvfrom(sock, buffer, sizeof(buffer), 0,
		    (struct sockaddr*)&client_address,
		    (socklen_t*)&client_address_len);

		// ip address
		buffer[len] = '\0';
		printf("hey %d", toInt(buffer, len));

		printf("received: '%s' from client %s\n", buffer,
		    inet_ntoa(client_address.sin_addr));
		int number = toInt(buffer, len);
		std::string result;
		if (number > (ip.size() - 1)) {
			std::strcpy(buffer, "too big number");

		} else {
			result += convert(ip[number], true) + '\n' + convert(ip[number], false) + '\n' + toBinary(ip[number]);
			std::strcpy(buffer, result.c_str());
		}
		sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&client_address,
		    sizeof(client_address));

		printf("%s", buffer);

		printf("after print");
	}

	return 0;
}