//
#include "MVCharacterState.h"

//

//

MVCharacterState::MVCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character) : MVGameState(game), character(character)
{}

MVCharacterState::~MVCharacterState()
{}

void MVCharacterState::update(shared_ptr<MVPlayer> player, string message)
{}

void MVCharacterState::checkState()
{}

void MVCharacterState::render(shared_ptr<MVPlayer> player) const
{}

bool MVCharacterState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return game->getPlayer(character) == player;
}

bool MVCharacterState::canEndTurn()
{
	return actionOne;
}

void MVCharacterState::onEnter()
{}

void MVCharacterState::onExit()
{}
