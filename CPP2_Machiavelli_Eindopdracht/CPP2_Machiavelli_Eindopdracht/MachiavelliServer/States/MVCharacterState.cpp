//
#include "MVCharacterState.h"
#include <sstream>

//

//

MVCharacterState::MVCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character) : MVGameState(game), character(character)
{}

MVCharacterState::~MVCharacterState()
{}

void MVCharacterState::update(shared_ptr<MVPlayer> player, int message)
{
	switch (getActions()[message-1])
	{
	case MVEnum::DETAILS:
		Details(player);
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

void MVCharacterState::checkState()
{}

void MVCharacterState::render(shared_ptr<MVPlayer> player) const
{
	stringstream s;
	player->writeLine();
	s << "Je bent nu de: " << MVEnum::characterToString(character);
	player->writeLine(s.str());
	player->print();
	player->writeLine("Maak je keuze:");
}

bool MVCharacterState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return game->getPlayer(character) == player;
}

bool MVCharacterState::canEndTurn()
{
	return actionOne;
}

void MVCharacterState::onEnter()
{
	actionOne = true;
	special = true;
}

void MVCharacterState::onExit()
{}

vector<MVEnum::Action> MVCharacterState::getActions() const
{
	vector<MVEnum::Action> actions;
	actions.push_back(MVEnum::DETAILS);

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

void MVCharacterState::buildBuilding(shared_ptr<MVPlayer> player, shared_ptr<MVBuilding> building)
{
	if (canBuild())
	{
		if (player->build(building))
		{
			build++;
		}
	}
}

bool MVCharacterState::canBuild() const
{
	return build < 1;
}

void MVCharacterState::Details(shared_ptr<MVPlayer> player)
{
	stringstream s;
	s << "Andere speler:" << endl;
	s << game->getOtherPlayer(player)->ToString();
	player->writeLine(s.str());
}

void MVCharacterState::ChooseGold(shared_ptr<MVPlayer> player)
{
	if (player->addCoins(2))
		actionOne = false;
}

void MVCharacterState::ChooseCards(shared_ptr<MVPlayer> player)
{
	if (player->addBuildingCards(2))
		actionOne = false;
}

void MVCharacterState::Build(shared_ptr<MVPlayer> player)
{

}
