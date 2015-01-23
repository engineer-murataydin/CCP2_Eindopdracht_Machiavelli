#include "MVDestroyBuildingActionState.h"
#include <sstream>

MVDestroyBuildingActionState::MVDestroyBuildingActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player) : MVActionState(game, player)
{
}


MVDestroyBuildingActionState::~MVDestroyBuildingActionState()
{
}

void MVDestroyBuildingActionState::update(shared_ptr<MVPlayer> player, int message)
{
	if (message == 0)
	{
		game->popState();
		return;
	}
	else
	{
		shared_ptr<MVPlayer> otherPlayer = game->getOtherPlayer(player);
		vector<shared_ptr<MVBuilding>> buildings = otherPlayer->getBuildBuildingCardsPlayer();
		if (player->getCoinAmount() >= buildings[message - 1]->getPrice() - 1)
		{
			otherPlayer->destroyBuilding(buildings[message - 1]);
		}
	}
}

void MVDestroyBuildingActionState::render(shared_ptr<MVPlayer> player) const
{
	player->writeLine("Welk gebouw wil je slopen?");
	vector<shared_ptr<MVBuilding>> buildings = game->getOtherPlayer(player)->getBuildBuildingCardsPlayer();
	for (size_t i = 0; i < buildings.size(); i++)
	{
		stringstream s;
		s << "[" << i + 1 << "] " << buildings[i]->toString();
		player->writeLine(s.str());
	}
	player->writeLine();
	player->writeLine("[0] terug");
}

void MVDestroyBuildingActionState::onEnter()
{

}

void MVDestroyBuildingActionState::onExit()
{

}

void MVDestroyBuildingActionState::checkState()
{

}
