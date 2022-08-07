#ifndef MenuManager_h
#define MenuManager_h
#include <iostream>
#include <cstring>
#include "LongTravel.h"
#include "ShortTravel.h"
#include "Passport.h"
#include "vector"

//Menu Manager knows shortTravel, longTravel, and passport, its basically a travelling agency management class

class MenuManager { // Traveling agency

    string AgencyName; //Agency name
    ShortTravel SH; // ShortTravel obj
    Passport P; // Passport obj
    vector<Document*>DV; // a vector that holds info on travelling trips kinds

public:
    MenuManager();
    MenuManager(ShortTravel SH, Passport P);
    MenuManager(ShortTravel SH, Passport P, vector<Document*>dv);
    ~MenuManager();

    string getAgencyName() { return AgencyName; };
    vector<Document*> getVector() { return DV; };
    void setAgencyName(string agency_name);
    void setVector(vector<Document*>dv);

    void AddDocument(Document& DOC); // add a travel document to the vector that holds travel details
    void DeleteDocument(long id); // delete a travel document from the vector
    unsigned long SearchDoc(long id); // search a document, return document's index in vector
    void show()const; // show menu manager
    void FindAndChangeCost(MenuManager& MM, int opt); // finds a trip based on a given id, and it changes the price according to the workers choice
    void DiscountDate(Passport& P, char* month); // after adding a trip the program checks if this trip gets a big discount or no
    void StartProgram(MenuManager& MM); // start the program -> show menu
    char* FilterString(char* buff); // extract a required string 
    void ReadFromFile(MenuManager& MM, string Dir, vector<Document*>dv); // read info from file
    void PrintToFile(MenuManager& MM); // print info to file
    void Print(MenuManager& MM, long id); // print info to the screen
    void CalculateDays(MenuManager& MM); // calculate days
    void PrintCostlyTrips(MenuManager& MM); // print the trips that cost more than a given price

    friend ostream& operator<< (ostream& out, MenuManager& MM); //print 
};

#endif /* MenuManager_h */
