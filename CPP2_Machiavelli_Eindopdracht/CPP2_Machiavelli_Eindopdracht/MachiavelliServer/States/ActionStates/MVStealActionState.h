#pragma once
#include "../MVGameState.h"
class MVStealActionState :
	public MVActionState
{
public:
	MVStealActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player);
	virtual ~MVStealActionState();
	
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

