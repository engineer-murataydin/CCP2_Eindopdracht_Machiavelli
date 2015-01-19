#pragma once
#include "MVCharacter.h"
#include "MVCoin.h"
#include "MVBuilding.h"
#include <memory>
#include <vector>
#include "../Server/Socket.h"

using namespace std;

class MVPlayer
{
public:
	MVPlayer(Socket* socket);
	~MVPlayer();

	bool isKing() const;
	shared_ptr<Socket> getSocket() const;


private:
	vector<shared_ptr<MVCharacter>> characterCards;
	vector<shared_ptr<MVBuilding>> BuildingCards;
	vector<shared_ptr<MVCoin>> Coins;
	shared_ptr<Socket> socket;

	bool king;
};

