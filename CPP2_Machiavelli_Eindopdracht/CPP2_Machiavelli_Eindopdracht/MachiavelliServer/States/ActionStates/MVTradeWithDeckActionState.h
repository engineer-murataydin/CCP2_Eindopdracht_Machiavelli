#pragma once
#include "MVActionState.h"

class MVTradeWithDeckActionState :
	public MVActionState
{
public:
	MVTradeWithDeckActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player);
	virtual ~MVTradeWithDeckActionState();

	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

