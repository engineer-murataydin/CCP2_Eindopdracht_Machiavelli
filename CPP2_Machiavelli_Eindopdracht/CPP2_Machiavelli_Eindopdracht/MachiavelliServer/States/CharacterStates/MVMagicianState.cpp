//
#include "MVMagicianState.h"
#include "MVKingState.h"
#include "../ActionStates/MVTradeWithDeckActionState.h"

//
#include <sstream>

//

MVMagicianState::MVMagicianState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::MAGIER)
{

}

MVMagicianState::~MVMagicianState()
{

}

void MVMagicianState::update(shared_ptr<MVPlayer> player, int message)
{

	message--;
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::SWAP_WITH_PLAYER:
			swapPawCards(player);
			break;
		case MVEnum::TRADE_WITH_DECK:
			tradePawCards(player);
			break;
		default:
			MVCharacterState::update(player, message);
			return;
		}
	}
}

void MVMagicianState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVKingState>(new MVKingState(game)));
	}
}

void MVMagicianState::swapPawCards(shared_ptr<MVPlayer> player)
{
	special = false;
	player->swapCards(game->getOtherPlayer(player));
}

void MVMagicianState::tradePawCards(shared_ptr<MVPlayer> player)
{
	special = false;
	game->pushState(shared_ptr<MVTradeWithDeckActionState>(new MVTradeWithDeckActionState(game, player)));
}

void MVMagicianState::onEnter()
{
	cerr << "Enter MagicianState" << endl;
	MVCharacterState::onEnter();
}

void MVMagicianState::onExit()
{
	cerr << "Exit MagicianState" << endl;
	MVCharacterState::onExit();
}

vector<MVEnum::Action> MVMagicianState::getActions() const
{
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::SWAP_WITH_PLAYER);
		actions.push_back(MVEnum::TRADE_WITH_DECK);
	}
	return actions;
}