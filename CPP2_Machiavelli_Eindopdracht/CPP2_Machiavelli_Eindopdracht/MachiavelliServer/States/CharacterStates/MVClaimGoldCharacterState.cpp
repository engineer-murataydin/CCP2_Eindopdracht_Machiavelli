#include "MVClaimGoldCharacterState.h"


MVClaimGoldCharacterState::MVClaimGoldCharacterState(shared_ptr<MVGame> game, MVEnum::Characters character, MVEnum::Colors color) :MVCharacterState(game, character), color(color)
{
}


MVClaimGoldCharacterState::~MVClaimGoldCharacterState()
{
}
