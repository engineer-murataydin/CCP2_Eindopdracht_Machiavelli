#pragma once

//
#include "MVClaimGoldCharacterState.h"

//

//
using namespace std;

class MVPreacherState :
	public MVClaimGoldCharacterState
{
public:
	MVPreacherState();
	virtual ~MVPreacherState();
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

