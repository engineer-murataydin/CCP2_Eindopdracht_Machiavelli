#pragma once
#include "../MVCharacterState.h"
class MVClaimGoldCharacterState :
public MVCharacterState
{
public:
	MVClaimGoldCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character);
	virtual ~MVClaimGoldCharacterState();

};

