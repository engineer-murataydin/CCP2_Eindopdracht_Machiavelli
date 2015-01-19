#include "MVGame.h"

MVGame::MVGame()
{
	for (size_t i = 0; i < 30; i++)
	{
		coins.push_back(unique_ptr<MVCoin>(new MVCoin()));
	}
}


MVGame::~MVGame()
{
}

bool MVGame::addPlayer(MVPlayer* player)
{
	if (players.size() < 2)
	{
		players.push_back(shared_ptr<MVPlayer>(player));
		return true;
	}
	return false;
}

bool MVGame::isTurn(shared_ptr<Socket> socket)
{
	return players.front()->getSocket() == socket;
}
