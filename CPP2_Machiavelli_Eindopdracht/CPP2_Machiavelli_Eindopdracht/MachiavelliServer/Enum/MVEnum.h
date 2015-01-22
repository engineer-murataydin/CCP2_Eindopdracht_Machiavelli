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
		UNKNOWN_COLOR = 0,
		GEEL,
		BLAUW,
		GROEN,
		ROOD,
		LILA
	};
	static Colors getColor(string color);
	static string colorToString(Colors color);

	enum Characters
	{
		UNKNOWN_CHARACHTER = 0,
		MOORDENAAR,
		DIEF,
		MAGIER,
		KONING,
		PREDIKER,
		KOOPMAN,
		BOUWMEESTER,
		CONDOTTIERE
	};
	static Characters getCharacter(int id);
	static Characters getCharacter(string character);
	static string characterToString(Characters character);

	enum Messages
	{
		UNKNOWN_MESSAGE = 0,
		CONNECTED,
		CONNECTED_PLAYER,
		DISCONNECTED,
		DISCONNECTED_PLAYER,
		WAITING_FOR_PLAYER,
		READY_GAME,
		START_GAME,
		CHARACTER_CARDS_SHUFFLED,
		BUILDING_CARDS_SHUFFLED,
		YOU_ARE_THE_KING,
		CARD_OVERVIEW_FULL,
		TOP_CARD_OF_DECK,
		CARD_ON_TABLE,
		CHOOSE_CARD,
		CHOSEN_CARD,
		REMOVED_CARD,
		TURN_PLAYER
	};
	static Messages getMessage(string message);
	static string messageToString(Messages message);
};

