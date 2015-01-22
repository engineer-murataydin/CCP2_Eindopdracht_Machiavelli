//
#include "MVThiefState.h"

//

//

MVThiefState::MVThiefState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::DIEF)
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
