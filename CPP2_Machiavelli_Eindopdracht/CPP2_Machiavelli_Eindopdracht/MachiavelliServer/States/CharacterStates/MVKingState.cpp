//
#include "MVKingState.h"
#include "MVPreacherState.h"

//

//

MVKingState::MVKingState() : MVClaimGoldCharacterState(MVEnum::KONING, MVEnum::GEEL)
{

}

MVKingState::~MVKingState()
{

}

void MVKingState::checkState()
{
	if (done)
	{
		game->setState(shared_ptr<MVPreacherState>(new MVPreacherState()));
	}
}

void MVKingState::onEnter()
{
	cerr << "Enter KingState" << endl;


	shared_ptr<MVPlayer> player = game->getPlayer(character);
	if (player&& game->getKilled() != character)
	{
		game->setKing(player);
	}
	
	MVClaimGoldCharacterState::onEnter();
}

void MVKingState::onExit()
{
	cerr << "Exit KingState" << endl;
	MVClaimGoldCharacterState::onExit();
}
