#include <stdio.h>
#include"Cake.h"
#include"Bakery.h"
#include"MousseCake.h"
#include"BirthdayCake.h"

void Bakery::setBakeryName(string _BakeryName){
    this->BakeryName = _BakeryName;
}
void Bakery::setEstablishmentDate(Date _ESTdate){
    this->EstablishmentDate = _ESTdate;
}
void Bakery::setMaxCakeNum(int _MaxCakeNum){
    this->MaxCakeNum = _MaxCakeNum;
}

Bakery::Bakery(string BakeryName,Date EstablishmentDate,int MaxCakeNum){
    this->BakeryName = BakeryName;
    this->EstablishmentDate = EstablishmentDate;
    this->MaxCakeNum = MaxCakeNum;
    CakeArr = new Cake*[MaxCakeNum];
    for(int i=0;i < MaxCakeNum;i++)
        CakeArr[i] = NULL;
    
}
Bakery::Bakery(const Bakery& other):BakeryName(other.BakeryName),EstablishmentDate(other.EstablishmentDate),MaxCakeNum(other.MaxCakeNum),CakeArr(other.CakeArr){
    cout<<"Bakery(const Bakery& other)"<<endl;
    *this = other;
}
void Bakery::chooseCake(int maxPrice){
    for(int i=0;i<MaxCakeNum;i++){
        MousseCake* tmpM = dynamic_cast<MousseCake*>(CakeArr[i]);
        if (tmpM) {
            if (tmpM->getPrice() <= maxPrice && CakeArr[i]) {
                cout <<endl<< *CakeArr[i];
            }
            else
                cout <<"There is no matched cakes!"<<endl;
            
        }
    else{
        BirthdayCake* tmpB = dynamic_cast<BirthdayCake*>(CakeArr[i]);
        if (tmpB->getPrice() <= maxPrice && CakeArr[i])
            cout <<endl<< *CakeArr[i];
        else
            cout <<"There is no matched cakes!"<<endl;
    }
    }
}

void Bakery::deleteCake(int cakePos){
    if (CakeArr[cakePos] && cakePos <= MaxCakeNum) {
        delete CakeArr[cakePos];
        CakeArr[cakePos] = NULL;
        cout <<"The cake in the position " << cakePos<<" has been deleted!"<<endl;
        return;
        }
    cout <<"Position not valid!"<<endl;
    }

void Bakery::deleteExpired(Date ExpDate){
    for (int i=0; i< MaxCakeNum; i++) {
        if (CakeArr[i]) {
        MousseCake* tmpM = dynamic_cast<MousseCake*>(CakeArr[i]);
            if (tmpM && ExpDate < tmpM->getDate() ){
                deleteCake(i);
            }
            else{
                BirthdayCake* tmpB = dynamic_cast<BirthdayCake*>(CakeArr[i]);
                if (tmpB && ExpDate < tmpB->getDate()){
                        deleteCake(i);
                }
            }
            
        }
    }
}
void Bakery:: addCake(Cake* Cake){
    for (int i=0; i<MaxCakeNum; i++) {
        if (!CakeArr[i]) {
            MousseCake* tmpM = dynamic_cast<MousseCake*>(Cake);
            if (tmpM)
                CakeArr[i] = new MousseCake(*tmpM);
            else{
                BirthdayCake* tmpB = dynamic_cast<BirthdayCake*>(Cake);
                if (tmpB)
                    CakeArr[i] = new BirthdayCake(*tmpB);
                if (!Cake)
                    CakeArr[MaxCakeNum] = NULL;
            }
            cout << "The cake has been added successfully, at ["<<i<<"]"<<endl;
            cout << *CakeArr[i];
            return;
        }
    }
}

const Bakery& Bakery::operator=(const Bakery& other) {
    cout <<"In Bakery operator="<<endl;
    this->MaxCakeNum = other.MaxCakeNum;
    this->EstablishmentDate = other.EstablishmentDate;
    this->BakeryName = other.BakeryName;
    this->CakeArr = new Cake*[other.MaxCakeNum];
    for (int i=0; i<MaxCakeNum; i++) {
        MousseCake* tmpM = dynamic_cast<MousseCake*>(other.CakeArr[i]);
        if (tmpM) {
            this->CakeArr[i] = new MousseCake(*tmpM);
        }
        else{
            BirthdayCake* tmpB = dynamic_cast<BirthdayCake*>(other.CakeArr[i]);
            if (tmpB)
                this-> CakeArr[i] = new BirthdayCake(*tmpB);
            if (!other.CakeArr[i])
                this->CakeArr[i] = NULL;
        }

    }
   return *this;
}

ostream& operator<< (ostream& out,const Bakery& Bakery){
    cout << "Bakery name: "<< Bakery.BakeryName<<endl
    <<"Establishment date: "<<Bakery.EstablishmentDate <<endl
    <<"Total number of cakes: "<<Bakery.MaxCakeNum<<endl;
    for (int i=0; i<Bakery.MaxCakeNum; i++) {
        if(Bakery.CakeArr[i])
            cout <<endl<< *(Bakery.CakeArr[i]);
    }
    return out;
}

Bakery::~Bakery(){
    cout<<"In ~Bakery()"<<endl;
    delete []CakeArr;
}
