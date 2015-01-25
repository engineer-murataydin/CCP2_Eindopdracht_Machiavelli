//
#include "MVThiefState.h"
#include "MVMagicianState.h"
#include "../ActionStates/MVStealActionState.h"
//

//

MVThiefState::MVThiefState() : MVCharacterState(MVEnum::DIEF)
{
}

MVThiefState::~MVThiefState()
{
}

void MVThiefState::update(shared_ptr<MVPlayer> player, int message)
{
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::STEAL:
			robCharacter(player);
			break;
		default:
			MVCharacterState::update(player, message);
			return;
		}
	}
}

void MVThiefState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVMagicianState>(new MVMagicianState()));
	}
}

void MVThiefState::robCharacter(shared_ptr<MVPlayer> player)
{
	special = false;
	game->pushState(shared_ptr<MVStealActionState>(new MVStealActionState(player)));
}

void MVThiefState::onEnter()
{
	cerr << "Enter ThiefState" << endl;
	MVCharacterState::onEnter();
}

void MVThiefState::onExit()
{
	cerr << "Exit ThiefState" << endl;
	MVCharacterState::onExit();
}

vector<MVEnum::Action> MVThiefState::getActions() const
{
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::STEAL);
	}
	return actions;
}