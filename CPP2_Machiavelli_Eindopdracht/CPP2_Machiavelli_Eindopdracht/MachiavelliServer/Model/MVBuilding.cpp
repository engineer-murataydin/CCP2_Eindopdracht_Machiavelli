#include "MVBuilding.h"
#include "../Enum/MVEnum.h"

MVBuilding::MVBuilding(string name, int cost, MVEnum::Colors color) : MVCard(name), cost(cost), color(color)
{}

MVBuilding::~MVBuilding()
{}

int MVBuilding::getPrice() const
{
	return cost;
}

MVEnum::Colors MVBuilding::getColor() const
{
	return color;
}
