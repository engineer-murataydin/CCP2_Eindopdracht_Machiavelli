//
#include "MVMagicianState.h"

//

//

MVMagicianState::MVMagicianState(shared_ptr<MVGame> game) : MVCharacterState(game)
{
	cerr << "Enter MagicianState" << endl;
}

MVMagicianState::~MVMagicianState()
{
	cerr << "Exit MagicianState" << endl;
}

void MVMagicianState::update(shared_ptr<MVPlayer> player, string message)
{

}

void MVMagicianState::checkState()
{

}

void MVMagicianState::render(shared_ptr<MVPlayer> player) const
{
}

void MVMagicianState::swapPawCards()
{

}

void MVMagicianState::changePawCards()
{

}