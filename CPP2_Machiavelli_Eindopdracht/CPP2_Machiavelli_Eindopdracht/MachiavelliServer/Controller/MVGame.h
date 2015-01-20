#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include "../Model/MVDeck.h"
#include <vector>
#include <random>


class MVGameState;


using namespace std;

class MVGame
{
public:
	static shared_ptr<MVGame> Instance();
	~MVGame();

	void quit();
	bool addPlayer(shared_ptr<MVPlayer> player);
	bool isTurn(shared_ptr<Socket> socket);
	void nextTurn();
	static bool isRunning();
	static default_random_engine getDre();

	vector<shared_ptr<MVPlayer>> getPlayers();

private:
	MVGame();
	static shared_ptr<MVGame> instance;
	static bool running;
	int turn;
	void start();
	shared_ptr<MVPlayer> currentPlayerTurn;
	vector<shared_ptr<MVPlayer>> players;
	vector<unique_ptr<MVCoin>> coins;
	MVDeck<MVCharacter> characterDeck;
	MVDeck<MVBuilding> buildingDeck;

	unique_ptr<MVGameState> state;

	static default_random_engine dre;
};

