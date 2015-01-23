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
	MVMerchantState(shared_ptr<MVGame> game);
	virtual ~MVMerchantState();
	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();
	virtual vector<MVEnum::Action> getActions() const;
};

