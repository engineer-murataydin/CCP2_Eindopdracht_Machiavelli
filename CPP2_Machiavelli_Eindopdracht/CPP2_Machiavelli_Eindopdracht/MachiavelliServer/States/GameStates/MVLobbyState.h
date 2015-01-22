#pragma once

//
#include "../MVGameState.h"

//

//

class MVLobbyState :
	public MVGameState
{
public:
	MVLobbyState(shared_ptr<MVGame> game);
	virtual ~MVLobbyState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

