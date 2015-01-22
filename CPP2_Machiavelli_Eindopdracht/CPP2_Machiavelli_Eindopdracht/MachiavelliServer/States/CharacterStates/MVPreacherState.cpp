//
#include "MVPreacherState.h"

//

//

MVPreacherState::MVPreacherState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	
}

MVPreacherState::~MVPreacherState()
{
	
}

void MVPreacherState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVPreacherState::checkState()
{

}

void MVPreacherState::render(shared_ptr<MVPlayer> player) const
{

}

void MVPreacherState::onEnter()
{
	cerr << "Enter PreacherState" << endl;
}

void MVPreacherState::onExit()
{
	cerr << "Exit PreacherState" << endl;
}