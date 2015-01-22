#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVMerchantState :
	public MVCharacterState
{
public:
	MVMerchantState(shared_ptr<MVGame> game);
	virtual ~MVMerchantState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
};

