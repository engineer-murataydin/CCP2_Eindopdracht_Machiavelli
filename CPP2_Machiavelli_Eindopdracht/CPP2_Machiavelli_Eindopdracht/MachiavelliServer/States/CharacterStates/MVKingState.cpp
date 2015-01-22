//
#include "MVKingState.h"

//

//

MVKingState::MVKingState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::KONING)
{

}

MVKingState::~MVKingState()
{

}

void MVKingState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVKingState::checkState()
{

}

void MVKingState::render(shared_ptr<MVPlayer> player) const
{

}

void MVKingState::onEnter()
{
	//game->setKing(
	game->getPlayer(character);
	MVCharacterState::onEnter();

	cerr << "Enter KingState" << endl;
}

void MVKingState::onExit()
{
	cerr << "Exit KingState" << endl;
}