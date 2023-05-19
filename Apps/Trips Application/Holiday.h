#ifndef Holiday_h
#define Holiday_h
#include <iostream>
#include <cstring>

// Holiday is a class that passport inherits from(the second father)

using namespace std;

class Holiday {

    string name; //holiday month
    int holidayNum; // holiday number

public:

    Holiday();
    Holiday(string name, int holidayNum);
    ~Holiday();

    string getHolidayName() { return name; };
    int getHolidayNum() { return holidayNum; };

    bool operator==(const Holiday& H); // check if its a holiday
    friend ostream& operator<< (ostream& out, const Holiday& H); // print a holiday

    void show(ostream& out)const; // show holiday
    void setHolidayName(string name); // set holiday month
    void setHolidayNum(int num); // set holiday number
};


#endif /* Holiday_h */
