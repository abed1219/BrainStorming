#ifndef Passport_h
#define Passport_h
#include <iostream>
#include <cstring>
#include "LongTravel.h"
#include <list>

/*Passport holds longtravel trips, has a person id and list of cities that the person visited, its a child for holiday as well as longtravel*/

class Passport :public LongTravel, Holiday {

    int personID; // person id
    list<string> CityList; // list of cities

public:

    Passport();
    Passport(int personID, list<string>CityList);
    Passport(int personID, list<string>CityList, string arrival, string departure, Calendar tripDate, double cost, string name = "AIRPORT 1");

    Passport(const Passport& P);
    ~Passport();


    int getPersonId() { return personID; };
    list<string> getCityList() { return CityList; };
    void setPersonId(int personID);
    void setCityList(string City);
    bool operator==(const Passport& P);
    friend ostream& operator<< (ostream& out, Passport& P);

    bool isHoliday(string name);// checks if holiday returns true else false
    void addToList(string city);// add cities to city list
    void showArrival(); // show arrival city code
    void show()const;

};

#endif /* Passport_h */
