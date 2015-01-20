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

	unique_ptr<T> getTopCard()
	{
		unique_ptr<T> card;

		return card;
	};

private:
	vector<unique_ptr<T>> deck;
};

