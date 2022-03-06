#define _CRT_SECURE_NO_WARNINGS
#ifndef DATE
#define DATE
#include <iostream>
using namespace std;

class Date
{
	int Day;
	int Month;
	int Year;

public:
	
	Date();//(1.1.2020)
    void setDate(int day,int month,int year=2020) noexcept(false);
	bool operator==(const Date &d);
	friend ostream& operator<<(ostream&out,const Date &d);
	//Added new functions
	int getDay() const { return Day; };
	int getMonth() const { return Month; };
	int getYear() const { return Year; };
	bool operator <(const Date &d)const;
};

#endif // DATE
