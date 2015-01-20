#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include "../Model/MVDeck.h"
#include <vector>
#include <random>
#include "../States/MVGameState.h"

using namespace std;

class MVGame
{
public:
	MVGame();
	~MVGame();

	bool addPlayer(shared_ptr<MVPlayer> player);
	bool isTurn(shared_ptr<Socket> socket);
	void nextTurn();
	static bool isRunning();
	static default_random_engine getDre();

private:
	static bool running;
	int turn;
	void start();
	shared_ptr<MVPlayer> currentPlayerTurn;
	vector<shared_ptr<MVPlayer>> players;
	vector<unique_ptr<MVCoin>> coins;
	MVDeck<MVCharacter> characterDeck;
	MVDeck<MVBuilding> buildingDeck;

	MVGameState state;

	static default_random_engine dre;
};

