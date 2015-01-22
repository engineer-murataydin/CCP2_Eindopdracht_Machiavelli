#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVPreacherState :
	public MVCharacterState
{
public:
	MVPreacherState(shared_ptr<MVGame> game);
	virtual ~MVPreacherState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

