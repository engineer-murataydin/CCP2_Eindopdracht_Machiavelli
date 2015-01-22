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
	MVThiefState(shared_ptr<MVGame> game);
	virtual ~MVThiefState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();

	void robCharacter(MVEnum::Characters chosenCharacter);

protected:
};

