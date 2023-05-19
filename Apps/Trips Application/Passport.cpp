#define _CRT_SECURE_NO_WARNINGS
#include "Passport.h"

const char HolidayArr[4][4] = { "jan","feb","jul","dec" };

void Passport::setPersonId(int personID) {
    this->personID = personID;
}

void Passport::setCityList(string City) noexcept(false) {
    for (int i = 0; i < City.length(); i++) {
        if (City[i] >= '0' && City[i] <= '9')
            throw "No numbers allowed in city names!";
    }
    CityList.push_back(City);
}
Passport::Passport() :personID(1) {
}

Passport::Passport(int personID, list<string>CityList) : personID(personID) {
    this->CityList = CityList;
}

Passport::Passport(int personID, list<string>CityList, string arrival, string departure, Calendar tripDate, double cost, string name) : LongTravel(departure, arrival, tripDate, cost, name), personID(personID), CityList(CityList) {
}

Passport::Passport(const Passport& P) : personID(P.personID), CityList(P.CityList), LongTravel(P.Departure, P.Arrival, P.TripDate, P.cost, P.LongTravel::name) {
}

void Passport::addToList(string city) {
    CityList.push_back(city);
}

bool Passport::operator==(const Passport& P) {
    return ((LongTravel::operator==((LongTravel&)P)) && (this->CityList == P.CityList) &&
        (this->personID == P.personID));
}

bool Passport::isHoliday(string name) {
    for (int i = 0; i < 4; i++) {
        if (name == HolidayArr[i])
            return true;
    }
    return false;
}

void Passport::showArrival() {
    cout << "Arrival: " << Arrival << endl;
}

void Passport::show()const {
    cout << "Person ID: " << personID << endl;
}

ostream& operator<< (ostream& out, Passport& P) {
    //P.show();
    out << "\nDocument name: " << P.getName() << endl << "Document Id: " << P.getID() << endl << "Document words count: " << P.getWords() << "\n\t-Passport Content-\n" << "Person ID: " << P.personID << endl << "Airport's name: " << P.LongTravel::name << "\nDeparture: " << P.Departure << "\nArrival: " << P.Arrival << "\nTrip date: " << P.TripDate << "Cost: " << P.cost << "\nCities Visited: \n";

    for (list<string>::iterator i = P.CityList.begin(); i != P.CityList.end(); ++i)
        out << *i << endl;
    out << "-----------------------" << endl;
    return out;
}

Passport::~Passport() {

}
