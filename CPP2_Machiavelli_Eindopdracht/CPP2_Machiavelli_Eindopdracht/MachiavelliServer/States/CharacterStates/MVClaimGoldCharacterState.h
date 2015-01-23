#pragma once
#include "../MVCharacterState.h"
#include "../../Enum/MVEnum.h"

class MVClaimGoldCharacterState :
	public MVCharacterState
{
public:
	MVClaimGoldCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character, MVEnum::Colors color);
	virtual ~MVClaimGoldCharacterState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	void ClaimGold(shared_ptr<MVPlayer> player);
	virtual vector<MVEnum::Action> getActions() const;

protected:
	MVEnum::Colors color;

};

