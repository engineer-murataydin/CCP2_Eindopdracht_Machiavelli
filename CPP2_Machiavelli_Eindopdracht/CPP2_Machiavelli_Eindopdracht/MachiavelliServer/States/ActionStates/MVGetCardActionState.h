#pragma once
#include "MVActionState.h"
class MVGetCardActionState :
	public MVActionState
{
public:
	MVGetCardActionState(shared_ptr<MVPlayer> player);
	virtual ~MVGetCardActionState();

	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();

protected:
	vector<shared_ptr<MVBuilding>> cards;

};

