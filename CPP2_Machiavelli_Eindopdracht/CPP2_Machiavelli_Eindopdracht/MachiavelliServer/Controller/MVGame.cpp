#include "MVGame.h"
#include "../Factory/MVMainFactory.h"
#include <time.h>
#include "../States/MVGameState.h"
#include "../States/GameStates/MVLobbyState.h"
#include "../Enum/MVEnum.h"

bool MVGame::running = true;
default_random_engine MVGame::dre;
shared_ptr<MVGame> MVGame::instance = nullptr;

shared_ptr<MVGame> MVGame::Instance()
{
	if (running)
	{
		if (!instance)
		{
			new MVGame();
		}
		return instance;
	}
	return shared_ptr<MVGame>();
}


MVGame::MVGame()
{
	instance = shared_ptr<MVGame>(this);
	dre = default_random_engine(time(0)); //NULL

	vector<shared_ptr<MVBuilding>> buildings = MVMainFactory::loadBuildings();
	vector<shared_ptr<MVCharacter>> characters = MVMainFactory::loadCharacters();

	for (size_t i = 0; i < buildings.size(); i++)
	{
		buildingDeck.AddCard(buildings[i]);
	}

	for (size_t i = 0; i < characters.size(); i++)
	{
		characterDeck.AddCard(move(characters[i]));
	}

	for (size_t i = 0; i < 30; i++)
	{
		coins.push(unique_ptr<MVCoin>(new MVCoin()));
	}

	state = unique_ptr<MVGameState>(new MVLobbyState(instance));
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
		return true;
	}
	return false;
}

bool MVGame::isRunning()
{
	return running;
}

void MVGame::start()
{
	shuffleCharacterDeck();
	shuffleBuildingDeck();

	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->addCoins(2);
		players[i]->addBuildingCards(4);
		players[i]->writeLine(MVEnum::messageToString(MVEnum::CONNECTED_PLAYER));
		players[i]->writeLine(MVEnum::messageToString(MVEnum::READY_GAME));
		players[i]->writeLine(MVEnum::messageToString(MVEnum::BUILDING_CARDS_SHUFFLED));
	}

	uniform_int_distribution<int> dist(0, players.size() - 1);
	king = players[dist(dre)];
}

default_random_engine MVGame::getDre()
{
	return dre;
}

void MVGame::quit(MVEnum::Messages message)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->writeLine(MVEnum::messageToString(message));
	}
	running = false;
}

vector<shared_ptr<MVPlayer>> MVGame::getPlayers()
{
	return players;
}

void MVGame::setState(shared_ptr<MVGameState> state)
{
	this->state->onExit();
	this->state = move(state);
	this->state->onEnter();
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

shared_ptr<MVBuilding> MVGame::getBuilding()
{
	return buildingDeck.moveTopCard();
}

shared_ptr<MVCharacter> MVGame::getCharacter(int pos)
{
	return characterDeck.moveCardAt(pos);
}

void MVGame::setBuildingCard(shared_ptr<MVBuilding>card)
{
	usedBuildingDeck.AddCard(card);
}

void MVGame::setCharacterCard(shared_ptr<MVCharacter>card)
{
	usedCharacterDeck.AddCard(card);
}

void MVGame::checkPlayers()
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->getSocket()->get() <= 0)
		{
			quit(MVEnum::DISCONNECTED_PLAYER);
			break;
		}
	}
}

shared_ptr<MVPlayer> MVGame::getPlayer(MVEnum::Characters character)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->HasCharacterCard(character))
		{
			return players[i];
		}
	}
	return shared_ptr<MVPlayer>();
}

bool MVGame::isCurrentPlayer(shared_ptr<MVPlayer> player)
{
	return state->isCurrentPlayer(player);
}

void MVGame::characterKilled(MVEnum::Characters character)
{
	killed = character;
}

void MVGame::characterStolen(MVEnum::Characters character)
{
	stolenFrom = character;
}

shared_ptr<MVPlayer> MVGame::getKing()
{
	return king;
}

void MVGame::shuffleCharacterDeck()
{
	characterDeck.shuffle();
}

void MVGame::shuffleBuildingDeck()
{
	buildingDeck.shuffle();
}

MVDeck<MVCharacter> MVGame::getCharacterDeck()
{
	return characterDeck;
}

shared_ptr<MVGameState> MVGame::getState()
{
	return state;
}

void MVGame::restart()
{
	instance.reset(new MVGame());
}

shared_ptr<MVPlayer> MVGame::getOtherPlayer(shared_ptr<MVPlayer> player)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i] != player)
		{
			return players[i];
		}
	}
}