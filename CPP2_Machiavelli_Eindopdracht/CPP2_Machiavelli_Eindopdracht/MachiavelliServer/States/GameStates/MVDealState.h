#pragma once

//
#include "../MVGameState.h"

//

//
using namespace std;

class MVDealState :
	public MVGameState
{
public:
	MVDealState();
	virtual ~MVDealState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);

private:
	shared_ptr<MVPlayer> curPlayer;
	bool hasChosenCard;
};

