//
#include "MVAssassinState.h"

//

//

MVAssassinState::MVAssassinState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	cerr << "Enter AssassinState" << endl;
}

MVAssassinState::~MVAssassinState()
{
	cerr << "Exit AssassinState" << endl;
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