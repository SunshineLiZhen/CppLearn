#pragma once
#include <string>

using namespace std;


class Movie
{
private:
	string m_title;
	int m_priceCode = 0;

public:
	static enum
	{
		Childrens,
		Regular,
		NewRelease
	};

	Movie() {}

	Movie(string title, int priceCode);
	
	Movie(const Movie& m);

	Movie& operator = (const Movie& other);

	int GetPriceCode() const;

	string GetTitle() const;

	void SetPriceCode(int priceCode);
};

