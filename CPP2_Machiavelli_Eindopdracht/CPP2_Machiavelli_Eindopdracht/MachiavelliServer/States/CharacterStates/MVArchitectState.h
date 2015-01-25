#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVArchitectState :
	public MVCharacterState
{
public:
	MVArchitectState();
	virtual ~MVArchitectState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;

protected:

	void getCards(shared_ptr<MVPlayer> player);
	bool canBuild() const;
};

