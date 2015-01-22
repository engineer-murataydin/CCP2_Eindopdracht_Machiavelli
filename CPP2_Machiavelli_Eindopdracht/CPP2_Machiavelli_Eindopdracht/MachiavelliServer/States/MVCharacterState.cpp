//
#include "MVCharacterState.h"
#include <sstream>

//

//

MVCharacterState::MVCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character) : MVGameState(game), character(character)
{}

MVCharacterState::~MVCharacterState()
{}

void MVCharacterState::update(shared_ptr<MVPlayer> player, string message)
{}

void MVCharacterState::checkState()
{}

void MVCharacterState::render(shared_ptr<MVPlayer> player) const
{
	stringstream s;
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

vector<string> MVCharacterState::getActions() const
{
	vector<string> actions;
	actions.push_back("Bekijk het goud en de gebouwen van de tegenstander");

	if (actionOne)
	{
		actions.push_back("Neem 2 goudstukken");
		actions.push_back("Neem 2 bouwkaarten en leg er 1 af");
	}
	if (canBuild())
	{
		actions.push_back("Plaats een gebouw");
	}
	if (special)
	{
		actions.push_back("Maak gebruik van de karaktereigenschap van de " + MVEnum::characterToString(character));
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