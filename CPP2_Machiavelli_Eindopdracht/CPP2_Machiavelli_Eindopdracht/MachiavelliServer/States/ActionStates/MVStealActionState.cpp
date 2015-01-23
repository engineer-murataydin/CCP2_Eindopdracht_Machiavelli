#include "MVStealActionState.h"
#include <sstream>

MVStealActionState::MVStealActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player) : MVActionState(game, player)
{
}


MVStealActionState::~MVStealActionState()
{
}

void MVStealActionState::update(shared_ptr<MVPlayer> player, int message)
{
	game->characterStolen(getStealable()[message - 1]);
	game->popState();
}

void MVStealActionState::render(shared_ptr<MVPlayer> player) const
{
	player->writeLine("Van welk character wil je al zijn goud?");
	vector<MVEnum::Characters> characters = getStealable();
	for (size_t i = 0; i < characters.size(); i++)
	{
		stringstream s;
		s << "[" << i + 1 << "] " << MVEnum::characterToString(characters[i]);
		player->writeLine(s.str());
	}
}

void MVStealActionState::onEnter()
{

}

void MVStealActionState::onExit()
{

}

void MVStealActionState::checkState()
{

}

vector<MVEnum::Characters> MVStealActionState::getStealable() const
{
	vector<MVEnum::Characters> characters;
	for (int i = MVEnum::MAGIER; i <= MVEnum::CONDOTTIERE; i++)
	{
		if (i != MVGame::Instance()->getKilled())
		{
			characters.push_back(static_cast<MVEnum::Characters>(i));
		}
	}
	return characters;
}
