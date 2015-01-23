//
#include "MVPreacherState.h"

//

//

MVPreacherState::MVPreacherState(shared_ptr<MVGame> game) : MVClaimGoldCharacterState(game, MVEnum::PREDIKER, MVEnum::BLAUW)
{

}

MVPreacherState::~MVPreacherState()
{

}

void MVPreacherState::update(shared_ptr<MVPlayer> player, int message)
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
	MVClaimGoldCharacterState::onEnter();
	cerr << "Enter PreacherState" << endl;
}

void MVPreacherState::onExit()
{
	cerr << "Exit PreacherState" << endl;
}

vector<MVEnum::Action> MVPreacherState::getActions() const
{
	vector<MVEnum::Action> actions = MVClaimGoldCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_GOLD);
	}
	return actions;
}