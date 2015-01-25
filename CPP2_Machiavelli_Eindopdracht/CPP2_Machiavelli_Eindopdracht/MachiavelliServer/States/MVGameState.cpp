//
#include "MVGameState.h"

//

//

MVGameState::MVGameState() : game(MVGame::Instance())
{}

MVGameState::~MVGameState()
{}

bool MVGameState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return true;
}