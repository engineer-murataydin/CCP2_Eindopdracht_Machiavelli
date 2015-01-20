#include "MVDealState.h"

MVDealState::MVDealState(shared_ptr<MVGame> game) :MVGameState(game)
{
	cerr << "Enter DealState" << endl;
}

MVDealState::~MVDealState()
{
	cerr << "Exit DealState" << endl;
}

void MVDealState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVDealState::checkState()
{

}

void MVDealState::render(shared_ptr<MVPlayer> player) const
{

}