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

void MVMerchantState::update(shared_ptr<MVPlayer> player, string message)
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