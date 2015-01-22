//
#include "MVCharacterState.h"

//

//

MVCharacterState::MVCharacterState(shared_ptr<MVGame> game) : MVGameState(game)
{}

MVCharacterState::~MVCharacterState()
{}

void MVCharacterState::update(shared_ptr<MVPlayer> player, string message)
{}

void MVCharacterState::checkState()
{}

void MVCharacterState::render(shared_ptr<MVPlayer> player) const
{}

void MVCharacterState::onEnter()
{}

void MVCharacterState::onExit()
{}