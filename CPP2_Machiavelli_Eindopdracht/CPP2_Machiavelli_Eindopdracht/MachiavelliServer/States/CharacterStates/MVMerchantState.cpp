//
#include "MVMerchantState.h"

//

//

MVMerchantState::MVMerchantState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::KOOPMAN)
{
	
}

MVMerchantState::~MVMerchantState()
{
	
}

void MVMerchantState::update(shared_ptr<MVPlayer> player, int message)
{

}

void MVMerchantState::checkState()
{

}

void MVMerchantState::render(shared_ptr<MVPlayer> player) const
{

}

void MVMerchantState::onEnter()
{
	
	cerr << "Enter MerchantState" << endl;
}

void MVMerchantState::onExit()
{
	cerr << "Exit MerchantState" << endl;
}

vector<MVEnum::Action> MVMerchantState::getActions() const
{
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_GOLD);
	}
	return actions;
}