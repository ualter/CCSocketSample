// SocketClient.cpp : Defines the entry point for the console application.
//

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include "SocketClient.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SocketClient so = SocketClient("192.168.0.179");
	so.sendTo("Hello from C++  111");
	so.sendTo("Hello from C++  222");
	so.~SocketClient();

	/*WSAData data;
	SOCKET sock;
	struct sockaddr_in si_other;
	const std::string address = "192.168.0.179";
	int slen = sizeof(si_other);
	char message[512] = "Hello World Java, I am a C++ Client Socket";

	int ret = WSAStartup(MAKEWORD(2, 2), &data);
	if (ret != 0) {
		printf("Error WSAStartup failed: " + WSAGetLastError());
		WSACleanup();
	}

	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock == INVALID_SOCKET) {
		printf("Error opening socket: " + WSAGetLastError());
	}

	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(8881);
	si_other.sin_addr.S_un.S_addr = inet_addr(address.c_str());
	
	std::stringstream sstm;
	for (int i = 0; i < 10; i++) {
		sstm << "Attemp #" << i << " - Sending:" << message << "\n";
		printf(sstm.str().c_str());
		ret = sendto(sock, message, strlen(message), 0, (struct sockaddr *) &si_other, slen);
		if (ret < 0) {
			sstm << "Failed Sending:" << WSAGetLastError();
		}
		sstm.str("");
	}

	printf("\n *** End ***");
	std::getchar();
	exit(0);

	closesocket(sock);
	WSACleanup();  */

	return 0;
}

