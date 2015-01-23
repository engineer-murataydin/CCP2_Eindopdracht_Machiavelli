//
#include "MVAssassinState.h"
#include "MVThiefState.h"
#include "../ActionStates/MVMurderActionState.h"
#include <sstream>

//

//

MVAssassinState::MVAssassinState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::MOORDENAAR)
{

}

MVAssassinState::~MVAssassinState()
{

}

void MVAssassinState::update(shared_ptr<MVPlayer> player, int message)
{
	message--;
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::KILL:
			killCharacter(player);
			break;
		default:
			MVCharacterState::update(player, message);
			return;
		}
	}
}

void MVAssassinState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVThiefState>(new MVThiefState(game)));
	}
}

void MVAssassinState::killCharacter(shared_ptr<MVPlayer> player)
{
	special = false;
	game->pushState(shared_ptr<MVMurderActionState>(new MVMurderActionState(game, player)));
}

void MVAssassinState::onEnter()
{
	cerr << "Enter AssassinState" << endl;
	MVCharacterState::onEnter();
}

void MVAssassinState::onExit()
{
	cerr << "Exit AssassinState" << endl;
	MVCharacterState::onExit();
}

vector<MVEnum::Action> MVAssassinState::getActions() const
{
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::KILL);
	}
	return actions;
}
