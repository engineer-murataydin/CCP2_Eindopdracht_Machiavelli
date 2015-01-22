//
#include "MVSpecialBuilding.h"
#include "../Enum/MVEnum.h"
#include <sstream>

//

//
using namespace std;

MVSpecialBuilding::MVSpecialBuilding(string name, int price, MVEnum::Colors color, string description) : description{ description }, MVBuilding(name, price, color)
{}

MVSpecialBuilding::~MVSpecialBuilding()
{}

string MVSpecialBuilding::getDescription() const
{
	return description;
}

string MVSpecialBuilding::toString() const
{
	stringstream s;
	s << getName() << " (" << getColorString() << ", " << getPrice() << ", " << getDescription() << ")";
	return s.str();
}
