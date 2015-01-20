#include "MVGame.h"
#include "../Factory/MVMainFactory.h"
#include <time.h>
#include "../States/MVGameState.h"
#include "../States/MVLobbyState.h"

bool MVGame::running;
default_random_engine MVGame::dre;
shared_ptr<MVGame> MVGame::instance = nullptr;

shared_ptr<MVGame> MVGame::Instance()
{
	if (!instance)
	{
		new MVGame();
	}
	return instance;
}


MVGame::MVGame()
{
	instance = shared_ptr<MVGame>(this);
	dre = default_random_engine(time(NULL));

	running = true;

	vector<unique_ptr<MVBuilding>> buildings = MVMainFactory::loadBuildings();
	vector<unique_ptr<MVCharacter>> characters = MVMainFactory::loadCharacters();

	for (size_t i = 0; i < buildings.size(); i++)
	{
		buildingDeck.AddCard(move(buildings[i]));
	}

	for (size_t i = 0; i < characters.size(); i++)
	{
		characterDeck.AddCard(move(characters[i]));
	}

	for (size_t i = 0; i < 30; i++)
	{
		coins.push_back(unique_ptr<MVCoin>(new MVCoin()));
	}

	buildingDeck.shuffle();
	characterDeck.shuffle();

	state = unique_ptr<MVGameState>(new MVGameState(instance));

}


MVGame::~MVGame()
{
	running = false;
}

bool MVGame::addPlayer(shared_ptr<MVPlayer> player)
{
	if (players.size() < 2)
	{
		players.push_back(player);
		if (players.size() == 2)
		{
			start();
		}
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

void MVGame::start()
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->write("Begin!!!\n\r");
	}

	uniform_int_distribution<int> dist(0, players.size() - 1);
	players[dist(dre)]->setKing(true);
}

default_random_engine MVGame::getDre()
{
	return dre;
}

void MVGame::quit()
{
	running = false;
}
