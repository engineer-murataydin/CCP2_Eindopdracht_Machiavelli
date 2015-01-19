#include "MVCharacter.h"

MVCharacter::MVCharacter(int order, string name) : MVCard(name), order(order)
{}

MVCharacter::~MVCharacter()
{}

int MVCharacter::getOrder() const
{
	return order;
}
