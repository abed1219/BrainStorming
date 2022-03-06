#define _CRT_SECURE_NO_WARNINGS
#include "Cake.h"
#include<iostream>
#define SIZE 15
using namespace std;
 
Cake::Cake(Date expDate,int Dmtr ,double height,double price,int storage,bool glutenFree):ExpirationDate(expDate),Diameter(Dmtr),height(height),price(price),storage(storage),glutenFree(glutenFree){
    cout << "Initialization Succeeded!" << endl;
    cout << "-------------------------" << endl;
    cout <<"In Cake(expDate,Dmtr,height,price,storage,glutenFree)"<<endl;
}
const Cake& Cake::operator=(const Cake& c){
    this->ExpirationDate = c.ExpirationDate;
    this->height = c.height;
    this->storage = c.storage;
    this->glutenFree = c.glutenFree;
    this->price = c.price;
    return *this;
}

bool Cake::operator==(const Cake &c){
    if(ExpirationDate == c.ExpirationDate && c.Diameter == Diameter && c.height == height && c.price == price && c.storage == storage && c.glutenFree == glutenFree)
        return true;
    return false;
}

void Cake::operator+=(double amount){
    this->price += amount;
}
ostream& operator<<(ostream& out, const Cake& cake){
    string storageC;
    cake.Print(out);
    if (cake.storage == 1)
        storageC = "Refrigerator";
    else
        storageC = "Freezer";
    out << "\nExpiration Date: " << cake.ExpirationDate << endl << "Diameter: "<< cake.Diameter <<endl << "Height: " << cake.height << endl <<"Is Gluten Free: " << cake.glutenFree <<endl <<"Stored in: " << cake.storage <<endl << "Price: " << cake.price <<endl;
    return out;
}

Cake::~Cake(){
    cout <<"In ~Cake()"<<endl;
}
