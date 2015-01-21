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
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
};

