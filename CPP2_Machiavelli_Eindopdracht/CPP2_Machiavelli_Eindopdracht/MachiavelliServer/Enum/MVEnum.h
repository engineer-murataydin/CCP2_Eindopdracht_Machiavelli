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
		UNKNOWN_COLOR = -1, GEEL, BLAUW, GROEN, ROOD, LILA
	};
	static Colors getColor(string color);
	static string colorToString(Colors color);

	enum Characters
	{
		UNKNOWN_CHARACHTER = -1, MOORDENAAR, DIEF, MAGIER, KONING, PREDIKER, KOOPMAN, BOUWMEESTER, CONDOTTIERE 
	};
	static Characters getCharacter(string character);
	static string characterToString(Characters character);

	enum Messages
	{
		UNKNOWN_MESSAGE = -1, CONNECTED, DISCONNECTED, DISCONNECTED_PLAYER
	};
	static Messages getMessage(string message);
	static string messageToString(Messages message);
};

