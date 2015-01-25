#include "MVFinishState.h"


MVFinishState::MVFinishState()
{
}


MVFinishState::~MVFinishState()
{
}

void MVFinishState::update(shared_ptr<MVPlayer> player, int message)
{

}

void MVFinishState::render(shared_ptr<MVPlayer> player) const
{
	if (player == Winner)
	{
		Win(player);
	}
	else
	{
		Lose(player);
	}
}

void MVFinishState::onEnter()
{
	cerr << "Enter FinishState" << endl;
	vector<shared_ptr<MVPlayer>> players = game->getPlayers();
	Winner = players.front();
	for (size_t i = 0; i < players.size(); i++)
	{
		if (players[i]->getScore() > Winner->getScore())
		{
			Winner = players[i];
		}
	}

}

void MVFinishState::onExit()
{
	cerr << "Exit FinishState" << endl;

}

void MVFinishState::checkState()
{

}


void MVFinishState::Win(shared_ptr<MVPlayer> player) const
{
	player->writeLine("Je hebt gewonnen");
}

void MVFinishState::Lose(shared_ptr<MVPlayer> player) const
{
	player->writeLine("Je hebt verloren");
}