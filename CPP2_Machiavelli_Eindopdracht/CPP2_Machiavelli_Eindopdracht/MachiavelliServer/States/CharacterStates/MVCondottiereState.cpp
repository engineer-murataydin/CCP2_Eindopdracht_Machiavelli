//
#include "MVCondottiereState.h"

//

//

MVCondottiereState::MVCondottiereState(shared_ptr<MVGame> game) : MVClaimGoldCharacterState(game, MVEnum::CONDOTTIERE, MVEnum::ROOD)
{
}

MVCondottiereState::~MVCondottiereState()
{
}

void MVCondottiereState::update(shared_ptr<MVPlayer> player, int message)
{
	switch (getActions()[message - 1])
	{
	case MVEnum::DESTROY_BUILDING:
		//killCharacter(player);
		break;
	default:
		MVCharacterState::update(player, message);
		return;
	}
}

void MVCondottiereState::checkState()
{

}

void MVCondottiereState::render(shared_ptr<MVPlayer> player) const
{

}


void MVCondottiereState::onEnter()
{
	MVCharacterState::onEnter();
	cerr << "Enter CondottiereState" << endl;

}

void MVCondottiereState::onExit()
{
	MVCharacterState::onExit();
	cerr << "Exit CondottiereState" << endl;
}

vector<MVEnum::Action> MVCondottiereState::getActions() const
{
	vector<MVEnum::Action> actions = MVClaimGoldCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_GOLD);
	}
	if (special2)
	{
		actions.push_back(MVEnum::DESTROY_BUILDING);
	}
	return actions;
}