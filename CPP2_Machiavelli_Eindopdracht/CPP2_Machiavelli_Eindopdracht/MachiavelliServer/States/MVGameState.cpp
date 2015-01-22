//
#include "MVGameState.h"

//

//

MVGameState::MVGameState(shared_ptr<MVGame> game) : game(game)
{
	players = MVGame::Instance()->getPlayers();
}

MVGameState::~MVGameState()
{}

vector<shared_ptr<MVPlayer>> MVGameState::getAllPlayers()
{
	return players;
}