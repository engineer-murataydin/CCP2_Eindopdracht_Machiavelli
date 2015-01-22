//
#include "MVMagicianState.h"

//

//

MVMagicianState::MVMagicianState(shared_ptr<MVGame> game) : MVCharacterState(game, MVEnum::MAGIER)
{

}

MVMagicianState::~MVMagicianState()
{

}

void MVMagicianState::update(shared_ptr<MVPlayer> player, int message)
{

}

void MVMagicianState::checkState()
{

}

void MVMagicianState::render(shared_ptr<MVPlayer> player) const
{
}

void MVMagicianState::swapPawCards()
{

}

void MVMagicianState::changePawCards()
{

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