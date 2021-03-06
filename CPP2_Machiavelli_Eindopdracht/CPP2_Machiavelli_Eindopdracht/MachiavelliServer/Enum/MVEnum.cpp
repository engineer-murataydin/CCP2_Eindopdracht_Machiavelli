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
		return "UNKNOWN";
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
	}
	return UNKNOWN_CHARACHTER;
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
		return "UNKNOWN";
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
		return "Verbonden";
	case MVEnum::CONNECTED_PLAYER:
		return "Alle spelers zijn verbonden!";
	case MVEnum::DISCONNECTED:
		return "Verbinding verbroken";
	case MVEnum::DISCONNECTED_PLAYER:
		return "Je tegenstander is gestopt! Verbinding verbroken";
	case MVEnum::READY_GAME:
		return "Machiavelli! Het spel is aan het laden...";
	case MVEnum::START_GAME:
		return "Speel het spel!!! Welkom bij Machiavelli";
	case MVEnum::BUILDING_CARDS_SHUFFLED:
		return "Gebouwkaarten zijn geschud";
	case MVEnum::CHARACTER_CARDS_SHUFFLED:
		return "Karakterkaarten zijn geschud";
	case MVEnum::WAITING_FOR_PLAYER:
		return "Wachten op andere spelers...";
	case MVEnum::YOU_ARE_THE_KING:
		return "Jij bent de koning!";
	case MVEnum::CARD_OVERVIEW_FULL:
		return "Dit zijn alle beschikbare karakter kaarten:";
	case MVEnum::TOP_CARD_OF_DECK:
		return "Dit is de bovenste kaart van de stapel:";
	case MVEnum::CARD_ON_TABLE:
		return "De kaart is weggehaald van de stapel en op tafel geplaatst";
	case MVEnum::CHOOSE_CARD:
		return "Kies een karakter kaartnummer:";
	case MVEnum::CHOSEN_CARD:
		return "Gekozen karakter door jou: ";
	case MVEnum::TURN_PLAYER:
		return "Jij bent aan de beurt. Kies een kaart: ";
	case MVEnum::REMOVED_CARD:
		return "Weggelegd karakter door jou: ";
	default:
		return "UNKNOWN";
	}
}

MVEnum::Action MVEnum::getAction(string action)
{
	for (int i = DETAILS; i <= DESTROY_BUILDING; i++)
	{
		Action tempAction = static_cast<Action>(i);
		if (actionToString(tempAction) == action)
		{
			return tempAction;
		}
	}
	return UNKOWN_ACTION;
}

MVEnum::Action MVEnum::getAction(int id)
{
	for (int i = DETAILS; i <= DESTROY_BUILDING; i++)
	{
		if (i == id)
		{
			return static_cast<Action>(i);
		}
	}
	return UNKOWN_ACTION;
}

string MVEnum::actionToString(MVEnum::Action action)
{
	switch (action)
	{
	case MVEnum::DETAILS:
		return "Bekijk het goud en de gebouwen van de tegenstander";
	case MVEnum::END_TURN:
		return "Eindig beurt";
	case MVEnum::CHOOSE_GOLD:
		return "Neem 2 goudstukken";
	case MVEnum::CHOOSE_CARDS:
		return "Neem 2 bouwkaarten en leg er 1 af";
	case MVEnum::CLAIM_CARDS:
		return "Pak 2 gebouwenkaarten";
	case MVEnum::BUILD:
		return "Plaats een gebouw";
	case MVEnum::KILL:
		return "Kies een character om te vermoorden";
	case MVEnum::STEAL:
		return "Kies een character om al zijn goud te stelen";
	case MVEnum::SWAP_WITH_PLAYER:
		return "Kies een character om al je kaarten mee te ruilen";
	case MVEnum::TRADE_WITH_DECK:
		return "Kies kaarten om in te wisselen met de stapel";
	case MVEnum::CLAIM_GOLD:
		return "Claim extra goudstukken";
	case MVEnum::DESTROY_BUILDING:
		return "Kies een character om een gebouw bij weg te halen";
	default:
		return "UNKNOWN";
	}
}