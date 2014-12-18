#include "MVBuilding.h"


MVBuilding::MVBuilding(string name, int cost, MVEnum::Colors color) : cost{ cost }, color{ color }, MVCard(name)
{

}


MVBuilding::~MVBuilding()
{

}

int MVBuilding::getPoints() const
{
	return cost;
}

MVEnum::Colors MVBuilding::getColor() const
{
	return color;
}