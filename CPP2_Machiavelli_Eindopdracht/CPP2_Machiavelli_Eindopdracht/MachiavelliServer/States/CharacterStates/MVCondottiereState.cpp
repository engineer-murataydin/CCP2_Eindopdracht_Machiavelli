//
#include "MVCondottiereState.h"

//

//

MVCondottiereState::MVCondottiereState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::CONDOTTIERE)
{
}

MVCondottiereState::~MVCondottiereState()
{
}

void MVCondottiereState::update(shared_ptr<MVPlayer> player, int message)
{

}

void MVCondottiereState::checkState()
{

}

void MVCondottiereState::render(shared_ptr<MVPlayer> player) const
{

}

void MVCondottiereState::takeCharacterCard(MVEnum::Characters characterTake)
{
	special2 = false;
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
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

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