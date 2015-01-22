#pragma once
#include <memory>

#include "../Controller/MVGame.h"
#include "../Model/MVPlayer.h"

class MVGameState
{
public:
	MVGameState(shared_ptr<MVGame> game);
	~MVGameState();
	virtual void update(shared_ptr<MVPlayer> player, int message) = 0;
	virtual void render(shared_ptr<MVPlayer> player) const = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual void checkState() = 0;
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);

protected:
	shared_ptr<MVGame> game;
};

