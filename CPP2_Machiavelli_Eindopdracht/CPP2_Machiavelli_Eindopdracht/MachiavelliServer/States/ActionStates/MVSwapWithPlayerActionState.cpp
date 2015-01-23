#include "MVSwapWithPlayerActionState.h"

MVSwapWithPlayerActionState::MVSwapWithPlayerActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player) : MVActionState(game, player)
{}


MVSwapWithPlayerActionState::~MVSwapWithPlayerActionState()
{}

void MVSwapWithPlayerActionState::update(shared_ptr<MVPlayer> player, int message)
{}

void MVSwapWithPlayerActionState::render(shared_ptr<MVPlayer> player) const
{}

void MVSwapWithPlayerActionState::onEnter()
{
	cerr << "Enter SwapWithPlayerActionState" << endl;
}

void MVSwapWithPlayerActionState::onExit()
{
	cerr << "Exit SwapWithPlayerActionState" << endl;
}

void MVSwapWithPlayerActionState::checkState()
{}