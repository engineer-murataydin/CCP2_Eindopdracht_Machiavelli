//
#include "MVKingState.h"

//

//

MVKingState::MVKingState(shared_ptr<MVGame> game) : MVClaimGoldCharacterState(game, MVEnum::KONING, MVEnum::GEEL)
{

}

MVKingState::~MVKingState()
{

}

void MVKingState::update(shared_ptr<MVPlayer> player, int message)
{

}

void MVKingState::checkState()
{

}

void MVKingState::render(shared_ptr<MVPlayer> player) const
{

}

void MVKingState::onEnter()
{
	//game->setKing(
	game->getPlayer(character);
	MVClaimGoldCharacterState::onEnter();

	cerr << "Enter KingState" << endl;
}

void MVKingState::onExit()
{
	cerr << "Exit KingState" << endl;
}

vector<MVEnum::Action> MVKingState::getActions() const
{
	vector<MVEnum::Action> actions = MVClaimGoldCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_GOLD);
	}
	return actions;
}