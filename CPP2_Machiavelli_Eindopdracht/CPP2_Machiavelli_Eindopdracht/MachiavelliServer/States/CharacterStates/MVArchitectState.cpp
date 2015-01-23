//
#include "MVArchitectState.h"

//

//

MVArchitectState::MVArchitectState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::BOUWMEESTER)
{

}

MVArchitectState::~MVArchitectState()
{

}

void MVArchitectState::update(shared_ptr<MVPlayer> player, int message)
{
	switch (getActions()[message - 1])
	{
	case MVEnum::CLAIM_CARDS:
		getCards(player);
		break;
	default:
		MVCharacterState::update(player, message);
		return;
	}
}

void MVArchitectState::checkState()
{

}

void MVArchitectState::render(shared_ptr<MVPlayer> player) const
{

}

void MVArchitectState::onEnter()
{
	cerr << "Enter ArchitectState" << endl;
}

void MVArchitectState::onExit()
{
	cerr << "Exit ArchitectState" << endl;
}

vector<MVEnum::Action> MVArchitectState::getActions() const
{
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_CARDS);
	}
	return actions;
}

bool MVArchitectState::canBuild()
{
	return build < 3;
}

void MVArchitectState::getCards(shared_ptr<MVPlayer> player)
{
	if (player->addBuildingCards(2))
		special = false;
}
