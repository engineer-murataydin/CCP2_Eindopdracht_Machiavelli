#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include <vector>

class MVGame
{
public:
	MVGame(vector<unique_ptr<MVPlayer>> players);
	~MVGame();

private:
	vector<unique_ptr<MVPlayer>> players;
	vector<unique_ptr<MVCoin>> coins;
};

