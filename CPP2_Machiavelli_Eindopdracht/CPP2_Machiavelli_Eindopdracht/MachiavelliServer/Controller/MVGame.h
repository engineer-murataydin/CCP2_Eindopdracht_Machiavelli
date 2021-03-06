#pragma once

#include "../Model/MVPlayer.h"
#include "../Model/MVCoin.h"
#include "../Model/MVDeck.h"
#include <vector>
#include <queue>
#include <stack>
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

	void nextTurn();
	static bool isRunning();
	static default_random_engine getDre();
	bool isCurrentPlayer(shared_ptr<MVPlayer> player);
	shared_ptr<MVPlayer> getCurrentPlayer();
	vector<shared_ptr<MVPlayer>> getPlayers();
	unique_ptr<MVCoin> MoveCoin();
	void SetCoin(unique_ptr<MVCoin> coin);
	shared_ptr<MVBuilding> getBuilding();
	shared_ptr<MVCharacter>getCharacter(int pos = 0);
	void setBuildingCard(shared_ptr<MVBuilding>card);
	void setCharacterCard(shared_ptr<MVCharacter>card);
	bool hasCoins();
	bool hasBuildingCards();

	void update(shared_ptr<MVPlayer> player, string msg);
	void render(shared_ptr<MVPlayer> player) const;
	void checkState();

	void setState(shared_ptr<MVGameState> state);
	void popState();
	void pushState(shared_ptr<MVGameState> state);

	shared_ptr<MVGameState> getState();

	void checkPlayers();

	void quit(MVEnum::Messages message);
	void start();

	MVEnum::Characters getKilled();
	MVEnum::Characters getStolen();
	void characterKilled(MVEnum::Characters character);
	void characterStolen(MVEnum::Characters character);

	shared_ptr<MVPlayer> getPlayer(MVEnum::Characters character);
	shared_ptr<MVPlayer> getPlayer(shared_ptr<Socket> socket) const;

	shared_ptr<MVPlayer> getKing();
	void setKing(shared_ptr<MVPlayer> player);
	shared_ptr<MVPlayer> getOtherPlayer(shared_ptr<MVPlayer> player);
	void shuffleCharacterDeck();
	void shuffleBuildingDeck();

	MVDeck<MVCharacter> getCharacterDeck();
	void mergeCharacters();


private:

	stack<shared_ptr<MVGameState>> states;
	MVEnum::Characters killed;
	MVEnum::Characters stolenFrom;

	void restart();

	MVGame();
	shared_ptr<MVPlayer> king;
	static shared_ptr<MVGame> instance;
	static bool running;
	int turn;
	vector<shared_ptr<MVPlayer>> players;
	queue<unique_ptr<MVCoin>> coins;
	MVDeck<MVCharacter> characterDeck;
	MVDeck<MVCharacter> usedCharacterDeck;
	MVDeck<MVBuilding> buildingDeck;
	MVDeck<MVBuilding> usedBuildingDeck;

	static default_random_engine dre;
};

