//
#include "MVGameState.h"

//

//

MVGameState::MVGameState(shared_ptr<MVGame> game) : game(game)
{}

MVGameState::~MVGameState()
{}

bool MVGameState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return true;
}