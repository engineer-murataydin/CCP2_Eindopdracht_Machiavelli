//
#include "MVCondottiereState.h"

//

//

MVCondottiereState::MVCondottiereState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::CONDOTTIERE)
{
}

MVCondottiereState::~MVCondottiereState()
{
}

void MVCondottiereState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVCondottiereState::checkState()
{

}

void MVCondottiereState::render(shared_ptr<MVPlayer> player) const
{

}

void MVCondottiereState::takeCharacterCard(MVEnum::Characters characterTake)
{
}

void MVCondottiereState::onEnter()
{
	MVCharacterState::onEnter();
	cerr << "Enter CondottiereState" << endl;

}

void MVCondottiereState::onExit()
{
	MVCharacterState::onExit();
	cerr << "Exit CondottiereState" << endl;
}