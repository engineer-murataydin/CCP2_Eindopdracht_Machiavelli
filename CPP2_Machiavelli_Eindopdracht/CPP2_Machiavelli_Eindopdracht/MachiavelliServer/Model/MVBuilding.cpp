#include "MVBuilding.h"
#include "../Enum/MVEnum.h"
#include <sstream>

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

string MVBuilding::getColorString() const
{
	return MVEnum::colorToString(getColor());
}

string MVBuilding::toString() const
{
	stringstream s;
	s << getName() << " (" << getColorString() << ", " << getPrice() << "):";
	return s.str();
}
