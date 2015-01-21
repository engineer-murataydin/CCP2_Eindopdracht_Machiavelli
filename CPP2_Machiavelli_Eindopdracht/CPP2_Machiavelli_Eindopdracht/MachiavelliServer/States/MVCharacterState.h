#pragma once

//
#include <memory>

//
#include "MVGameState.h"

//

class MVCharacterState :
	public MVGameState
{
public:
	MVCharacterState(shared_ptr<MVGame> game);
	virtual ~MVCharacterState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
};

