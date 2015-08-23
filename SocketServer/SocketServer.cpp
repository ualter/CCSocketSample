// SocketServer.cpp : Defines the entry point for the console application.
//
#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <tchar.h>

#define BUFLEN 512

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen;
	char buf[BUFLEN];
	WSADATA wsa;

	slen = sizeof(si_other);

	int ret = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (ret != 0) {
		printf("Error WSAStartup failed: " + WSAGetLastError());   
		WSACleanup();
	}

	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s == INVALID_SOCKET) {
		printf("Error opening socket: " + WSAGetLastError());
	}

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8881);

	// Bind
	ret = bind(s, (struct sockaddr *)&server, sizeof(server));
	if (ret < 0) {
		printf("Bind failed: " + WSAGetLastError());
	}
	

	std::stringstream sstm;
	// Receiving
	while (1) {
		printf("Listening por 8881...\n");

		memset(buf, '\0', BUFLEN);

		ret = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);
		if (ret < 0) {
			printf("Error receving failed: " + WSAGetLastError());
		}
		sstm << "Received: " << buf << "\n";
		printf(sstm.str().c_str());
		sstm.str("");
	}

	closesocket(s);
	WSACleanup();

	exit(0);
	return 0;
}

