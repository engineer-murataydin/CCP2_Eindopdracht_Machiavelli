//
#include "MVKingState.h"

//

//

MVKingState::MVKingState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::KONING)
{
	cerr << "Enter KingState" << endl;
}

MVKingState::~MVKingState()
{
	cerr << "Exit KingState" << endl;
}

void MVKingState::update(shared_ptr<MVPlayer> player, string message)
{
	  
}

void MVKingState::checkState()
{

}

void MVKingState::render(shared_ptr<MVPlayer> player) const
{

}