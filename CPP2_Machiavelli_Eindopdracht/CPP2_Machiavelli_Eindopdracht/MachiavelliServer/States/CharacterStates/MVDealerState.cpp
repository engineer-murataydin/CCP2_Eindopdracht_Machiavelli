//
#include "MVDealerState.h"

//

//

MVDealerState::MVDealerState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	cerr << "Enter DealerState" << endl;
}

MVDealerState::~MVDealerState()
{
	cerr << "Exit DealerState" << endl;
}

void MVDealerState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVDealerState::checkState()
{

}

void MVDealerState::render(shared_ptr<MVPlayer> player) const
{

}