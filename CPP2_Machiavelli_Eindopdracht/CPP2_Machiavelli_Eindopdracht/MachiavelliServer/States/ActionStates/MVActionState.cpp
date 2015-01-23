#include "MVActionState.h"


MVActionState::MVActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player) : MVGameState(game), currentPlayer(player)
{
}


MVActionState::~MVActionState()
{
}

bool MVActionState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return currentPlayer == player;
}
