#pragma once
#include "../MVCharacterState.h"
#include "../../Enum/MVEnum.h"

class MVClaimGoldCharacterState :
	public MVCharacterState
{
public:
	MVClaimGoldCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character, MVEnum::Colors color);
	virtual ~MVClaimGoldCharacterState();

protected:
	MVEnum::Colors color;

};

