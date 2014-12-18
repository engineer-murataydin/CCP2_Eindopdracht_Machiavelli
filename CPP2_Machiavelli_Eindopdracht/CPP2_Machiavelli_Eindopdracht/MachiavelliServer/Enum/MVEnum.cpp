#include "MVEnum.h"


MVEnum::MVEnum()
{
}


MVEnum::~MVEnum()
{
}


string MVEnum::enumToString(Colors color)
{
	switch (color)
	{
	case MVEnum::Yellow:
		return "Geel";
	case MVEnum::Blue:
		return "Blauw";
	case MVEnum::Green:
		return "Groen";
	case MVEnum::Red:
		return "Rood";
	case MVEnum::Lilac:
		return "Lilla";
	default:
		return "??";
	}
}