//
#include "MVMerchantState.h"
#include "MVArchitectState.h"

//

//

MVMerchantState::MVMerchantState(shared_ptr<MVGame> game) : MVClaimGoldCharacterState(game, MVEnum::KOOPMAN, MVEnum::GROEN)
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
	if (done)
	{
		game->setState(shared_ptr<MVArchitectState>(new MVArchitectState(game)));
	}
}

void MVMerchantState::render(shared_ptr<MVPlayer> player) const
{

}

void MVMerchantState::onEnter()
{
	MVClaimGoldCharacterState::onEnter();
	cerr << "Enter MerchantState" << endl;
}

void MVMerchantState::onExit()
{
	cerr << "Exit MerchantState" << endl;
}

vector<MVEnum::Action> MVMerchantState::getActions() const
{
	vector<MVEnum::Action> actions = MVClaimGoldCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_GOLD);
	}
	return actions;
}