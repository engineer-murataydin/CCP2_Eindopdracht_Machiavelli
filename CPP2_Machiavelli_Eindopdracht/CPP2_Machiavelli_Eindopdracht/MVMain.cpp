// MVMain.cpp : Defines the entry point for the console application.
//

#include "MachiavelliServer\Server\Server.h"
#include "MachiavelliServer/Controller/MVGame.h"
#include <memory>
#include <vld.h>

BOOL WINAPI ConsoleHandler(DWORD CEvent)
{
	MVGame::Instance()->quit();
	return TRUE;
}

int main(int argc, char* argv[])
{
	SetConsoleCtrlHandler(ConsoleHandler, true);

	unique_ptr<Server> server(new Server(MVGame::Instance()));

	//while (true);

	return 0;
}

