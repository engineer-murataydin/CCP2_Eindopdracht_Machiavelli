#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVThiefState :
	public MVCharacterState
{
public:
	MVThiefState();
	virtual ~MVThiefState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;

	void robCharacter(shared_ptr<MVPlayer> player);

protected:
};

