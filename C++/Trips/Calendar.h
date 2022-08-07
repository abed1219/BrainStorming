#ifndef Calendar_h
#define Calendar_h
#include "Date.h"
#include "Holiday.h"
#include <iostream>
#include <string>

//Calendar inherits from date and holds date with number of tags to that date (number of holidays this date attached to)

class Calendar : public Date {

    int numOfTags; // number of tags for each date

public:
    Calendar();
    Calendar(int day, char* month, int year, int numoftags = 10);
    void show()const; // show calendar
    ~Calendar();

    void operator+=(int Tags); // add tags to this date

    int getNumOfTags() { return numOfTags; };
    void setNumOfTags(int num);
};


#endif /* Calendar_h */
