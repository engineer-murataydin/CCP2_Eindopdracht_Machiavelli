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
	switch (getActions()[message - 1])
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

void MVMagicianState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVKingState>(new MVKingState(game)));
	}
}

void MVMagicianState::render(shared_ptr<MVPlayer> player) const
{
	MVCharacterState::render(player);
	vector<MVEnum::Action> actions = getActions();
	for (size_t i = 0; i < actions.size(); i++)
	{
		stringstream s;
		s << "[" << i + 1 << "] " + MVEnum::actionToString(actions[i]);
		player->writeLine(s.str());
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
	MVCharacterState::onEnter();
	cerr << "Enter MagicianState" << endl;
}

void MVMagicianState::onExit()
{
	MVCharacterState::onExit();
	cerr << "Exit MagicianState" << endl;
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