#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LongTravel.h"
#include "Date.h"
#include "Calendar.h"
#define L3 10

const char monthArr[12][4] = { "jan","feb","mar","apr","may","jun",
                   "jul","aug","sep","oct","nov","dec" };

int LongTravel::TripsNumber = 1;

void LongTravel::setAirportsName(string Name) {
    this->name = Name;
}

void LongTravel::setArrival(string arrival) {
    this->Arrival = arrival;
}

void LongTravel::setDeparture(string departure) {
    this->Departure = departure;
}

void LongTravel::setCost(double Cost) {
    this->cost = Cost;
}

void LongTravel::setDate(int day, char* month, int year) {
    this->TripDate.setDate(day, month, year);
}

LongTravel::LongTravel() :Departure("TLV"), Arrival("NYC") {
    char month[L3] = "jan";
    this->TripDate.setDate(1, month, 2000);
    this->cost = 500.4;
    this->name = "AIRPORT 1";
}

LongTravel::LongTravel(char* name, long id, int words) {
    setName(name);
    setId(id);
    setWords(words);
}

LongTravel::LongTravel(string Departure, string Arrival, Calendar TripDate, double cost, string name) :Departure(Departure), Arrival(Arrival), TripDate(TripDate), cost(cost), name(name) {}

LongTravel::LongTravel(const LongTravel& LT) : Departure(LT.Departure),Arrival(LT.Arrival), TripDate(LT.TripDate),cost(LT.cost) {
    this->TripsNumber = LT.TripsNumber;
    this->setName(LT.Document::getName());
    this->setId(LT.getID());
    this->setWords(LT.getWords());
}

int LongTravel::ConvertMonth(Calendar C) {
    int Curr_month = 0;
    for (; Curr_month < 12; Curr_month++) {
        if (!(strcmp(C.getMonth(), monthArr[Curr_month])))
            break;
    }
    return Curr_month + 1;
}


void LongTravel::operator-(Calendar TripDate) {
    int Curr_month = ConvertMonth(TripDate);

    cout << (((TripDate.getDay() + (Curr_month * 30) + (TripDate.getYear() * 365)) - (CURRENT_DAY + CURRENT_MONTH * 30 + CURRENT_YEAR * 365))) << " Days away from trip (in days)" << endl;
}

bool LongTravel::operator>(double cost) {
    return cost > this->cost;

}

bool LongTravel::operator==(const LongTravel& LT) {
    return ((Document::operator==((Document&)LT)) && (!(Departure == LT.Departure))
        && !(this->Arrival == LT.Arrival) && this->cost == LT.cost);
}

const LongTravel& LongTravel::operator=(const LongTravel& LT) {
    Document::operator=((Document&)LT);
    this->Departure = LT.Departure;
    this->Arrival = LT.Arrival;
    this->TripDate = LT.TripDate;
    this->cost = LT.cost;
    return *this;
}


double LongTravel::DiscountDay(double cost) {
    if (this->TripDate.getDay() == 10) {
        cout << "\nCost in this day: " << this->cost * 0.50;
        return this->cost * 0.50;
    }
    return this->cost;
}

void LongTravel::MinDays(Calendar C) {
    int Curr_month = ConvertMonth(C);
    char month[L3] = "jan";
    strcpy(month, monthArr[Curr_month]);
    if (C.getDay() + 3 > 31)
        cout << "\nMinimum staying date: " << C.getDay() - 28 << "/" << month << "/" << C.getYear() << endl;
    else
        cout << "\nMinimum staying date: " << C.getDay() + 3 << "/" << C.getMonth() << "/" << C.getYear() << endl;
}

//bool Document:: Long(){
//    return(this->words > 1000);;
//}

void LongTravel::show()const {
    cout << "\nDeparture Code: " << Departure << endl << "Arrival Code: " << Arrival << endl << "Trips Count: " << TripsNumber << endl << "Travel date:" << TripDate << endl << "Travel cost: " << cost << endl;
}

ostream& operator<<(ostream& out, const LongTravel& LT) {
    out << "\nDocument name: " << LT.Document::getName() << endl << "Document Id: " << LT.getID() <<
        "Document words count: " << LT.getWords();
    LT.show();
    return out;
}

LongTravel::~LongTravel() {}
