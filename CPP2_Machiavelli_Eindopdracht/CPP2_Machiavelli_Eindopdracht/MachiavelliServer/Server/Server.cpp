#include "Server.h"

Sync_queue<ClientCommand> Server::queue;

void Server::consume_command() // runs in its own thread
{
	try
	{
		shared_ptr<MVGame> game = MVGame::Instance();
		while (MVGame::isRunning()) {
			ClientCommand command;
			queue.get(command); // will block here unless there still are command objects in the queue
			shared_ptr<Socket> client{ command.get_client() };

			if (client) {
				try {
					// TODO handle command here
					if (game->isCurrentPlayer(game->getPlayer(client)))
					{
						game->update(game->getPlayer(client), command.get_cmd());
					}
					else
					{
						client->write("Niet jouw beurt!\n\r");
					}

					game->render(game->getPlayer(client));
				}
				catch (const exception& ex) {
					client->write("Sorry, ");
					client->write(ex.what());
					client->write("\n");
				}
				catch (...) {
					client->write("Sorry, er ging iets mis! ;)\n\r");
				}
				client->write(socketexample::prompt);
			}
			else {
				cerr << "trying to handle command for client who has disappeared...\n";
			}
		}
	}
	catch (...) {}
}

void Server::handle_client(Socket* socket) // this function runs in a separate thread
{
	shared_ptr<Socket> client{ socket };
	while (MVGame::isRunning()) { // game loop

		shared_ptr<MVGame> game(MVGame::Instance());
		game->checkState();

		try {
			// read first line of request
			string cmd = client->readline();
			cerr << "client (" << client->get() << ") said: " << cmd << '\n';

			if (cmd == "quit") {
				client->write("Bye!\n\r");
				break; // out of game loop, will end this thread and close connection
			}
			game->checkState();
			ClientCommand command{ cmd, client };
			queue.put(command);

		}
		catch (...) {}
	}
}

Server::~Server()
{
	//TODO
}

Server::Server()
{
	// start command consumer thread
	thread consumer{ consume_command };
	consumer.detach(); // detaching is usually ugly, but in this case the right thing to do

	// create a server socket
	ServerSocket server(socketexample::tcp_port);
	shared_ptr<MVGame> game = MVGame::Instance();
	while (game->isRunning()) {
		try {
			// wait for connection from client; will create new socket
			cerr << "server listening" << '\n';
			Socket* client = nullptr;

			while (game->isRunning() && game->getPlayers().size() <= 2 && (client = server.accept()) != nullptr) {

				// communicate with client over new socket in separate thread
				if (game->addPlayer(shared_ptr<MVPlayer>(new MVPlayer(client))))
				{
					thread handler{ handle_client, client };
					handler.detach(); // detaching is usually ugly, but in this case the right thing to do
				}
				cerr << "server listening again" << '\n';
			}
		}
		catch (const exception& ex) {
			cerr << ex.what() << ", resuming..." << '\n';
		}
	}
}