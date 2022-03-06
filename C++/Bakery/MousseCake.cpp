#define _CRT_SECURE_NO_WARNINGS
#include "MousseCake.h"
#include "Cake.h"

void MousseCake::setExpirationDate(Date expDate){
    this->ExpirationDate = expDate;
}
void MousseCake::setMousseFlavour(string MF) {
    this->MousseFlavour = MF;
}
void MousseCake::setHeight(double height){
    this->height = height;
}
void MousseCake::setStorage(int storage){
    this->storage = storage;
}
void  MousseCake::setGlutenFree(bool glutenFree){
    this->glutenFree = glutenFree;
}
void MousseCake:: setPrice(double price){
    this->price = price;
}

MousseCake::MousseCake(Date expDate, int dmtr,double height,double price,int storage,bool glutenFree,const string mf):Cake(expDate,dmtr,height,price,storage, glutenFree){
    cout <<"In MousseCake(expDate,Dmtr,height,price,storage,glutenFree,MousseFlavour)"<<endl;
    MousseFlavour = mf;
    this->storage = storage;
}

MousseCake::MousseCake(const MousseCake& MC):Cake(MC){
    this->MousseFlavour = MC.MousseFlavour;
}

void MousseCake::operator+=(double amount){
    this->price += amount;
}
bool MousseCake::operator==(const Cake &C){
    const MousseCake* tmpM = dynamic_cast<const MousseCake*>(&C);
    if (Cake::operator==(C) &&this->MousseFlavour == tmpM->MousseFlavour)
            return true;
    return false;
    
}
const string MousseCake::showRecipe()const{
      return "Link to a mousse cake recipe\n";
}
void MousseCake::Print(ostream& out)const{
    out <<"\nMousse cake: "<<endl<<"Mousse flavour: "<<MousseFlavour;
}
MousseCake::~MousseCake(){
    cout << "In ~MousseCake()"<<endl;
}
