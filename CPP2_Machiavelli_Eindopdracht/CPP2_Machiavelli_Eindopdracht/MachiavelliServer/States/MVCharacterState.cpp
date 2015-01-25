//
#include "MVCharacterState.h"
#include "ActionStates\MVBuildActionState.h"
#include "ActionStates\MVGetCardActionState.h"
#include <sstream>

//

//

MVCharacterState::MVCharacterState(MVEnum::Characters character) : character(character)
{}

MVCharacterState::~MVCharacterState()
{}

void MVCharacterState::update(shared_ptr<MVPlayer> player, int message)
{
	vector<MVEnum::Action> actions = getActions();
	if (message >= 0 && message < actions.size())
	{
		switch (actions[message])
		{
		case MVEnum::DETAILS:
			Details(player);
			return;
		case MVEnum::END_TURN:
			EndTurn();
			return;
		case MVEnum::CHOOSE_GOLD:
			ChooseGold(player);
			return;
		case MVEnum::CHOOSE_CARDS:
			ChooseCards(player);
			return;
		case MVEnum::BUILD:
			Build(player);
		default:
			break;
		}


	}
}

void MVCharacterState::render(shared_ptr<MVPlayer> player) const
{
	stringstream s;
	player->writeLine();
	s << "Je bent nu de: " << MVEnum::characterToString(character);
	player->writeLine(s.str());
	player->print();
	player->writeLine("Maak je keuze:");
	vector<MVEnum::Action> actions = getActions();
	for (size_t i = 0; i < actions.size(); i++)
	{
		stringstream s;
		s << "[" << to_string(i + 1) << "] " << MVEnum::actionToString(actions[i]);
		player->writeLine(s.str());
	}
}

bool MVCharacterState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return game->getPlayer(character) == player;
}

bool MVCharacterState::canEndTurn() const
{
	return !actionOne;
}

void MVCharacterState::onEnter()
{
	shared_ptr<MVPlayer> player = game->getPlayer(character);
	if (player && game->getKilled() != character)
	{
		render(player);
		player->buildInCurrentTurn = 0;
		if (player == game->getPlayer(game->getStolen()))
		{
			player->moveAllCoinsTo(game->getPlayer(MVEnum::DIEF));
		}
		actionOne = true;
		special = true;
		render(player);
	}
	else
	{
		done = true;
		checkState();
	}
}

void MVCharacterState::onExit()
{}

vector<MVEnum::Action> MVCharacterState::getActions() const
{
	vector<MVEnum::Action> actions;
	actions.push_back(MVEnum::DETAILS);
	if (canEndTurn())
	{
		actions.push_back(MVEnum::END_TURN);
	}

	if (actionOne)
	{
		actions.push_back(MVEnum::CHOOSE_GOLD);
		actions.push_back(MVEnum::CHOOSE_CARDS);
	}
	if (canBuild())
	{
		actions.push_back(MVEnum::BUILD);
	}
	return actions;
}


bool MVCharacterState::canBuild() const
{
	return game->getPlayer(character)->buildInCurrentTurn < 1;
}

void MVCharacterState::Details(shared_ptr<MVPlayer> player)
{
	stringstream s;
	player->writeLine("Andere speler:");
	player->writeLine(game->getOtherPlayer(player)->ToString());
}

void MVCharacterState::ChooseGold(shared_ptr<MVPlayer> player)
{
	if (player->addCoins(2))
		actionOne = false;
}

void MVCharacterState::ChooseCards(shared_ptr<MVPlayer> player)
{
	game->pushState(shared_ptr<MVGetCardActionState>(new MVGetCardActionState(player)));
	actionOne = false;
}

void MVCharacterState::Build(shared_ptr<MVPlayer> player)
{
	game->pushState(shared_ptr<MVBuildActionState>(new MVBuildActionState(player)));
}

void MVCharacterState::EndTurn()
{
	done = true;
}
