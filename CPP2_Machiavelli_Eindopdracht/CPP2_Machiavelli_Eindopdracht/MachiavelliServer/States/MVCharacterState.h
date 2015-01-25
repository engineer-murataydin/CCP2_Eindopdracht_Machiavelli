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
	MVCharacterState(MVEnum::Characters character);
	virtual ~MVCharacterState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual bool canEndTurn() const;
	virtual vector<MVEnum::Action> getActions() const;
	virtual bool isCurrentPlayer(shared_ptr<MVPlayer>player);
	void Build();

protected:
	bool special;
	bool actionOne;

	bool done;

	void EndTurn();
	virtual bool canBuild() const;
	void Details(shared_ptr<MVPlayer> player);
	void ChooseGold(shared_ptr<MVPlayer> player);
	void ChooseCards(shared_ptr<MVPlayer> player);
	void Build(shared_ptr<MVPlayer> player);


	MVEnum::Characters character;
};

