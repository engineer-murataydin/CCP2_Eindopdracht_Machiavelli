#pragma once
#include "../MVGameState.h"
class MVActionState :
	public MVGameState
{
public:
	MVActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player);
	virtual ~MVActionState();
	virtual void update(shared_ptr<MVPlayer> player, int message) = 0;
	virtual void render(shared_ptr<MVPlayer> player) const = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual void checkState() = 0;
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);
protected:
	shared_ptr<MVPlayer> currentPlayer;
};

