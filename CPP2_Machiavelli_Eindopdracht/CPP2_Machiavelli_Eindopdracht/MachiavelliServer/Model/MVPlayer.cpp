#include "MVPlayer.h"


MVPlayer::MVPlayer(Socket* socket)
{
	this->socket = shared_ptr<Socket>(socket);
}


MVPlayer::~MVPlayer()
{
}


bool MVPlayer::isKing() const
{
	return king;
}

shared_ptr<Socket> MVPlayer::getSocket() const
{
	return socket;
}

bool MVPlayer::HasCharacterCard(int id) const
{
	for (size_t i = 0; i < characterCards.size(); i++)
	{
		if (characterCards[i]->getOrder() == id)
		{
			return true;
		}
	}
	return false;
}

vector<shared_ptr<MVCharacter>> MVPlayer::getCharacterCards() const
{
	return characterCards;
}

void MVPlayer::write(string msg)
{
	try
	{
		socket->write(msg);
	}
	catch (...)
	{
	}
}

void MVPlayer::setKing(bool value)
{
	king = value;
}