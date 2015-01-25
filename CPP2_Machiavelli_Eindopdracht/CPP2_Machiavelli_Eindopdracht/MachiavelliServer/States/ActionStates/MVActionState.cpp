#include "MVActionState.h"

MVActionState::MVActionState(shared_ptr<MVPlayer> player) : currentPlayer(player)
{
}

MVActionState::~MVActionState()
{
}

void MVActionState::update(shared_ptr<MVPlayer> player, int message)
{}

void MVActionState::render(shared_ptr<MVPlayer> player) const
{}

void MVActionState::onEnter()
{}

void MVActionState::onExit()
{}

void MVActionState::checkState()
{}

bool MVActionState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return currentPlayer == player;
}
