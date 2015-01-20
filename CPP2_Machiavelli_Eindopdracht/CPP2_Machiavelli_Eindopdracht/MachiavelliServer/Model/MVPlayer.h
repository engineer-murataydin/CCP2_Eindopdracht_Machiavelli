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
	virtual ~MVPlayer();

	void setKing(bool value);
	bool isKing() const;
	shared_ptr<Socket> getSocket() const;
	vector<shared_ptr<MVCharacter>> getCharacterCards() const;
	bool HasCharacterCard(int id) const;
	void write(string msg);


private:
	vector<shared_ptr<MVCharacter>> characterCards;
	vector<shared_ptr<MVBuilding>> BuildingCards;
	vector<shared_ptr<MVCoin>> Coins;
	shared_ptr<Socket> socket;

	bool king;
};

