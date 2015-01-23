#include "MVTradeWithDeckActionState.h"
#include <sstream>

MVTradeWithDeckActionState::MVTradeWithDeckActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player) : MVActionState(game, player)
{}

MVTradeWithDeckActionState::~MVTradeWithDeckActionState()
{}

void MVTradeWithDeckActionState::update(shared_ptr<MVPlayer> player, int message)
{
	auto it = buildingCards.begin();
	for (int i = 0; i < message && it != buildingCards.end(); i++)
	{
		++it;
	}
	it->second != it->second;
}

void MVTradeWithDeckActionState::render(shared_ptr<MVPlayer> player) const
{
	int i = 1;
	for (auto it = buildingCards.begin(); it != buildingCards.end(); ++it)
	{
		stringstream s;
		if (it->second)
		{
			s << "[" << to_string(i + 1) << "]* " << it->first;
		}
		else
		{
			s << "[" << to_string(i + 1) << "]  " << it->first;
		}
		i++;
		player->writeLine(s.str());
	}
}

void MVTradeWithDeckActionState::onEnter()
{
	cerr << "Enter TradeWithDeckActionState" << endl;
	vector<shared_ptr<MVBuilding>> bCards = currentPlayer->getBuildingCardsPlayer();
	for (size_t i = 0; i < bCards.size(); i++)
	{
		buildingCards[bCards[i]] = false;
	}
}

void MVTradeWithDeckActionState::onExit()
{
	cerr << "Exit TradeWithDeckActionState" << endl;
}

void MVTradeWithDeckActionState::checkState()
{}