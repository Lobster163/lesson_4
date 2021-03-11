#include "include/punkt_3.h"

bool Card::Flip()
{
	m_IsFaceUp = !m_IsFaceUp;
	return m_IsFaceUp;
}

int Card::GetValue(){return (int)m_Rank;}

string Card::GetName()
{
	switch (m_Rank)
	{
	case Rank::_2:
	case Rank::_3:
	case Rank::_4:
	case Rank::_5:
	case Rank::_6:
	case Rank::_7:
	case Rank::_8:
	case Rank::_9:
	case Rank::_10:
		return std::to_string((int)m_Rank);
	case Rank::_V:
		return "V";
	case Rank::_Q:
		return "Q";
	case Rank::_K:
		return "K";
	case Rank::_A:
		return "T";
	}
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	m_Cards.erase(m_Cards.begin(), m_Cards.end());
}

int Hand::GetTotal(){	return m_Cards.size(); }

int Hand::GetValue()
{
	int sum = 0;
	for (int i = 0; i < GetTotal(); ++i)
	{
		int val = m_Cards[i]->GetValue();
		if (val == 1)
		{
			if (sum < 21)
				sum = sum + 11;
			else
				sum = sum + 1;
		}
		else
		{
			if(val < 20)
				sum = sum + val;
			else
				sum = sum + 10;
		}
	}
	return sum;
}

string Hand::GetName(int numberCard)
{
	return m_Cards[numberCard]->GetName();
}