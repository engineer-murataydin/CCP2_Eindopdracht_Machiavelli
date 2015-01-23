#include "MVMurderActionState.h"
#include <sstream>

MVMurderActionState::MVMurderActionState(shared_ptr<MVGame> game, shared_ptr<MVPlayer> player) : MVActionState(game, player)
{}

MVMurderActionState::~MVMurderActionState()
{}

void MVMurderActionState::update(shared_ptr<MVPlayer> player, int message)
{
	switch (getPlayersToKill()[message - 1])
	{
	case MVEnum::DIEF:
		MVGame::Instance()->characterKilled(MVEnum::DIEF);
		break;
	case MVEnum::MAGIER:
		MVGame::Instance()->characterKilled(MVEnum::MAGIER);
		break;
	case MVEnum::KONING:
		MVGame::Instance()->characterKilled(MVEnum::KONING);
		break;
	case MVEnum::PREDIKER:
		MVGame::Instance()->characterKilled(MVEnum::PREDIKER);
		break;
	case MVEnum::KOOPMAN:
		MVGame::Instance()->characterKilled(MVEnum::KOOPMAN);
		break;
	case MVEnum::BOUWMEESTER:
		MVGame::Instance()->characterKilled(MVEnum::BOUWMEESTER);
		break;
	case MVEnum::CONDOTTIERE:
		MVGame::Instance()->characterKilled(MVEnum::CONDOTTIERE);
		break;
	default:
		MVActionState::update(player, message);
		return;
	}
	MVGame::Instance()->popState();
}

void MVMurderActionState::render(shared_ptr<MVPlayer> player) const
{
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		stringstream s;
		s << "[" << to_string(i + 1) << "] " << MVEnum::characterToString(characterCards[i]);
		player->writeLine(s.str());
	}
	player->writeLine(MVEnum::actionToString(MVEnum::KILL));
}

void MVMurderActionState::onEnter()
{
	cerr << "Enter MurderActionState" << endl;
	characterCards = getPlayersToKill();
}

void MVMurderActionState::onExit()
{
	cerr << "Exit MurderActionState" << endl;
}

void MVMurderActionState::checkState()
{

}

vector<MVEnum::Characters> MVMurderActionState::getPlayersToKill()
{
	return{ MVEnum::DIEF, MVEnum::MAGIER, MVEnum::KONING, MVEnum::PREDIKER, MVEnum::KOOPMAN, MVEnum::BOUWMEESTER, MVEnum::CONDOTTIERE };
}
