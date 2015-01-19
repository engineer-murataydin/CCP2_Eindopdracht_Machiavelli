#pragma once

//
#include <string>

//
using namespace std;

class MVEnum
{
public:
	MVEnum();
	~MVEnum();

	enum Colors
	{
		UNKNOWN = -1, GEEL, BLAUW, GROEN, ROOD, LILA
	};
	static Colors getColor(string color);
	static string colorToString(Colors color);
};

