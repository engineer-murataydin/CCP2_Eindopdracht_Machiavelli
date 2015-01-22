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
	MVArchitectState(shared_ptr<MVGame> game);
	virtual ~MVArchitectState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;
};

