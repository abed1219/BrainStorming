#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ShortTravel.h"
#define L2 10
#define TAX 1.17
#define DISCOUNT 0.85
using namespace std;


void ShortTravel::setVehicleType(char* Vehicletype) {
    this->VehicleType = new char[strlen(Vehicletype)];
    strcpy(this->VehicleType, Vehicletype);

}
void ShortTravel::setCost(double cost) {
    this->cost = cost;
}

ShortTravel::ShortTravel() :cost(20) {
    char VT[L2] = "car";
    this->VehicleType = new char[strlen(VT)];
    strcpy(this->VehicleType, VT);
}

ShortTravel::ShortTravel(char* name, long id, int words) :Document(name, id, words) {}

ShortTravel::ShortTravel(char* name, long id, int words, char* VehicleType, double cost) : Document(name, id, words), VehicleType(VehicleType), cost(cost) {}

ShortTravel::ShortTravel(const ShortTravel& ST) : cost(ST.cost) {
    strcpy(this->VehicleType, ST.VehicleType);
    *this = ST;
}

bool ShortTravel::operator==(const ShortTravel& ST) {
    return ((Document::operator==((Document&)ST)) && (!strcmp(this->VehicleType, ST.VehicleType))
        && this->cost == ST.cost);
}

const ShortTravel& ShortTravel::operator=(const ShortTravel& ST) {
    Document::operator=((Document&)ST);
    this->VehicleType = new char[strlen(ST.VehicleType)];// + 1 in strlen>?
    strcpy(this->VehicleType, ST.VehicleType);
    this->cost = ST.cost;
    return *this;
}

bool ShortTravel::operator<(const ShortTravel& ST) {
    return (this->cost < ST.cost);
}

void ShortTravel::operator+=(double cost) {
    this->cost = cost;
}

void ShortTravel::CostAfterTax(ShortTravel& ST) {

    cout << "Cost after tax: " << ST.cost * TAX << endl;
    ST.cost *= TAX;
}

void ShortTravel::CostAfterDiscount(ShortTravel& ST) {
    cout << "Cost after Discount: " << ST.cost * DISCOUNT << endl; //25% discount
    ST.cost *= DISCOUNT;
}


void ShortTravel::show()const {
    cout << "\nDocument name: " << getName() << endl << "Document Id: " << getID() << endl << "Document words count: " << getWords() << endl;
}

ostream& operator<<(ostream& out, const ShortTravel& ST) {
    out << "\nDocument name: " << ST.getName() << endl << "Document Id: " << ST.getID() << endl << "Document words count: " << ST.getWords() << endl << "\t-Document Content-\n" << "Vehicle type: " << ST.VehicleType << endl
        << "Cost: " << ST.cost << endl;
    out << "-----------------------" << endl;
    return out;
}

ShortTravel::~ShortTravel() {

}
