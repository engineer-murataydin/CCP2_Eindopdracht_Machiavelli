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
	void AddCard(shared_ptr<T> card)
	{
		deck.push_back(card);
	};

	void shuffle()
	{
		random_shuffle(deck.begin(), deck.end());
	};

	shared_ptr<T> moveTopCard()
	{
		return moveCardAt(0);
	};

	shared_ptr<T> moveCardAt(int index)
	{
		shared_ptr<T> card(deck[index]);
		deck.erase(deck.begin() + index);
		return card;
	};

	void mergeDeck(MVDeck<T> deck)
	{
		while (deck.HasCard())
		{
			this->deck.push_back(deck.getTopCard());
		}
	};

	bool HasCard()
	{
		return !deck.empty();
	};

	int size()
	{
		return deck.size();
	}

	vector<shared_ptr<T>> getDeck()
	{
		return deck;
	}

private:
	vector<shared_ptr<T>> deck;
};

