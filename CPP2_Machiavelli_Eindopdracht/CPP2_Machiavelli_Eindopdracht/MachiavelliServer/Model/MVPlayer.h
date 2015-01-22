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

	shared_ptr<Socket> getSocket() const;
	vector<shared_ptr<MVCharacter>> getCharacterCards() const;
	bool HasCharacterCard(MVEnum::Characters id) const;
	void write(string msg);
	void writeLine(string msg);
	bool addCoin();
	bool addCoins(int amount);
	bool addBuildingCard();
	bool addBuildingCards(int amount);

private:
	vector<shared_ptr<MVCharacter>> characterCards;
	vector<shared_ptr<MVBuilding>> BuildingCards;
	vector<shared_ptr<MVBuilding>> BuildBuildings;
	queue<unique_ptr<MVCoin>> Coins;
	shared_ptr<Socket> socket;
};

