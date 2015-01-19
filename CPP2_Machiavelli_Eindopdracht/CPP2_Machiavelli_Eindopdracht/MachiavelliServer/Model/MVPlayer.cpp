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
