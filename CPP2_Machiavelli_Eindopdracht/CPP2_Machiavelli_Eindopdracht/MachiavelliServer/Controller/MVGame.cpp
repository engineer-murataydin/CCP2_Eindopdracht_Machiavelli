#include "MVGame.h"
#include "../Factory/MVMainFactory.h"
#include <time.h>
#include "../States/MVGameState.h"
#include "../States/GameStates/MVLobbyState.h"
#include "../Enum/MVEnum.h"

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
		coins.push(unique_ptr<MVCoin>(new MVCoin()));
	}

	buildingDeck.shuffle();
	characterDeck.shuffle();

	state = unique_ptr<MVGameState>(new MVLobbyState(instance));
}

MVGame::~MVGame()
{
	running = false;
}

bool MVGame::addPlayer(shared_ptr<MVPlayer> player)
{
	if (players.size() == 0)
	{
		currentPlayerTurn = player;
	}
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
	return getPlayer(socket) == currentPlayerTurn;
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
		players[i]->addCoins(2);
		players[i]->addBuildingCards(4);
	}

	uniform_int_distribution<int> dist(0, players.size() - 1);
	players[dist(dre)]->setKing(true);
}

default_random_engine MVGame::getDre()
{
	return dre;
}

void MVGame::quit(MVEnum::Messages message)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->write(MVEnum::messageToString(message));
	}
	/*shared_ptr<MVGame> mvgame(new MVGame());
	Instance().swap(mvgame);*/
	running = false;
}

shared_ptr<MVPlayer> MVGame::getCurrentPlayer()
{
	return currentPlayerTurn;
}

vector<shared_ptr<MVPlayer>> MVGame::getPlayers()
{
	return players;
}

void MVGame::setState(unique_ptr<MVGameState> state)
{
	this->state = move(state);
}
void MVGame::update(shared_ptr<MVPlayer> player, string msg)
{
	state->update(player, msg);
}

void MVGame::render(shared_ptr<MVPlayer> player) const
{
	state->render(player);
}

void MVGame::checkState()
{
	state->checkState();
}

shared_ptr<MVPlayer> MVGame::getPlayer(shared_ptr<Socket> socket) const
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->getSocket() == socket)
		{
			return players[i];
		}
	}
	return nullptr;
}

unique_ptr<MVCoin> MVGame::MoveCoin()
{
	unique_ptr<MVCoin> coin(move(coins.front()));
	coins.pop();
	return coin;
}


bool MVGame::hasCoins()
{
	return !coins.empty();
}

bool MVGame::hasBuildingCards()
{
	return buildingDeck.HasCard();
}

unique_ptr<MVBuilding> MVGame::MoveBuilding(int pos)
{
	return buildingDeck.moveCardAt(pos);
}

unique_ptr<MVCharacter> MVGame::MoveCharacter(int pos)
{
	return characterDeck.moveCardAt(pos);
}

void MVGame::checkPlayers()
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->getSocket()->get() <= 0)
		{
			quit(MVEnum::DISCONNECTED_PLAYER);
		}
	}
}
