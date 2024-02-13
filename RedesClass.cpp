#include <iostream>
#include <conio.h>
#include <SFML/Network.hpp>

#include "Chat.h"


void RunClient();
void RunServer();

short port = 3000;

	int main()
	{
		std::cout << "Select" << std::endl << "Client -> C" << std::endl << "Server -> S" << std::endl;

		char mode = ' ';

		do
		{
			mode = ConsoleControl::WaitForReadNextChar();

		} while (mode != 'C' && mode != 'c' && mode != 'S' && mode != 's');

		switch (mode)
		{
		case 'c':
		case 'C':
		{
			RunClient();
		}
		break;
		case's':
		case 'S':
		{
			RunServer();
		}
		break;
		default:
			break;
		}
		while (true)
		{

		}
	}

	void RunClient()
	{
		std::cout << "Client";

		std::cout << std::endl << "Set server IP -->";

		std::string ip;
	std:getline(std::cin, ip);

		Chat* chat = Chat::Client(ip, port);
	}

	void RunServer()
	{
		std::cout << "Server" << std::endl;

		Chat* chat = Chat::Server(port);
	}
