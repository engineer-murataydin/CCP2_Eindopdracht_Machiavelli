#include "MVGame.h"
#include "../Factory/MVMainFactory.h"

bool MVGame::running;

MVGame::MVGame()
{
	running = true;
	for (size_t i = 0; i < 30; i++)
	{
		coins.push_back(unique_ptr<MVCoin>(new MVCoin()));
	}
	players = vector<unique_ptr<MVPlayer>>();
	vector<shared_ptr<MVBuilding>> buildings = MVMainFactory::loadBuildings();
	//vector<shared_ptr<MVCharacter>> characters = MVMainFactory::loadCharacters();
}


MVGame::~MVGame()
{
	running = false;
}

bool MVGame::addPlayer(unique_ptr<MVPlayer> player)
{
	if (players.size() < 2)
	{
		players.push_back(move(player));
		return true;
	}
	return false;
}

bool MVGame::isTurn(shared_ptr<Socket> socket)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->getSocket() == socket)
		{
			return players[i]->HasCharacterCard(turn);
		}
	}
	return false;
}

void MVGame::nextTurn()
{
	turn++;
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->HasCharacterCard(turn))
		{
			//currentPlayerTurn = players[i];
			return;
		}
	}
}

bool MVGame::isRunning()
{
	return running;
}