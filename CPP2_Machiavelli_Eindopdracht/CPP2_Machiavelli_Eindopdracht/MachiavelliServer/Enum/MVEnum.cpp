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
	return UNKNOWN_COLOR;
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

MVEnum::Characters MVEnum::getCharacter(int id)
{
	for (int i = MOORDENAAR; i <= CONDOTTIERE; i++)
	{
		if (i == id)
		{
			return static_cast<Characters>(i);
		}
		return UNKNOWN_CHARACHTER;
	}
}

MVEnum::Characters MVEnum::getCharacter(string character)
{
	for (int i = MOORDENAAR; i <= CONDOTTIERE; i++)
	{
		Characters tempCharacter = static_cast<Characters>(i);
		if (characterToString(tempCharacter) == character)
		{
			return tempCharacter;
		}
	}
	return UNKNOWN_CHARACHTER;
}

string MVEnum::characterToString(Characters character)
{
	switch (character)
	{
	case MVEnum::MOORDENAAR:
		return "Moordenaar";
	case MVEnum::DIEF:
		return "Dief";
	case MVEnum::MAGIER:
		return "Magier";
	case MVEnum::KONING:
		return "Koning";
	case MVEnum::PREDIKER:
		return "Prediker";
	case MVEnum::KOOPMAN:
		return "Koopman";
	case MVEnum::BOUWMEESTER:
		return "Bouwmeester";
	case MVEnum::CONDOTTIERE:
		return "Condottiere";
	default:
		break;
	}
}

MVEnum::Messages MVEnum::getMessage(string message)
{
	for (int i = CONNECTED; i <= DISCONNECTED; i++)
	{
		Messages tempMessage = static_cast<Messages>(i);
		if (messageToString(tempMessage) == message)
		{
			return tempMessage;
		}
	}
	return UNKNOWN_MESSAGE;
}

string MVEnum::messageToString(Messages message)
{
	switch (message)
	{
	case MVEnum::CONNECTED:
		return "Connected";
	case MVEnum::DISCONNECTED:
		return "Disconnected";
	case MVEnum::DISCONNECTED_PLAYER:
		return "Player has disconnected";
	case MVEnum::CARDS_SHUFFLED:
		return "All cards has been shuffled";
	default:
		break;
	}
}