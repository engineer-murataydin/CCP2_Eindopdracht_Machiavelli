//
#include "MVCondottiereState.h"
#include "../GameStates/MVDealState.h"
#include "../ActionStates/MVDestroyBuildingActionState.h"

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
	message--;
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::DESTROY_BUILDING:
			DestroyBuilding(player);
			break;
		default:
			MVClaimGoldCharacterState::update(player, message);
			return;
		}
	}
}

void MVCondottiereState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVDealState>(new MVDealState(game)));
	}
}

void MVCondottiereState::onEnter()
{
	cerr << "Enter CondottiereState" << endl;
	MVClaimGoldCharacterState::onEnter();

}

void MVCondottiereState::onExit()
{
	cerr << "Exit CondottiereState" << endl;
	MVClaimGoldCharacterState::onExit();
}

vector<MVEnum::Action> MVCondottiereState::getActions() const
{
	vector<MVEnum::Action> actions = MVClaimGoldCharacterState::getActions();

	if (special2)
	{
		actions.push_back(MVEnum::DESTROY_BUILDING);
	}
	return actions;
}

void MVCondottiereState::DestroyBuilding(shared_ptr<MVPlayer> player)
{
	game->pushState(shared_ptr<MVDestroyBuildingActionState>(new MVDestroyBuildingActionState(game, player)));
}
