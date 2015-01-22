#include "MVPlayer.h"
#include "../Controller/MVGame.h"
#include <sstream>

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

bool MVPlayer::HasCharacterCard(MVEnum::Characters id) const
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

void MVPlayer::writeLine(string msg)
{
	stringstream s;
	s << msg << "\n\r";
	write(s.str());
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

void MVPlayer::addCharacterCard(shared_ptr<MVCharacter> characterCard)
{
	characterCards.push_back(characterCard);
}

vector<shared_ptr<MVCharacter>> MVPlayer::getCharacterCardsPlayer()
{
	return characterCards;
}

void MVPlayer::print()
{
	stringstream s;
	s << "goud: " << Coins.size();
	writeLine(s.str());
	writeLine();

	writeLine("Gebouwen:");
	for (size_t i = 0; i < BuildBuildings.size(); i++)
	{
		s = stringstream(" ");
		s << BuildBuildings[i]->toString();
		writeLine(s.str());
	}
	writeLine();
	writeLine("Handkaarten");
	for (size_t i = 0; i < BuildingCards.size(); i++)
	{
		s = stringstream(" ");
		s << BuildingCards[i]->toString();
		writeLine(s.str());
	}

}

vector<shared_ptr<MVBuilding>> MVPlayer::getBuildingCardsPlayer()
{
	return BuildingCards;
}

vector<shared_ptr<MVBuilding>> MVPlayer::getBuildBuildingCardsPlayer()
{
	return BuildBuildings;
}

bool MVPlayer::build(shared_ptr<MVBuilding> building)
{
	if (Coins.size() >= building->getPrice())
	{
		for (size_t i = 0; i < BuildingCards.size(); i++)
		{
			if (building == BuildingCards[i])
			{
				BuildingCards.erase(BuildingCards.begin() + i);
				BuildBuildings.push_back(building);
				return true;
			}
		}
	}
	return false;
}