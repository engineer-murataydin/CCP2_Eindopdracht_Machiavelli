#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include "../Model/MVDeck.h"
#include <vector>
#include <queue>
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
	shared_ptr<MVPlayer> getCurrentPlayer();
	vector<shared_ptr<MVPlayer>> getPlayers();
	unique_ptr<MVCoin> MoveCoin();
	unique_ptr<MVBuilding> MoveBuilding(int pos = 0);
	unique_ptr<MVCharacter>MoveCharacter(int pos = 0);
	bool hasCoins();
	bool hasBuildingCards();

	void update(shared_ptr<MVPlayer> player, string msg);
	void render(shared_ptr<MVPlayer> player) const;
	void checkState();

	void setState(unique_ptr<MVGameState> state);

	shared_ptr<MVPlayer> getPlayer(shared_ptr<Socket> socket) const;

private:
	MVGame();
	static shared_ptr<MVGame> instance;
	static bool running;
	int turn;
	void start();
	shared_ptr<MVPlayer> currentPlayerTurn;
	vector<shared_ptr<MVPlayer>> players;
	queue<unique_ptr<MVCoin>> coins;
	MVDeck<MVCharacter> characterDeck;
	MVDeck<MVBuilding> buildingDeck;

	unique_ptr<MVGameState> state;

	static default_random_engine dre;
};

