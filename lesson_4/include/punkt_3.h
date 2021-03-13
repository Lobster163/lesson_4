#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Suit
{
	spades = 0,
	clubs,
	diamonds,
	hearts
};

enum class Rank
{
	_2 = 2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	_10,
	_V = 20,
	_Q = 21,
	_K = 22,
	_A = 1
};

class Card
{
private:
	Suit m_Suit;
	Rank m_Rank;
	bool m_IsFaceUp;
public:
	Card() : m_Suit(Suit::clubs), m_Rank(Rank::_2), m_IsFaceUp(false) {};
	Card(Rank valueCard, Suit suit) : m_Rank(valueCard), m_Suit(suit), m_IsFaceUp(false) {};
	~Card(); //добавил после 5 занятия
	bool Flip();
	int GetValue();
	string GetName();
};

class Hand
{
	private:
		std::vector<Card*> m_Cards;
	public:
		~Hand();//добавил после 5 занятия
		void Add(Card* pCard);
		void Clear();
		int GetTotal();
		int GetValue();
		string GetName(int numberCard);
};