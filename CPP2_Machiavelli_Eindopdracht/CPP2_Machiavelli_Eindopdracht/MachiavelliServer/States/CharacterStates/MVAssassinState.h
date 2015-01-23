#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVAssassinState :
	public MVCharacterState
{
public:
	MVAssassinState(shared_ptr<MVGame> game);
	virtual ~MVAssassinState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;

	void killCharacter(shared_ptr<MVPlayer> player);
};

