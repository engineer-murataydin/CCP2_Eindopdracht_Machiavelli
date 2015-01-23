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
	MVPreacherState(shared_ptr<MVGame> game);
	virtual ~MVPreacherState();
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
};

