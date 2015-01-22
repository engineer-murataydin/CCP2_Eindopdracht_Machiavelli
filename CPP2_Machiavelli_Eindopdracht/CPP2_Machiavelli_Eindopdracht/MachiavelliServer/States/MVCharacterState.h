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
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual bool canEndTurn();
	virtual vector<MVEnum::Action> getActions() const;
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);

protected:
	bool special;
	bool actionOne;

	bool done;

	int build;

	virtual bool canBuild() const;
	void buildBuilding(shared_ptr<MVPlayer> player, shared_ptr<MVBuilding> building);
	void Details(shared_ptr<MVPlayer> player);
	void ChooseGold(shared_ptr<MVPlayer> player);
	void ChooseCards(shared_ptr<MVPlayer> player);
	void Build(shared_ptr<MVPlayer> player);


	MVEnum::Characters character;
};

