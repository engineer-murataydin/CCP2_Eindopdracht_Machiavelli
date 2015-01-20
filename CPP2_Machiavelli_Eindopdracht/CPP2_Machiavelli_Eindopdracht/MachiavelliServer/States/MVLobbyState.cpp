#include "MVLobbyState.h"
#include "MVDealState.h"


MVLobbyState::MVLobbyState(shared_ptr<MVGame> game) :MVGameState(game)
{
}


MVLobbyState::~MVLobbyState()
{
}

void MVLobbyState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVLobbyState::checkState()
{
	if (game->getPlayers().size() >= 2)
	{
		game->setState(unique_ptr<MVDealState>(new MVDealState(game)));
	}
}

void MVLobbyState::render(shared_ptr<MVPlayer> player) const
{
	player->write("Wachten op andere speler\n\r");
}