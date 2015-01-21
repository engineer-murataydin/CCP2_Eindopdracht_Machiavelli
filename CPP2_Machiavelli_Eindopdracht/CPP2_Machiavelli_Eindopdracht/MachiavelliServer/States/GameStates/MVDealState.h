#pragma once

//
#include "../MVGameState.h"

//

//
using namespace std;

class MVDealState :
	public MVGameState
{
public:
	MVDealState(shared_ptr<MVGame> game);
	virtual ~MVDealState();
	virtual void update(shared_ptr<MVPlayer> player, string message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void checkState();
};

