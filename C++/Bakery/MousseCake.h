#ifndef MousseCake_hpp
#define MousseCake_hpp
#include <stdio.h>
#include "Cake.h"

class MousseCake:public Cake{
private:
     string MousseFlavour;
public:
    MousseCake(Date expDate,int dmtr,double height, double price,int storage,bool glutenFree, const string mf);
    MousseCake(const MousseCake& MC);
    virtual ~MousseCake();
    //get
    Date getDate(){return ExpirationDate;};
    const int getDiameter(){return Diameter;};
    int getStorage(){return storage;};
    double getPrice(){return price;};
    double getHeight(){return height;};
    bool getGlutenFree(){return glutenFree;};
    string getMousseFlavour(){return MousseFlavour;};
    //set
    void setExpirationDate(Date Date);
    void setMousseFlavour(string MF);
    void setHeight(double height);
    void setPrice(double price);
    void setStorage(int storage);
    void setGlutenFree(bool glutenFree);
    const MousseCake& operator=(const MousseCake& MC);
    void operator+=(double amount);
    virtual bool operator==(const Cake& C);
    virtual const string showRecipe()const;
    virtual void Print(ostream& out)const;

};
#endif /* MousseCake_hpp */
