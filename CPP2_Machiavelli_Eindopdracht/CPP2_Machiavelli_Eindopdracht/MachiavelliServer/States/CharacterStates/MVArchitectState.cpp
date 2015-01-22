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

void MVArchitectState::update(shared_ptr<MVPlayer> player, string message)
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

