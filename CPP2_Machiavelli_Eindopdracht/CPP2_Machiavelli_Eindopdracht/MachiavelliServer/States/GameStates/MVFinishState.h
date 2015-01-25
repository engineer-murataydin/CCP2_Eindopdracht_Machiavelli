#pragma once
#include "../MVGameState.h"
class MVFinishState :
	public MVGameState
{
public:
	MVFinishState();
	virtual ~MVFinishState();

	virtual void update(shared_ptr<MVPlayer> player, int message);
	virtual void render(shared_ptr<MVPlayer> player) const;
	virtual void onEnter();
	virtual void onExit();
	virtual void checkState();

protected:
	shared_ptr<MVPlayer> Winner;

	void Win(shared_ptr<MVPlayer> player) const;
   void Lose(shared_ptr<MVPlayer> player) const;
};

