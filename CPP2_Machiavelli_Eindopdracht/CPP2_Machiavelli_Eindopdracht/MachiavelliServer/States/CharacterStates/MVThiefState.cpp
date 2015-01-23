//
#include "MVThiefState.h"
#include "MVMagicianState.h"
//

//

MVThiefState::MVThiefState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::DIEF)
{
}

MVThiefState::~MVThiefState()
{
}

void MVThiefState::update(shared_ptr<MVPlayer> player, int message)
{

}

void MVThiefState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVMagicianState>(new MVMagicianState(game)));
	}
}

void MVThiefState::render(shared_ptr<MVPlayer> player) const
{

}

void MVThiefState::robCharacter(MVEnum::Characters chosenCharacter)
{

}

void MVThiefState::onEnter()
{
	MVCharacterState::onEnter();
	cerr << "Enter ThiefState" << endl;
}

void MVThiefState::onExit()
{
	MVCharacterState::onExit();
	cerr << "Exit ThiefState" << endl;
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