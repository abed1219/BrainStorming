#ifndef LongTravel_h
#define LongTravel_h
#include "Document.h"
#include "Calendar.h"
#include <iostream>
#include <cstring>

// LongTravel is an abstract class, that inherits Document, and its a trip out of the borders

class LongTravel : public Document {
protected:
    string name; //airport's name
    string Departure; // departure city code
    string Arrival; // arrival city code
    Calendar TripDate; // long trip's date
    double cost; // trip cost
     
public:
    static int TripsNumber; // Trip number
    LongTravel();
    LongTravel(const LongTravel& LT);
    LongTravel(char* name, long id, int words);
    LongTravel(string Departure, string Arrival, Calendar TripDate, double cost, string name);
    LongTravel(char* name, long id, string Departure, string Arrival, Calendar TripDate, double cost);
    virtual~LongTravel();

    string getDeparture() { return Departure; }
    string getArrival() { return Arrival; }
    string getAirportsName() { return name; }
    double getCost() { return cost; }
    Calendar getDate() { return TripDate; }

    void setAirportsName(string Name);
    void setDeparture(string departure);
    void setArrival(string arrival);
    void setCost(double Cost);
    void setDate(int day, char* month, int year);

    void operator-(Calendar TripDate); // calculate how many days left for the trip
    bool operator>(double cost); // return if the trip's cost is bigger than a given cost
    bool operator==(const LongTravel& LT); // compare two long trips
    const LongTravel& operator=(const LongTravel& LT); // copy a long trip
    friend ostream& operator<< (ostream& out, const LongTravel& LT); //print a long trip
    friend bool Document::Long(); // friend method from document class
    double DiscountDay(double cost); // a specific day that allowes the person to get a 50% discount
    void MinDays(Calendar D); // minimum number of days for each long trip
    int ConvertMonth(Calendar D); // convert month from char to int

    virtual void showArrival() = 0;// pure virtual method

    void show()const; // show method
};


#endif /* LongTravel_h */
