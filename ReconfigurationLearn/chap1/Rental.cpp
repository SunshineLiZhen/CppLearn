#include "Rental.h"

Rental::Rental(Movie& name, int rentalDay)
{
	m_movieName = name;
	m_rentalDay = rentalDay;
}

Movie Rental::GetMovie() const
{
	return m_movieName;
}

int Rental::GetDaysRented() const
{
	return m_rentalDay;
}

double Rental::GetCharge() const
{
	double charge = 0;
	switch (GetMovie().GetPriceCode()) { // ȡ��ӰƬ����۸�
	case Movie::Regular: // ��ͨƬ
		charge += 2;
		if (GetDaysRented() > 2)
			charge += (GetDaysRented() - 2) * 1.5;
		break;
	case Movie::NewRelease: // ��Ƭ
		charge += GetDaysRented() * 3;
		break;
	case Movie::Childrens: // ��ͯ��
		charge += 1.5;
		if (GetDaysRented() > 3)
			charge += (GetDaysRented() - 3) * 1.5;
		break;
	}

	return charge;
}

int Rental::GetFrequentRenterPoints() const
{
	int frequentRenterPoints = 0;
	frequentRenterPoints++;
	// add bonus for a two day new release rental
	if ( (GetMovie().GetPriceCode() == Movie::NewRelease)
		 && GetDaysRented() > 1)
		frequentRenterPoints++;

	return frequentRenterPoints;
}