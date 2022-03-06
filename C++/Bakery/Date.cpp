#include "Date.h"

Date::Date() :Day(1), Month(1), Year(2020)
{
	cout << "In Date()" << endl;
}

//Date::Date(const Date &d)
//{
//	cout << "In Date(const Date &)" << endl;
//	*this = d;
//
//}
//const Date&Date::operator=(const Date &d)
//{
//	
//	if (this != &d)
//	{
//		this->Day = d.Day;
//		this->Month = d.Month;
//		this->Year = d.Year;
//	}
//	cout << "In Date operator=" << endl;
//	return *this;
//}

void Date::setDate(int day, int month, int year) noexcept(false)
{
	if ((day >= 1) && (day <= 31))
	{
		Day = day;
	}
	else
	{
		this->Day = -1;
		throw "Invalid day";
	}

	if ((month >= 1) && (month <= 12))
	{
		Month = month;
	}
	else
	{
		this->Month = -1;
		throw "Invalid day";
	}
	Year = year;

}

bool Date::operator==(const Date &d)
{
	return (this->Day == d.Day) && (this->Month == d.Month) && (this->Year == d.Year);
}

ostream& operator<<(ostream&out, const Date &d)
{
	cout << d.Day << "/" << d.Month << "/" << d.Year;
	return out;
}

//new functions
//Date::~Date()
//{
//	cout << "In~Date()" <<endl;
//}

bool Date::operator<(const Date & d) const
{
	if (this->Year < d.Year)
		return false;
	else if (this->Year > d.Year)
		return true;
	else//the year is equal!
	{
		if (this->Month < d.Month)
			return false;
		else if (this->Month > d.Month)
			return true;
		else//the month is equal!
		{
			if (this->Day < d.Day)
				return false;
			return true;
		}
	}
}
