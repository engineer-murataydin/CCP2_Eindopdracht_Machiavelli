//
#include "MVPreacherState.h"
#include "MVMerchantState.h"

//

//

MVPreacherState::MVPreacherState() : MVClaimGoldCharacterState(MVEnum::PREDIKER, MVEnum::BLAUW)
{

}

MVPreacherState::~MVPreacherState()
{

}

void MVPreacherState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVMerchantState>(new MVMerchantState()));
	}
}

void MVPreacherState::onEnter()
{
	cerr << "Enter PreacherState" << endl;
	MVClaimGoldCharacterState::onEnter();
}

void MVPreacherState::onExit()
{
	cerr << "Exit PreacherState" << endl;
	MVClaimGoldCharacterState::onExit();
}
