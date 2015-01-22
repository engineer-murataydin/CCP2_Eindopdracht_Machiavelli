#pragma once
#include <memory>

#include "../Controller/MVGame.h"
#include "../Model/MVPlayer.h"

class MVGameState
{
public:
	MVGameState(shared_ptr<MVGame> game);
	~MVGameState();
	virtual void update(shared_ptr<MVPlayer> player, string message) = 0;
	virtual void render(shared_ptr<MVPlayer> player) const = 0;
	virtual void checkState() = 0;

	vector<shared_ptr<MVPlayer>> getAllPlayers();

protected:
	shared_ptr<MVGame> game;
	vector<shared_ptr<MVPlayer>> players;
};

