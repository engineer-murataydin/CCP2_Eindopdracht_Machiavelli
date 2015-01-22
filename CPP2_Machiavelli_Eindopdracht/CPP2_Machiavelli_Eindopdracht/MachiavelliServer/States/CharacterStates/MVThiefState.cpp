//
#include "MVThiefState.h"

//

//

MVThiefState::MVThiefState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::DIEF)
{
	cerr << "Enter ThiefState" << endl;
}

MVThiefState::~MVThiefState()
{
	cerr << "Exit ThiefState" << endl;
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
