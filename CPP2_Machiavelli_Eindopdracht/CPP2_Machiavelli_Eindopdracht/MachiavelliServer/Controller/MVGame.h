#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include "../Model/MVDeck.h"
#include <vector>

using namespace std;

class MVGame
{
public:
	MVGame();
	~MVGame();

	bool addPlayer(unique_ptr<MVPlayer> player);
	bool isTurn(shared_ptr<Socket> socket);
	void nextTurn();
	static bool isRunning();
private:
	static bool running;
	int turn;
	shared_ptr<MVPlayer> currentPlayerTurn;
	vector<unique_ptr<MVPlayer>> players;
	vector<unique_ptr<MVCoin>> coins;
	MVDeck<MVCharacter> characterDeck;
	MVDeck<MVBuilding> buildingDeck;

};

