#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Date.h"
#define CURRENT_DAY 23
#define CURRENT_MONTH 2
#define CURRENT_YEAR 2022
#define L1 20

const char monthArr[12][4] = { "jan","feb","mar","apr","may","jun",
                   "jul","aug","sep","oct","nov","dec" };

void Date::setDay(int day) {
    this->day = day;
}
void Date::setMonth(char* month) {
    this->month = new char[strlen(month)];
    strcpy(this->month, month);
}
void Date::setYear(int year) {
    this->year = year;
}

void Date::setDate(int day, char* month, int year = CURRENT_YEAR) noexcept(false) {// set a given date, check if its valid
    if ((day >= 1) && (day <= 31))
    {
        this->day = day;
    }
    else
    {
        this->day = -1;
        throw "Invalid day";
    }
    this->year = year;

    for (int i = 0; i < 12; i++) {
        if (!(strcmp(month, monthArr[i]))) {
            this->month = new char[strlen(month)+1];
            strcpy(this->month, monthArr[i]);
            return;
        }
    }
    throw "invalid month";

}

Date::Date() :day(1), year(2000) { //constructor
    char d[L1] = "jan";
    this->month = new char[4];
    strcpy(this->month, d);
}

Date::Date(int day, char* month, int year) {
    this->day = day;
    this->month = new char[4];
    strcpy(this->month, month);
    this->year = year;
}

Date::Date(const Date& other) :day(other.day), month(other.month), year(other.year) {// copying constructor
    *this = other;
}

const Date& Date::operator=(const Date& other) {//operator =
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    return *this;
}

ostream& operator<<(ostream& out, const Date& p) { //operator <<
    out << p.day << "/" << p.month << "/" << p.year << endl;
    return out;
}

istream& operator>>(istream& in, Date& p) { // operator >>
    cout << "Enter a date: format -> (int/char/int)\n";
    in >> p.day >> p.month >> p.year;
    return in;
}

bool Date::operator>(const Date& other) const { // operator > that checks if the first day is older than the other
    if (this->year > other.year)
        return false;
    else if (this->year < other.year)
        return true;
    else {//the year is equal!
        for (int i = 0; i < 12; i++) {
            int flag1 = 0, flag2 = 0;
            if (!(strcmp(this->month, monthArr[i])))
                flag1++;
            if (!(strcmp(other.month, monthArr[i])))
                flag2++;
            if (flag1 == 1 && flag1 == flag2)
                break;
            else if (flag1 == 1)
                return true;
            else if (flag2 == 1)
                return false;
        }
        if (this->day < other.day)
            return true;
        return false;
    }
}

bool Date::operator==(const Date& other) const {// operator ==, to compare if two dates are the same
    return (this->day == other.day) && !(strcmp(this->month, other.month)) && (this->year == other.year);
}

Date::~Date() {// a destructor that
    this->month = NULL;
    delete[] this->month;
}
