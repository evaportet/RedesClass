#include "Chat.h"
#include <thread>
#include <iostream>
#include "ConsoleControl.h"

void Chat::ShowMessage(std::string message)
{
	_messagesMutex.lock();
	_messages.push_back(message);
	_messagesMutex.unlock();

	ConsoleControl::LockMutex();
	std::cout << std::endl << message;
	ConsoleControl::UnlockMutex();

}

void Chat::ShowWarning(std::string message)
{
	ConsoleControl::LockMutex();
	ConsoleControl::SetColor(ConsoleControl::RED);
	std::cout << std::endl << message;
	ConsoleControl::SetColor(ConsoleControl::WHITE);
	ConsoleControl::UnlockMutex();
}

void Chat::ShowError(std::string message)
{
	ConsoleControl::LockMutex();
	ConsoleControl::SetColor(ConsoleControl::YELLOW);
	std::cout << std::endl << message;
	ConsoleControl::SetColor(ConsoleControl::WHITE);
	ConsoleControl::UnlockMutex();
}

void Chat::ListenClientsConnections(unsigned short port)
{
	sf::TcpListener listener;

	if (listener.listen(3000) != sf::Socket::Done)
	{
		std::cout << "Error on start listener" << std::endl;
		return;
	}

	sf::IpAddress ipAddress = sf::IpAddress::getLocalAddress();
	std::cout << "Listening on IP: " + ipAddress.toString() << std::endl;

	sf::TcpSocket client;

	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cout << "Error on accept Client" << std::endl;
		return;
	}
}

Chat* Chat::Server(unsigned short port)
{
	Chat* chat = new Chat();
	chat->_serverAddress = sf::IpAddress::getLocalAddress();



	return chat;
}

Chat* Chat::Client(std::string i, unsigned short port)
{
	Chat* chat = new Chat();



	return chat;
}
