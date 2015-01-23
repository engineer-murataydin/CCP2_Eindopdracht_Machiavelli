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

	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

