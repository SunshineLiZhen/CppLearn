#include "Customer.h"

string Customer::GetName() const
{
	return string();
}

double Customer::GetTotalCharge() const
{
	double totalAmount = 0; // 总消费金。
	for (auto it = m_rentalList.begin(); it != m_rentalList.end(); ++it)
	{
		// 计算租金
		totalAmount += it->GetCharge();
	}
}

int Customer::GetTotalFrequentRenterPoints() const
{
	int total = 0; // 总消费金。
	for (auto it = m_rentalList.begin(); it != m_rentalList.end(); ++it)
	{
		total += it->GetFrequentRenterPoints();
	}
}

string Customer::Statement()
{
	string result = "Rental Record for " + GetName() + "\n";
	for (auto it = m_rentalList.begin(); it != m_rentalList.end(); ++it)
	{
		result += "\t" + it->GetMovie().GetTitle() + "\t"
			+ to_string(it->GetCharge()) + "\n";
	}

	// add footer lines（结尾打印）
	result += "Amount owed is " + to_string(GetTotalCharge()) + "\n";
	result += "You earned " + to_string(GetTotalFrequentRenterPoints())
		+ " frequent renter points";
	return result;
}




