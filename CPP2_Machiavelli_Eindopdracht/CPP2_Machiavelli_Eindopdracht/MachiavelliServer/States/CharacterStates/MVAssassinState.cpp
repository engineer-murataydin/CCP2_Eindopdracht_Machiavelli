//
#include "MVAssassinState.h"

//

//

MVAssassinState::MVAssassinState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::MOORDENAAR)
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
	game->characterKilled(chosenCharacter);
}

vector<MVEnum::Characters> MVAssassinState::getPlayersToKill()
{
	return{ MVEnum::MOORDENAAR, MVEnum::DIEF, MVEnum::MAGIER, MVEnum::KONING, MVEnum::PREDIKER, MVEnum::KOOPMAN, MVEnum::BOUWMEESTER, MVEnum::CONDOTTIERE };
}

void MVAssassinState::onEnter()
{
	cerr << "Enter AssassinState" << endl;
}

void MVAssassinState::onExit()
{
	cerr << "Exit AssassinState" << endl;
}
