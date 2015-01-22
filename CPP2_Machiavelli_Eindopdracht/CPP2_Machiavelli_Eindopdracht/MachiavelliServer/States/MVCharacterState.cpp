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

shared_ptr<MVPlayer> MVCharacterState::getCurrentPlayer()
{
	return game->getPlayer(character);
}

bool MVCharacterState::canEndTurn()
{
	return actionOne;
}
