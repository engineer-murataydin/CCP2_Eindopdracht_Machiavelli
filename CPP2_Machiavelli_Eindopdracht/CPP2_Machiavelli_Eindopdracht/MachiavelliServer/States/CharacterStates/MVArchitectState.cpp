//
#include "MVArchitectState.h"

//

//

MVArchitectState::MVArchitectState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	cerr << "Enter ArchitectState" << endl;
}

MVArchitectState::~MVArchitectState()
{
	cerr << "Exit ArchitectState" << endl;
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