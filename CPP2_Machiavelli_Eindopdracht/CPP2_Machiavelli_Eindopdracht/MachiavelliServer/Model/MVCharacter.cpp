#include "MVCharacter.h"

MVCharacter::MVCharacter(MVEnum::Characters order, string name) : MVCard(name), order(order)
{}

MVCharacter::~MVCharacter()
{}

MVEnum::Characters MVCharacter::getOrder() const
{
	return order;
}