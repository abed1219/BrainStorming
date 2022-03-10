#define _CRT_SECURE_NO_WARNINGS
#include "Calendar.h"
#define L4 10


void Calendar::setNumOfTags(int num) {// tags for holidays in a calendar
    this->numOfTags = num;
}

Calendar::Calendar() {
    char month[L4] = "jan";
    this->setDay(1);
    this->setMonth(month);
    this->setYear(CURRENT_YEAR);
}


Calendar::Calendar(int day, char* month, int year, int numoftags) :numOfTags(numoftags) {
    this->setDay(day);
    this->setMonth(month);
    this->setYear(year);
}

void Calendar::show() const {
    cout << day << "/" << month << "/" << year << endl;
}

void Calendar:: operator+=(int Tags) {// add tags
    this->numOfTags += Tags;
}

ostream& operator<<(ostream& out, const Calendar& c) {// print
    c.show();
    return out;
}


Calendar::~Calendar() {

}
