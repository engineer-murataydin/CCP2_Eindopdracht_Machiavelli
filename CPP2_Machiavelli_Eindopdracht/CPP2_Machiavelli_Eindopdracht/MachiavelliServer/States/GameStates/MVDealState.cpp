//
#include "MVDealState.h"

//

//

MVDealState::MVDealState(shared_ptr<MVGame> game) : MVGameState(game)
{
	cerr << "Enter DealState" << endl;
	vector<shared_ptr<MVPlayer>> players = MVGame::Instance()->getPlayers();
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->write("\n\rPlay the game!!! Welcome to Machiavelli\n\r");
	}
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