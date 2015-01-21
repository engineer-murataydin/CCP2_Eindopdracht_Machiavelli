#pragma once

//
#include "../MVCharacterState.h"

//

//
using namespace std;

class MVDealerState :
	public MVCharacterState
{
public:
	MVDealerState(shared_ptr<MVGame> game);
	virtual ~MVDealerState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
};

