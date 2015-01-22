//
#include "MVThiefState.h"

//

//

MVThiefState::MVThiefState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
}

MVThiefState::~MVThiefState()
{
}

void MVThiefState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVThiefState::checkState()
{

}

void MVThiefState::render(shared_ptr<MVPlayer> player) const
{

}

void MVThiefState::robCharacter(MVEnum::Characters chosenCharacter)
{
	character = MVEnum::characterToString(chosenCharacter);

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
	else if (character == "Condottiere")
	{

	}
}

void MVThiefState::onEnter()
{
	cerr << "Enter ThiefState" << endl;
}

void MVThiefState::onExit()
{
	cerr << "Exit ThiefState" << endl;

}