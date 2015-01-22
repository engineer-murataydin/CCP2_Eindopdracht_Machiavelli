//
#include "MVGameState.h"

//

//

MVGameState::MVGameState(shared_ptr<MVGame> game) : game(game)
{}

bool MVGameState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return true;
}

MVGameState::~MVGameState()
{}
