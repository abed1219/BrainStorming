#ifndef Bakery_h
#define Bakery_h
#include"Date.h"
#include"Cake.h"

class Bakery{
private:
    string BakeryName;
    Date EstablishmentDate;
    int MaxCakeNum;
    Cake** CakeArr;
public:
    Bakery(string BakeryName,Date EstablishmentDate,int MaxCakeNum);
    Bakery(const Bakery& o);
    ~Bakery();
    //get
    string getBakeryName(){return BakeryName;};
    Date getEstablishmentDate(){return EstablishmentDate;};
    int getMaxCakeNum(){return MaxCakeNum;};
    //set
    void setBakeryName(string _BakeryName);
    void setEstablishmentDate(Date _ESTdate);
    void setMaxCakeNum(int _MaxCakeNum);
    void chooseCake(int maxPrice);
    void deleteCake(int cakePos);
    void addCake(Cake* Cake);
    void deleteExpired(Date ExpDate);
    const Bakery& operator=(const Bakery& o);
    friend ostream& operator <<(ostream& out,const Bakery& Bakery);
};
#endif /* Bakery_h */
