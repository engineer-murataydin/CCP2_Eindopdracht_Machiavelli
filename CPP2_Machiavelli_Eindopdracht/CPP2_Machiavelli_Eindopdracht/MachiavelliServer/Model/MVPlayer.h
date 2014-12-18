#pragma once
#include "MVCharacter.h"
#include "MVCoin.h"
#include "MVBuilding.h"
#include <memory>
#include <vector>

using namespace std;

class MVPlayer
{
public:
	MVPlayer();
	~MVPlayer();

	bool isKing() const;
private:
	vector<shared_ptr<MVCharacter>> characterCards;
	vector<shared_ptr<MVBuilding>> BuildingCards;
	vector<shared_ptr<MVCoin>> Coins;

	bool king;
};

