#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Holiday.h"
#include "Date.h"


void Holiday::setHolidayName(string name) {
    this->name = name;
}
void Holiday::setHolidayNum(int num) {
    this->holidayNum = num;
}

Holiday::Holiday() :name("ABC"), holidayNum(12) {}
Holiday::Holiday(string name, int holidayNum) : name(name), holidayNum(holidayNum) {}



bool Holiday:: operator==(const Holiday& H) {
    return ((this->name == H.name) && this->holidayNum == H.holidayNum);
}

void Holiday::show(ostream& out)const {
    out << "Holiday name: " << name << "Holiday number: " << holidayNum << endl;
}
ostream& operator<< (ostream& out, const Holiday& H) {
    H.show(out);
    return out;
}
Holiday::~Holiday() {

}
