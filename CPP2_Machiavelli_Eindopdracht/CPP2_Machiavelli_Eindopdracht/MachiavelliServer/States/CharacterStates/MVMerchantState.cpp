//
#include "MVMerchantState.h"

//

//

MVMerchantState::MVMerchantState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	cerr << "Enter MerchantState" << endl;
}

MVMerchantState::~MVMerchantState()
{
	cerr << "Exit MerchantState" << endl;
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