#ifndef ShortTravel_h
#define ShortTravel_h
#include "Date.h"
#include "Document.h"
#include <iostream>
#include <cstring>

//ShortTravel is a trip in borders using a bus/ train/car...

class ShortTravel : public Document {

    char* VehicleType; // bus/train/car...
    double cost; // i.e fuel, bus ticket, train ticket etc...

public:
    ShortTravel();
    ShortTravel(const ShortTravel& ST);
    ShortTravel(char* name, long id, int words);
    ShortTravel(char* name, long id, int words, char* VehicleType, double cost);
    ~ShortTravel();

    char* getVehicleType() { return VehicleType; }
    double getCost() { return cost; }
    void setVehicleType(char* Vehicletype);
    void setCost(double cost);

    bool operator==(const ShortTravel& ST); // compare trips
    const ShortTravel& operator=(const ShortTravel& ST); //copy short trip
    bool operator<(const ShortTravel& ST); // check if the left trip is smaller than the right one
    void operator+=(double cost); // add to cost
    friend ostream& operator<< (ostream& out, const ShortTravel& ST); // print
    void CostAfterTax(ShortTravel& ST); // save cost
    void CostAfterDiscount(ShortTravel& ST); //save cost

    void show()const;
};

#endif /* ShortTravel_h */

