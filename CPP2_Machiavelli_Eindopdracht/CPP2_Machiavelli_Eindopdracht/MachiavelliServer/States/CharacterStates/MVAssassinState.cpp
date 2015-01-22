//
#include "MVAssassinState.h"

//

//

MVAssassinState::MVAssassinState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	
}

MVAssassinState::~MVAssassinState()
{
	
}

void MVAssassinState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVAssassinState::checkState()
{

}

void MVAssassinState::render(shared_ptr<MVPlayer> player) const
{

}

void MVAssassinState::killCharacter(MVEnum::Characters chosenCharacter)
{
	character = MVEnum::characterToString(chosenCharacter);

	if (character == "Dief")
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
	else if (character == "Condottiere")
	{

	}
}

void MVAssassinState::onEnter()
{
	cerr << "Enter AssassinState" << endl;
}

void MVAssassinState::onExit()
{
	cerr << "Exit AssassinState" << endl;
}