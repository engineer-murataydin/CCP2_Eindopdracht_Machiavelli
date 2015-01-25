#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVMagicianState :
	public MVCharacterState
{
public:
	MVMagicianState();
	virtual ~MVMagicianState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;

	void swapPawCards(shared_ptr<MVPlayer> player);
	void tradePawCards(shared_ptr<MVPlayer> player);
};

