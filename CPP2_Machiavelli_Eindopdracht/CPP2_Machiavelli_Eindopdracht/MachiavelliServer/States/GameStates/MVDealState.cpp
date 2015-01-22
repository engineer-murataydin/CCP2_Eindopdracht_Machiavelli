//
#include "MVDealState.h"

//

//

MVDealState::MVDealState(shared_ptr<MVGame> game) : MVGameState(game)
{}

MVDealState::~MVDealState()
{}

void MVDealState::update(shared_ptr<MVPlayer> player, string message)
{}

void MVDealState::checkState()
{

}

void MVDealState::render(shared_ptr<MVPlayer> player) const
{
	vector<shared_ptr<MVCharacter>> characterCards = MVGame::Instance()->getCharacterDeck().getDeck();

	for (size_t i = 0; i < characterCards.size(); i++)
	{
		MVGame::Instance()->getKing()->writeLine(MVEnum::messageToString(MVEnum::CARD_OVERVIEW_FULL));
		MVGame::Instance()->getKing()->writeLine(characterCards[i]->getName());
	}
}

void MVDealState::onEnter()
{
	cerr << "Enter DealState" << endl;
	vector<shared_ptr<MVPlayer>> players = MVGame::Instance()->getPlayers();
	for (size_t i = 0; i < players.size(); i++)
	{
		players[i]->writeLine(MVEnum::messageToString(MVEnum::START_GAME));
	}
	MVGame::Instance()->getKing()->writeLine(MVEnum::messageToString(MVEnum::YOU_ARE_THE_KING));
	MVGame::Instance()->shuffleCharacterDeck();
	MVGame::Instance()->getKing()->writeLine(MVEnum::messageToString(MVEnum::CHARACTER_CARDS_SHUFFLED));
	//MVGame::Instance()->
}

void MVDealState::onExit()
{
	cerr << "Exit DealState" << endl;
}