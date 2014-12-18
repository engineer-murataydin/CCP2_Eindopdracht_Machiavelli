#pragma once

#include <string>

using namespace std;

class MVEnum
{
public:
	MVEnum();
	~MVEnum();

	enum Colors
	{
		Yellow, Blue, Green, Red, Lilac
	};

	static string enumToString(Colors color);
};

