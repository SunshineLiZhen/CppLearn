#pragma once
#include <string>
#include "Movie.h"

using namespace std;

//�����Ϣ
class Rental
{
private:
	Movie m_movieName;
	int m_rentalDay;
public:
	Rental(Movie& name, int rentalDay);

	Movie GetMovie() const;

	int GetDaysRented() const;

	double GetCharge() const;

	int GetFrequentRenterPoints() const;
};

