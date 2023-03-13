#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Rental.h"

using namespace std;

class Customer
{
private:
	string m_name;
	vector<Rental> m_rentalList;

public:
	string GetName() const;

	// Ω·À„
	string Statement();

	double GetTotalCharge() const;
	int GetTotalFrequentRenterPoints() const ;
};

