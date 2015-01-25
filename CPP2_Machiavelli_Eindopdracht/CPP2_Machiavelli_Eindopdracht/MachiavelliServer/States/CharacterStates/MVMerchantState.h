#pragma once

//
#include "MVClaimGoldCharacterState.h"

//

//
using namespace std;

class MVMerchantState :
	public MVClaimGoldCharacterState
{
public:
	MVMerchantState();
	virtual ~MVMerchantState();
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

