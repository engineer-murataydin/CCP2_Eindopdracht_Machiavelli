#include "MVBuildActionState.h"
#include "../MVCharacterState.h"
#include <sstream>

MVBuildActionState::MVBuildActionState(shared_ptr<MVPlayer> player) : MVActionState(player)
{}

MVBuildActionState::~MVBuildActionState()
{}

void MVBuildActionState::update(shared_ptr<MVPlayer> player, int message)
{
	if (message == 0)
	{
		game->popState();
		return;
	}
	else
	{
		shared_ptr<MVBuilding> chosen = player->getBuildingCardsPlayer()[message];
		player->build(chosen);
		game->popState();
		return;
	}
}

void MVBuildActionState::render(shared_ptr<MVPlayer> player) const
{
	player->writeLine("Welk Gebouw wil je bouwen?");
	vector<shared_ptr<MVBuilding>> buildings = player->getBuildingCardsPlayer();
	for (size_t i = 0; i < buildings.size(); i++)
	{
		stringstream s;
		s << "[" << i + 1 << "] " << buildings[i]->toString();
		player->writeLine(s.str());
	}

	player->writeLine();
	player->writeLine("[0] terug");
}

void MVBuildActionState::onEnter()
{
	cerr << "Enter BuildState" << endl;
	MVActionState::onEnter();
}

void MVBuildActionState::onExit()
{
	cerr << "Exit BuildState" << endl;
	MVActionState::onExit();
}

void MVBuildActionState::checkState()
{

}