//
#include "MVCondottiereState.h"

//

//

MVCondottiereState::MVCondottiereState(shared_ptr<MVGame> game) : MVCharacterState(game)
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
	character = MVEnum::characterToString(characterTake);

	if (character == "Moordenaar")
	{

	}
	else if (character == "Magier")
	{

	}
	else if (character == "Koning")
	{

	}
	else if (character == "Prediker")
	{

	}
	else if (character == "Koopman")
	{

	}
	else if (character == "Bouwmeester")
	{

	}
}

void MVCondottiereState::onEnter()
{
	cerr << "Enter CondottiereState" << endl;

}

void MVCondottiereState::onExit()
{
	cerr << "Exit CondottiereState" << endl;
}