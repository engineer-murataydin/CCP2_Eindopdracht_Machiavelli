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
	MVKingState();
	virtual ~MVKingState();

	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

