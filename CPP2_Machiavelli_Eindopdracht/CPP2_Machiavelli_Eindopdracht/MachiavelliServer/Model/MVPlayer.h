#pragma once
#include "MVCharacter.h"
#include "MVCoin.h"
#include "MVBuilding.h"
#include <memory>
#include <vector>
#include <queue>
#include "../Server/Socket.h"

using namespace std;

class MVPlayer
{
public:
	MVPlayer(Socket* socket);
	virtual ~MVPlayer();

	int getScore();
	shared_ptr<Socket> getSocket() const;
	vector<shared_ptr<MVCharacter>> getCharacterCards() const;
	bool HasCharacterCard(MVEnum::Characters id) const;
	void write(string msg);
	void writeLine(string msg = "");
	bool addCoin();
	bool addCoins(int amount);
	bool addBuildingCard();
	bool addBuildingCard(shared_ptr<MVBuilding> building);
	bool addBuildingCards(int amount);

	int getCoinAmount();

	bool build(shared_ptr<MVBuilding> building);
	bool destroyBuilding(shared_ptr<MVBuilding> building);

	void print();
	string ToString();

	void addCharacterCard(shared_ptr<MVCharacter> characterCard);
	vector<shared_ptr<MVCharacter>> getCharacterCardsPlayer();
	vector<shared_ptr<MVBuilding>> getBuildingCardsPlayer();
	vector<shared_ptr<MVBuilding>> getBuildBuildingCardsPlayer();
	void returnCharacters();

	int buildInCurrentTurn;

	void moveAllCoinsTo(shared_ptr<MVPlayer>player);
	void swapCards(shared_ptr<MVPlayer> player);

	int getBuildCardAmount(MVEnum::Colors color);
	int getBuildCardAmount();

private:
	vector<shared_ptr<MVCharacter>> characterCards;
	vector<shared_ptr<MVBuilding>> BuildingCards;
	vector<shared_ptr<MVBuilding>> BuildBuildings;
	queue<unique_ptr<MVCoin>> Coins;
	shared_ptr<Socket> socket;
};

