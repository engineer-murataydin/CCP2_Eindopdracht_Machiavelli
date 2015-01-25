#include "MVGetCardActionState.h"


MVGetCardActionState::MVGetCardActionState(shared_ptr<MVPlayer> player) :MVActionState(player)
{
}


MVGetCardActionState::~MVGetCardActionState()
{
}

void MVGetCardActionState::update(shared_ptr<MVPlayer> player, int message)
{
	if (message >= 0 && message < cards.size())
	{
		player->addBuildingCard(cards[message]);
		cards.erase(cards.begin() + message);
		game->popState();
	}
}

void MVGetCardActionState::render(shared_ptr<MVPlayer> player) const
{
	player->writeLine("Welke kaart wil je houden?");
	for (size_t i = 0; i < cards.size(); i++)
	{
		stringstream s;
		s << "[" << i + 1 << "] " << cards[i]->toString();
		player->writeLine(s.str());
	}
}

void MVGetCardActionState::onEnter()
{
	cerr << "Enter GetCardState" << endl;
	for (int i = 0; i < 2; i++)
	{
		cards.push_back(game->getBuilding());
	}
	MVActionState::onEnter();
}

void MVGetCardActionState::onExit()
{
	cerr << "Exit GetCardState" << endl;
	while (!cards.empty())
	{
		game->setBuildingCard(cards.front());
		cards.erase(cards.begin());
	}
	MVActionState::onExit();
}

void MVGetCardActionState::checkState()
{

}