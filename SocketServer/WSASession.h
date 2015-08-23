#pragma once
class WSASession
{
public:
	WSASession()
	{
		int ret = WSAStartup(MAKEWORD(2, 2), &data);
		if (ret != 0)
			printf("WSAStartup Failed");
	}
	~WSASession()
	{
		WSACleanup();
	}
};

