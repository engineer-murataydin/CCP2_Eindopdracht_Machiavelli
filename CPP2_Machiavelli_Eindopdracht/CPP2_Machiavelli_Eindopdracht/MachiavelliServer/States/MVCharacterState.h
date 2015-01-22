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
	MVCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character);
	virtual ~MVCharacterState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
	virtual bool canEndTurn();
	virtual shared_ptr<MVPlayer> getCurrentPlayer();

protected:
	bool actionOne;
	bool hasBuild;

	bool done;

	MVEnum::Characters character;
};

