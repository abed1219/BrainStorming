#include <stdio.h>
#include"BirthdayCake.h"
#include "Cake.h"

void BirthdayCake::setExpirationDate(Date expDate){
    this->ExpirationDate = expDate;
}
void BirthdayCake::setCakeText(string CT){
    this->CakeText = CT;
}
void BirthdayCake::setHeight(double height){
    this->height = height;
}
void BirthdayCake::setStorage(int storage){
    this->storage = storage;
}
void BirthdayCake::setGlutenFree(bool glutenFree){
    this->glutenFree = glutenFree;
}
void BirthdayCake::setPrice(double price){
    this->price = price;
}

BirthdayCake::BirthdayCake(Date expDate, int dmtr,double height,double price,int storage,bool glutenFree,const string CT):Cake( expDate,dmtr,height,price,storage,glutenFree){
    cout <<"In BirthdayCake(expDate,Dmtr,height,price,storage,glutenFree,CT)"<<endl;
    CakeText =  CT;
    this->storage = storage;
}

BirthdayCake::BirthdayCake(const BirthdayCake& BC):Cake(BC){
    CakeText = BC.CakeText;
}

void BirthdayCake::operator+=(double amount){
    this->price += amount;
}

void BirthdayCake::Print(ostream& out)const{
    out <<"\nBirthdayCake: "<<endl<<"Cake Text: "<<CakeText;
}

const BirthdayCake& BirthdayCake::operator=(const BirthdayCake& BC){
    cout<<"In BirthdayCake operator= "<<endl;
    Cake::operator=(BC);
    CakeText = BC.CakeText;
    return *this;
}
bool BirthdayCake::operator==(const Cake &C){
    const BirthdayCake* tmpB = dynamic_cast<const BirthdayCake*>(&C);
    if (Cake::operator==(C) && this->CakeText == tmpB->CakeText)
        return true;
    return false;
}
const string BirthdayCake::showRecipe()const{
    return "Link to a birthday cake recipe\n";
    
}
BirthdayCake::~BirthdayCake(){
    cout<<"In ~BirthdayCake()"<<endl;
}
