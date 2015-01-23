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
	switch (getActions()[message - 1])
	{
	case MVEnum::KILL:
		killCharacter(player);
		break;
	default:
		MVCharacterState::update(player, message);
		return;
	}
}

void MVAssassinState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVThiefState>(new MVThiefState(game)));
	}
}

void MVAssassinState::render(shared_ptr<MVPlayer> player) const
{
	MVCharacterState::render(player);
	vector<MVEnum::Action> actions = getActions();
	for (size_t i = 0; i < actions.size(); i++)
	{
		stringstream s;
		s << "[" << i + 1 << "] " + MVEnum::actionToString(actions[i]);
		player->writeLine(s.str());
	}
}

void MVAssassinState::killCharacter(shared_ptr<MVPlayer> player)
{
	special = false;
	game->pushState(shared_ptr<MVMurderActionState>(new MVMurderActionState(game, player)));
}

void MVAssassinState::onEnter()
{
	MVCharacterState::onEnter();
	cerr << "Enter AssassinState" << endl;
}

void MVAssassinState::onExit()
{
	MVCharacterState::onExit();
	cerr << "Exit AssassinState" << endl;
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
