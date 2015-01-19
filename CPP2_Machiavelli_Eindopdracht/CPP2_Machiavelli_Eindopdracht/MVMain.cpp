// MVMain.cpp : Defines the entry point for the console application.
//

#include "MachiavelliServer\Server\Server.h"
#include "MachiavelliServer/Controller/MVGame.h"
#include <memory>
#include <vld.h>

int main(int argc, char* argv[])
{
	unique_ptr<Server> server(new Server(unique_ptr<MVGame>(new MVGame())));

	//while (true);

	return 0;
}

