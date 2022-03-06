#ifndef Cake_hpp
#define Cake_hpp
#include"Date.h"
#include <stdio.h>


class Cake{
protected:
    Date ExpirationDate;
    const int Diameter;
    double height;
    double price;
    int storage;
    bool glutenFree;
public:
    Cake(Date expDate,int dmtr,double height,double price,int storage,bool glutenFree);
    virtual ~Cake();
    const Cake& operator=(const Cake& c);
    void operator+=(double amount);
    friend ostream& operator <<(ostream& out,const Cake& cake);
    virtual const string showRecipe()const = 0;
    virtual void Print(ostream& out)const = 0;
    virtual bool operator==(const Cake& c);
};
#endif /* Cake_hpp */
