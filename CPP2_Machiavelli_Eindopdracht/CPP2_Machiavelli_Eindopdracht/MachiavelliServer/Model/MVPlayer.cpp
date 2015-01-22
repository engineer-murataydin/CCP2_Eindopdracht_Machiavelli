#include "MVPlayer.h"
#include "../Controller/MVGame.h"

MVPlayer::MVPlayer(Socket* socket)
{
	this->socket = shared_ptr<Socket>(socket);
}


MVPlayer::~MVPlayer()
{
}



shared_ptr<Socket> MVPlayer::getSocket() const
{
	return socket;
}

bool MVPlayer::HasCharacterCard(int id) const
{
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		if (characterCards[i]->getOrder() == id)
		{
			return true;
		}
	}
	return false;
}

vector<shared_ptr<MVCharacter>> MVPlayer::getCharacterCards() const
{
	return characterCards;
}

void MVPlayer::write(string msg)
{
	try
	{
		socket->write(msg);
	}
	catch (...)
	{
	}
}

bool MVPlayer::addCoin()
{
	if (MVGame::Instance()->hasCoins())
	{
		Coins.push(move(MVGame::Instance()->MoveCoin()));
		return true;
	}
	return false;
}

bool MVPlayer::addCoins(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (!addCoin())
		{
			return false;
		}
	}
	return true;
}

bool MVPlayer::addBuildingCard()
{
	if (MVGame::Instance()->hasBuildingCards())
	{
		BuildingCards.push_back(move(MVGame::Instance()->getBuilding()));
		return true;
	}
	return false;
}

bool MVPlayer::addBuildingCards(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (!addBuildingCard())
		{
			return false;
		}
	}
	return true;
}