//
#include "MVArchitectState.h"
#include "MVCondottiereState.h"

//

//

MVArchitectState::MVArchitectState() : MVCharacterState(MVEnum::BOUWMEESTER)
{

}

MVArchitectState::~MVArchitectState()
{

}

void MVArchitectState::update(shared_ptr<MVPlayer> player, int message)
{
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::CLAIM_CARDS:
			getCards(player);
			break;
		default:
			MVCharacterState::update(player, message);
			return;
		}

	}
}

void MVArchitectState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVCondottiereState>(new MVCondottiereState()));
	}
}

void MVArchitectState::onEnter()
{
	cerr << "Enter ArchitectState" << endl;
	shared_ptr<MVPlayer> player = game->getPlayer(character);
	if (player)
	{
		player->addBuildingCards(2);
	}
	MVCharacterState::onEnter();
}

void MVArchitectState::onExit()
{
	cerr << "Exit ArchitectState" << endl;
	MVCharacterState::onExit();
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

bool MVArchitectState::canBuild() const
{
	return game->getPlayer(character)->buildInCurrentTurn < 3;
}

void MVArchitectState::getCards(shared_ptr<MVPlayer> player)
{
	if (player->addBuildingCards(2))
		special = false;
}
