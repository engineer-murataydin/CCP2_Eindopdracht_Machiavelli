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
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<string> getActions() const;

	void killCharacter(MVEnum::Characters chosenCharacter);

protected:
	vector<MVEnum::Characters> getPlayersToKill();
};

