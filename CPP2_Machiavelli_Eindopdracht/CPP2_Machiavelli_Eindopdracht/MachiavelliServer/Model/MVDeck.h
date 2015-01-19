#pragma once
#include <memory>
#include <vector>

template<typename T>
class MVDeck
{
public:
	MVDeck(){};
	virtual ~MVDeck(){};
	void AddCard(unique_ptr<T> card)
	{
		deck.push_back(card);
	};

	void shuffle()
	{

	};

	unique_ptr<T> getTopCard()
	{
		unique_ptr<T> card;

		return card;
	};

private:
	vector<unique_ptr<T>> deck;
};

