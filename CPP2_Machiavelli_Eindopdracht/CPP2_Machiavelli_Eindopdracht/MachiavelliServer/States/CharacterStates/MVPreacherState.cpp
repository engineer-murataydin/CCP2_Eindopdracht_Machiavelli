//
#include "MVPreacherState.h"

//

//

MVPreacherState::MVPreacherState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::PREDIKER)
{
	cerr << "Enter PreacherState" << endl;
}

MVPreacherState::~MVPreacherState()
{
	cerr << "Exit PreacherState" << endl;
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