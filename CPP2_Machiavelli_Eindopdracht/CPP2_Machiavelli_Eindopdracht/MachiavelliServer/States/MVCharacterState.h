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
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual bool canEndTurn();
	virtual vector<string> getActions() const;
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);

protected:
	bool special;
	bool actionOne;

	bool done;

	int build;

	virtual bool canBuild() const;
	void buildBuilding(shared_ptr<MVPlayer> player, shared_ptr<MVBuilding> building);

	MVEnum::Characters character;
};

