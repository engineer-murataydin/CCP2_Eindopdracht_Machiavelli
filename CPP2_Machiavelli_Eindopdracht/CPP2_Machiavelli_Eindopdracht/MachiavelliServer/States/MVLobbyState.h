#pragma once
#include "MVGameState.h"

class MVLobbyState :
	public MVGameState
{
public:
	MVLobbyState(shared_ptr<MVGame> game);
	virtual ~MVLobbyState();
};

