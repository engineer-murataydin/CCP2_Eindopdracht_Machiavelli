#pragma once

//
#include "../MVGameState.h"

//

//

class MVLobbyState :
	public MVGameState
{
public:
	MVLobbyState();
	virtual ~MVLobbyState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

