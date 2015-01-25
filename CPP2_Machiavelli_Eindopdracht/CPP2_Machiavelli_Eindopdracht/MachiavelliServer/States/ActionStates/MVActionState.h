#pragma once
#include "../MVGameState.h"
class MVActionState :
	public MVGameState
{
public:
	MVActionState(shared_ptr<MVPlayer> player);
	virtual ~MVActionState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);
protected:
	shared_ptr<MVPlayer> currentPlayer;
};

