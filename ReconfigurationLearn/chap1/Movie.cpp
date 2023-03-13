#include "Movie.h"

Movie::Movie(string title, int priceCode)
{
	m_title = title;
	m_priceCode = priceCode;
}

Movie::Movie(const Movie& m)
{
	m_title = m.m_title;
	m_priceCode = m.m_priceCode;
}

Movie& Movie::operator=(const Movie& other)
{
	m_title = other.m_title;
	m_priceCode = other.m_priceCode;
	return *this;
}

int Movie::GetPriceCode() const
{
	return m_priceCode;
}

string Movie::GetTitle() const
{
	return m_title;
}

void Movie::SetPriceCode(int priceCode)
{
	m_priceCode = priceCode;
}
