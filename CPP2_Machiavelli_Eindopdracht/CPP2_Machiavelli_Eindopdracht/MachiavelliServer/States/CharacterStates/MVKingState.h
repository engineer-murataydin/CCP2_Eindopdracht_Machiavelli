#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVKingState :
	public MVCharacterState
{
public:
	MVKingState(shared_ptr<MVGame> game);
	virtual ~MVKingState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
};

