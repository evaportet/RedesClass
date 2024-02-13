#pragma once
#include <string>
#include <mutex>
#include <SFML/Network.hpp>
#include <vector>
#include <list>
#include "ConsoleControl.h"


class Chat
{
private:
	bool _isServer = false;
	std::mutex _isServerMutex;

	std::list<sf::TcpSocket*> _sockets;
	std::mutex _socketsMutex;

	std::vector<std::string> _messages;
	std::mutex _messagesMutex;

	sf::IpAddress _serverAddress;

	Chat() {};

	void ShowMessage(std::string message);
	void ShowAlert(std::string message);
	void ShowError(std::string message);

	void ListenClientsConnections(unsigned short port);
	void ConnectToServer(std::string ip, unsigned short port);

	void OnClientEnter(sf::TcpSocket* client);
	void ListenMessages(sf::TcpSocket* socket);
	void ListenKeyboardToSendMessage();
	void SendMessage(std::string message);
public:

	static Chat* Server(unsigned short port);
	static Chat* Client(std::string ip, unsigned short port);
};

