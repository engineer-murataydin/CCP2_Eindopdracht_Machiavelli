//
#include "MVMerchantState.h"
#include "MVArchitectState.h"

//

//

MVMerchantState::MVMerchantState() : MVClaimGoldCharacterState(MVEnum::KOOPMAN, MVEnum::GROEN)
{

}

MVMerchantState::~MVMerchantState()
{

}

void MVMerchantState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVArchitectState>(new MVArchitectState()));
	}
}

void MVMerchantState::onEnter()
{
	cerr << "Enter MerchantState" << endl;

	shared_ptr<MVPlayer> player = game->getPlayer(character);
	if (player)
	{
		player->addCoin();
	}
	MVClaimGoldCharacterState::onEnter();
}

void MVMerchantState::onExit()
{
	cerr << "Exit MerchantState" << endl;
	MVClaimGoldCharacterState::onExit();
}