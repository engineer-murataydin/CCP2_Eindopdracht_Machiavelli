#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include "../Model/MVDeck.h"
#include <vector>
#include <queue>
#include <random>
#include "../Enum/MVEnum.h"

class MVGameState;


using namespace std;

class MVGame
{
public:
	static shared_ptr<MVGame> Instance();
	~MVGame();

	bool addPlayer(shared_ptr<MVPlayer> player);
	bool isTurn(shared_ptr<Socket> socket);

	void nextTurn();
	static bool isRunning();
	static default_random_engine getDre();
	shared_ptr<MVPlayer> getCurrentPlayer();
	vector<shared_ptr<MVPlayer>> getPlayers();
	unique_ptr<MVCoin> MoveCoin();
	unique_ptr<MVBuilding> getBuilding();
	unique_ptr<MVCharacter>getCharacter(int pos = 0);
	void setBuildingCard(unique_ptr<MVBuilding>card);
	void setCharacterCard(unique_ptr<MVCharacter>card);
	bool hasCoins();
	bool hasBuildingCards();

	void update(shared_ptr<MVPlayer> player, string msg);
	void render(shared_ptr<MVPlayer> player) const;
	void checkState();

	void setState(unique_ptr<MVGameState> state);

	void checkPlayers();

	void quit(MVEnum::Messages message);
	void start();

	shared_ptr<MVPlayer> getPlayer(shared_ptr<Socket> socket) const;

private:
	MVGame();
	static shared_ptr<MVGame> instance;
	static bool running;
	int turn;
	shared_ptr<MVPlayer> currentPlayerTurn;
	vector<shared_ptr<MVPlayer>> players;
	queue<unique_ptr<MVCoin>> coins;
	MVDeck<MVCharacter> characterDeck;
	MVDeck<MVCharacter> usedCharacterDeck;
	MVDeck<MVBuilding> buildingDeck;
	MVDeck<MVBuilding> usedBuildingDeck;
	unique_ptr<MVGameState> state;

	static default_random_engine dre;
};

