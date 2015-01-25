#include "MVLobbyState.h"
#include "MVDealState.h"

MVLobbyState::MVLobbyState()
{}

MVLobbyState::~MVLobbyState()
{}

void MVLobbyState::update(shared_ptr<MVPlayer> player, int message)
{}

void MVLobbyState::checkState()
{
	if (game->getPlayers().size() >= 2)
	{
		MVGame::Instance()->setState(unique_ptr<MVDealState>(new MVDealState()));
	}
}

void MVLobbyState::render(shared_ptr<MVPlayer> player) const
{
	player->writeLine(MVEnum::messageToString(MVEnum::WAITING_FOR_PLAYER));
}

void MVLobbyState::onEnter()
{
	cerr << "Enter LobbyState" << endl;
}

void MVLobbyState::onExit()
{
	cerr << "Exit LobbyState" << endl;
	game->start();
}