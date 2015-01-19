//
#include "MVSpecialBuilding.h"
#include "../Enum/MVEnum.h"

//

//
using namespace std;

MVSpecialBuilding::MVSpecialBuilding(string name, int price, MVEnum::Colors color, string description) : description{ description }, MVBuilding(name, price, color)
{
}


MVSpecialBuilding::~MVSpecialBuilding()
{
}
