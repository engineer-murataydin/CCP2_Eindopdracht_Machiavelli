#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include <vector>

using namespace std;

class MVGame
{
public:
	MVGame();
	~MVGame();

	bool addPlayer(MVPlayer* player);
	bool isTurn(shared_ptr<Socket> socket);
private:
	int turn;
	vector<shared_ptr<MVPlayer>> players;
	vector<unique_ptr<MVCoin>> coins;
};

