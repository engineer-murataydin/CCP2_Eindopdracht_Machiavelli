//
#include "MVDealState.h"
#include <sstream>
#include "../CharacterStates/MVAssassinState.h"

//

//

MVDealState::MVDealState(shared_ptr<MVGame> game) : MVGameState(game)
{}

MVDealState::~MVDealState()
{}

void MVDealState::update(shared_ptr<MVPlayer> player, int message)
{
	shared_ptr<MVCharacter> chosen = game->getCharacter(message - 1);
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

	characterCards = MVGame::Instance()->getCharacterDeck().getDeck();
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		stringstream s;
		s << "[" << to_string(i + 1) << "] " << characterCards[i]->getName();
		curPlayer->writeLine(s.str());
	}
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CHOOSE_CARD));

}

void MVDealState::checkState()
{
	if (game->getCharacterDeck().getDeck().size() == 0)
	{
		game->setState(shared_ptr<MVAssassinState>(new MVAssassinState(game)));
	}
}

void MVDealState::render(shared_ptr<MVPlayer> player) const
{
	player->print();
	stringstream s;

}

void MVDealState::onEnter()
{
	cerr << "Enter DealState" << endl;
	hasChosenCard = false;
	curPlayer = game->getKing();
	vector<shared_ptr<MVPlayer>> players = MVGame::Instance()->getPlayers();
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->writeLine(MVEnum::messageToString(MVEnum::START_GAME));
	}
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::YOU_ARE_THE_KING));
	game->shuffleCharacterDeck();
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CHARACTER_CARDS_SHUFFLED));
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::TOP_CARD_OF_DECK));
	shared_ptr<MVCharacter> mvc = game->getCharacter();
	curPlayer->writeLine(mvc->getName());
	game->setCharacterCard(mvc);
	vector<shared_ptr<MVCharacter>> characterCards = MVGame::Instance()->getCharacterDeck().getDeck();
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CARD_ON_TABLE));
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CARD_OVERVIEW_FULL));
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		curPlayer->writeLine("[" + to_string(i + 1) + "] " + characterCards[i]->getName());
	}
	curPlayer->writeLine(MVEnum::messageToString(MVEnum::CHOOSE_CARD));
}

void MVDealState::onExit()
{
	cerr << "Exit DealState" << endl;
}

bool MVDealState::isCurrentPlayer(shared_ptr<MVPlayer>player)
{
	return player == curPlayer;
}