#pragma once
#include <memory>

#include "../Controller/MVGame.h"

class MVGameState
{
public:
	MVGameState(shared_ptr<MVGame> game);
	~MVGameState();

protected:
	shared_ptr<MVGame> game;

};

