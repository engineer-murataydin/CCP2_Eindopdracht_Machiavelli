//
#include <string>

//
#include "MVEnum.h"

//
using namespace std;

MVEnum::MVEnum() {}

MVEnum::~MVEnum() {}

MVEnum::Colors MVEnum::getColor(string color)
{
	for (int i = GEEL; i <= LILA; i++)
	{
		Colors tempColor = static_cast<Colors>(i);
		if (colorToString(tempColor) == color)
		{
			return tempColor;
		}
	}
	return UNKNOWN;
}

string MVEnum::colorToString(Colors color)
{
	switch (color)
	{
	case MVEnum::GEEL:
		return "geel";
	case MVEnum::BLAUW:
		return "blauw";
	case MVEnum::GROEN:
		return "groen";
	case MVEnum::ROOD:
		return "rood";
	case MVEnum::LILA:
		return "lila";
	default:
		break;
	}
}