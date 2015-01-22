#pragma once

#include <thread>
#include <iostream>
#include <exception>
#include <memory>
using namespace std;

#include "Socket.h"
#include "Sync_queue.h"
#include "ClientCommand.h"
#include "../Controller/MVGame.h"

namespace socketexample {
	const int tcp_port{ 1080 };
	const std::string prompt{ "> " };
}

class Server
{
public:
	static shared_ptr<Server> Instance();
	~Server();

private:
	Server();
	static shared_ptr<Server> instance;
	static void handle_client(Socket* socket); // this function runs in a separate thread
	static void consume_command(); // runs in its own thread
	static Sync_queue<ClientCommand> queue;

};