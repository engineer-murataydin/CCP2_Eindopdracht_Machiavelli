#pragma once
#include <memory>
#include <vector>
#include <algorithm>

template<typename T>
class MVDeck
{
public:
	MVDeck(){};
	virtual ~MVDeck(){};
	void AddCard(unique_ptr<T> card)
	{
		deck.push_back(move(card));
	};

	void shuffle()
	{
		random_shuffle(deck.begin(), deck.end());
	};

	unique_ptr<T> moveTopCard()
	{
		return moveCardAt(0);
	};

	unique_ptr<T> moveCardAt(int index)
	{
		unique_ptr<T> card(move(deck[index]));
		deck.erase(deck.begin() + index);
		return card;
	};

	void mergeDeck(MVDeck<T> deck)
	{
		while (deck.HasCard())
		{
			this->deck.push_back(move(deck.getTopCard()));
		}
	};

	bool HasCard()
	{
		return !deck.empty();
	};

private:
	vector<unique_ptr<T>> deck;
};

