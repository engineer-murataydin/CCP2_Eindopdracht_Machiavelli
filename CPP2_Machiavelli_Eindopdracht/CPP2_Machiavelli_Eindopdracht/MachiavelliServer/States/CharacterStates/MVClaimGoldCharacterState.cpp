#include "MVClaimGoldCharacterState.h"

MVClaimGoldCharacterState::MVClaimGoldCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character, MVEnum::Colors color) :MVCharacterState(game, character), color(color)
{
}


MVClaimGoldCharacterState::~MVClaimGoldCharacterState()
{
}


void MVClaimGoldCharacterState::update(shared_ptr<MVPlayer> player, int message)
{
	message--;
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::CLAIM_GOLD:
			ClaimGold(player);
			break;
		default:
			MVCharacterState::update(player, message);
			return;
		}

	}
}

void MVClaimGoldCharacterState::ClaimGold(shared_ptr<MVPlayer> player)
{
	if (player->addCoins(player->getBuildCardAmount(color)))
	{
		special = false;
	}
}

vector<MVEnum::Action> MVClaimGoldCharacterState::getActions() const
{
	vector<MVEnum::Action> actions = MVCharacterState::getActions();

	if (special)
	{
		actions.push_back(MVEnum::CLAIM_GOLD);
	}
	return actions;
}
