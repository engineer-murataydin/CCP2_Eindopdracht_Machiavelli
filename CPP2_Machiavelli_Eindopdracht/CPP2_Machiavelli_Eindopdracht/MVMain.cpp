// MVMain.cpp : Defines the entry point for the console application.
//

#include "MachiavelliServer\Server\Server.h"
#include "MachiavelliServer/Controller/MVGame.h"
#include "MachiavelliServer\Enum\MVEnum.h"
#include <memory>
#include <vld.h>

BOOL WINAPI ConsoleHandler(DWORD CEvent)
{
	MVGame::Instance()->quit(MVEnum::DISCONNECTED);
	return TRUE;
}

int main(int argc, char* argv[])
{
	SetConsoleCtrlHandler(ConsoleHandler, true);

	shared_ptr<Server> server(Server::Instance());

	//while (true);

	return 0;
}

