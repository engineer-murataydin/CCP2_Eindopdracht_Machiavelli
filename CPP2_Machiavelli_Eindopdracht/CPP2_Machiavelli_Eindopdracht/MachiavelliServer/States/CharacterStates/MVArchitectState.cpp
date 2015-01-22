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
