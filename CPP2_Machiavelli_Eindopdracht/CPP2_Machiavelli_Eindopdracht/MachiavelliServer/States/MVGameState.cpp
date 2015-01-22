//
#include "MVGameState.h"

//

//

MVGameState::MVGameState(shared_ptr<MVGame> game) : game(game)
{}

shared_ptr<MVPlayer> MVGameState::getCurrentPlayer()
{
	return shared_ptr<MVPlayer>();
}

MVGameState::~MVGameState()
{}
