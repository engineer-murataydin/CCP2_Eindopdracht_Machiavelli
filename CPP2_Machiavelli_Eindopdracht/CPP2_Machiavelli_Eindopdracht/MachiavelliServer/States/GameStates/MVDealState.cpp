//
#include "MVDealState.h"
#include <sstream>
#include "../CharacterStates/MVAssassinState.h"
#include "MVFinishState.h"


//

//

MVDealState::MVDealState()
{}

MVDealState::~MVDealState()
{}

void MVDealState::update(shared_ptr<MVPlayer> player, int message)
{
	shared_ptr<MVCharacter> chosen = game->getCharacter(message);
	vector<shared_ptr<MVCharacter>> characterCards = MVGame::Instance()->getCharacterDeck().getDeck();
	if (chosen)
	{
		if (!hasChosenCard)
		{
			player->addCharacterCard(chosen);
			curPlayer->writeLine(MVEnum::messageToString(MVEnum::CHOSEN_CARD) + chosen->getName());
			hasChosenCard = true;
			curPlayer = game->getOtherPlayer(curPlayer);
			curPlayer->writeLine(MVEnum::messageToString(MVEnum::TURN_PLAYER));
		}
		else
		{
			hasChosenCard = false;
			game->setCharacterCard(chosen);
			curPlayer->writeLine(MVEnum::messageToString(MVEnum::REMOVED_CARD) + chosen->getName());
		}
	}
}

void MVDealState::checkState()
{
	if (game->getCharacterDeck().getDeck().size() == 0)
	{
		game->setState(shared_ptr<MVAssassinState>(new MVAssassinState()));
	}
}

void MVDealState::render(shared_ptr<MVPlayer> player) const
{
	if (hasChosenCard)
	{
		player->writeLine("Kies een karakter kaart om weg te leggen");
	}
	else
	{
		player->writeLine("Kies een karakter kaart voor jezelf");
	}

	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CARD_OVERVIEW_FULL));
	vector<shared_ptr<MVCharacter>> characterCards = MVGame::Instance()->getCharacterDeck().getDeck();
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		stringstream s;
		s << "[" << to_string(i + 1) << "] " << characterCards[i]->getName();
		curPlayer->writeLine(s.str());
	}
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CHOOSE_CARD));
}

void MVDealState::onEnter()
{
	game->characterKilled(MVEnum::UNKNOWN_CHARACHTER);
	game->characterStolen(MVEnum::UNKNOWN_CHARACHTER);

	vector<shared_ptr<MVPlayer>> players = game->getPlayers();
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->returnCharacters();
		if (players[i]->getBuildCardAmount() >= 8)
		{
			game->setState(shared_ptr<MVFinishState>(new MVFinishState()));
		}
	}

	game->mergeCharacters();


	cerr << "Enter DealState" << endl;
	hasChosenCard = false;
	curPlayer = game->getKing();
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::YOU_ARE_THE_KING));
	game->shuffleCharacterDeck();
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CHARACTER_CARDS_SHUFFLED));
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::TOP_CARD_OF_DECK));
	shared_ptr<MVCharacter> mvc = game->getCharacter();
	curPlayer->writeLine(mvc->getName());
	game->setCharacterCard(mvc);
	vector<shared_ptr<MVCharacter>> characterCards = MVGame::Instance()->getCharacterDeck().getDeck();
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CARD_ON_TABLE));
	render(curPlayer);
}

void MVDealState::onExit()
{
	cerr << "Exit DealState" << endl;
}

bool MVDealState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return player == curPlayer;
}