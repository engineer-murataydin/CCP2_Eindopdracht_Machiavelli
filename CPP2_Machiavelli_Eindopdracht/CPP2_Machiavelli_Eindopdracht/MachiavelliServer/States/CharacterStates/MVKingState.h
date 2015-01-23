#pragma once

//
#include "MVClaimGoldCharacterState.h"

//

//
using namespace std;

class MVKingState :
	public MVClaimGoldCharacterState
{
public:
	MVKingState(shared_ptr<MVGame> game);
	virtual ~MVKingState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;
};

