#ifndef BirthdayCake_h
#define BirthdayCake_h
#include <stdio.h>
#include "Cake.h"

class BirthdayCake: public Cake{
private:
    string CakeText;
public:
    BirthdayCake(Date expDate,int dmtr,double height, double price,int storage,bool glutenFree, const string CT);
    BirthdayCake(const BirthdayCake& BC);
    virtual ~BirthdayCake();
    //get
    Date getDate(){return ExpirationDate;};
    const int getDiameter(){return Diameter;};
    string getCakeText(){return CakeText;};
    double getHeight(){return height;};
    double getPrice(){return price;};
    int getStorage(){return storage;};
    bool getGlutenFree(){return glutenFree;};
    //set
    void setCakeText(string CT);
    void setExpirationDate(Date expDate);
    void setHeight(double height);
    void setPrice(double price);
    void setStorage(int storage);
    void setGlutenFree(bool glutenFree);
    const BirthdayCake& operator=(const BirthdayCake& BC);
    void operator+=(double amount);
    virtual bool operator==(const Cake& C);
    virtual const string showRecipe()const;
    virtual void Print(ostream& out)const;
    
};
#endif /* BirthdayCake_h */
