// MVMain.cpp : Defines the entry point for the console application.
//

#include "MachiavelliServer\Server\Server.h"
#include "MachiavelliServer/Controller/MVGame.h"
#include "MachiavelliServer\Enum\MVEnum.h"
#include <memory>
#include <vld.h>
#include <csignal>

void signal_handler(int sig)
{
	MVGame::Instance()->quit(MVEnum::DISCONNECTED);
}

int main(int argc, char* argv[])
{
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGBREAK, signal_handler);


	MVGame::Instance();
	shared_ptr<Server>(new Server());
	MVGame::Instance().reset();

	return 0;
}

