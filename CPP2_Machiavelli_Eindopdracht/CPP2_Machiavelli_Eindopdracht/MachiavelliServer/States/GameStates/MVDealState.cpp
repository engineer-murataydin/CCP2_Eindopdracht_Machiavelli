//
#include "MVDealState.h"
#include <sstream>

//

//

MVDealState::MVDealState(shared_ptr<MVGame> game) : MVGameState(game)
{}

MVDealState::~MVDealState()
{}

void MVDealState::update(shared_ptr<MVPlayer> player, string message)
{
	player->addCharacterCard(game->getCharacter(stoi(message)));
}

void MVDealState::checkState()
{

}

void MVDealState::render(shared_ptr<MVPlayer> player) const
{
	player->print();
	stringstream s;

}

void MVDealState::onEnter()
{
	cerr << "Enter DealState" << endl;
	vector<shared_ptr<MVPlayer>> players = MVGame::Instance()->getPlayers();
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->writeLine(MVEnum::messageToString(MVEnum::START_GAME));
	}
	game->getKing()->writeLine(MVEnum::messageToString(MVEnum::YOU_ARE_THE_KING));
	game->shuffleCharacterDeck();
	game->getKing()->writeLine(MVEnum::messageToString(MVEnum::CHARACTER_CARDS_SHUFFLED));
	game->getKing()->writeLine(MVEnum::messageToString(MVEnum::TOP_CARD_OF_DECK));
	shared_ptr<MVCharacter> mvc = game->getCharacter();
	game->getKing()->writeLine(mvc->getName());
	game->setCharacterCard(mvc);
	vector<shared_ptr<MVCharacter>> characterCards = MVGame::Instance()->getCharacterDeck().getDeck();
	game->getKing()->writeLine(MVEnum::messageToString(MVEnum::CARD_ON_TABLE));
	game->getKing()->writeLine(MVEnum::messageToString(MVEnum::CARD_OVERVIEW_FULL));
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		MVGame::Instance()->getKing()->writeLine(to_string(i + 1) + ". " + characterCards[i]->getName());
	}
	game->getKing()->writeLine(MVEnum::messageToString(MVEnum::CHOOSE_CARD));
	//game->getKing()->addCharacterCard();

}

void MVDealState::onExit()
{
	cerr << "Exit DealState" << endl;
}