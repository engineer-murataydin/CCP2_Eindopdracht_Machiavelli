#pragma once

//
#include "MVClaimGoldCharacterState.h"

//

//
using namespace std;

class MVCondottiereState :
	public MVClaimGoldCharacterState
{
public:
	MVCondottiereState();
	virtual ~MVCondottiereState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;

protected:
	bool special2;

	void DestroyBuilding(shared_ptr<MVPlayer> player);
};

