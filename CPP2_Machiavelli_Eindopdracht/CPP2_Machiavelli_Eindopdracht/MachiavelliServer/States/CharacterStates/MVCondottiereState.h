#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVCondottiereState :
	public MVCharacterState
{
public:
	MVCondottiereState(shared_ptr<MVGame> game);
	virtual ~MVCondottiereState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();

	void takeCharacterCard(MVEnum::Characters characterTake);

protected:
};

