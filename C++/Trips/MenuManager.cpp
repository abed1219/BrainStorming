#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MenuManager.h"
#include "ShortTravel.h"
#include "LongTravel.h"
#include "Date.h"
#include "Calendar.h"
#include "Passport.h"
#include <fstream>
#define DOCNAMELEN 100
#define L5 10

using namespace std;

void MenuManager::setAgencyName(string agency_name) {
    this->AgencyName = agency_name;
}
void MenuManager::setVector(vector<Document*>dv) {
    this->DV = dv;
}

MenuManager::MenuManager() :AgencyName("A Flights") {
    list<string>cities;
    cities.push_back("NYC");
    Passport p(1, cities);
    this->DV.push_back(&p);
}

MenuManager::MenuManager(ShortTravel sh, Passport p) :SH(sh), P(p) {}

MenuManager::MenuManager(ShortTravel SH, Passport P, vector<Document*>dv) : SH(SH), P(P), DV(dv) {}

void MenuManager::AddDocument(Document& DOC) {
    this->DV.push_back(&DOC);
}

unsigned long MenuManager::SearchDoc(long id) noexcept(false) {
    for (int i = 0; i < this->DV.size(); i++) {
        if (this->DV[i]->getID() == id)
            return i;
    }
    throw "No such document!\n";
    return this->DV.size() + 1; //(*) the size() + 1 is for delete check
}

void MenuManager::DeleteDocument(long id) noexcept(false) {
    if (this->DV.empty()) {
        throw "Document Vector is empty!\n";
        return;
    }
    unsigned long idx = SearchDoc(id);
    if (idx <= this->DV.size()) { //(*)
        vector<Document*>::iterator idxITR = this->DV.begin() + idx;
        this->DV.erase(idxITR);
    }
}

void MenuManager::show()const {
    cout << "\t\t\t\t\t\t\t\tAgency name: " << AgencyName << endl;
}

ostream& operator<< (ostream& out, MenuManager& MM) {
    MM.show();
    for (int i = 0; i < MM.DV.size(); i++) {
        ShortTravel* tmpS = dynamic_cast<ShortTravel*>(MM.DV[i]);
        if (tmpS)
            cout << *tmpS;
        else {
            Passport* tmpP = dynamic_cast<Passport*>(MM.DV[i]);
            cout << *tmpP;
        }
    }
    return out;
}

char* MenuManager::FilterString(char* buff) {
    char Str[100] = {};
    for (int i = 0; i < strlen(buff); i++) {
        if (buff[i] == ':' && buff[i + 1] == ' ') {
            for (int h = 0, j = i + 2; buff[j] != '\0'; h++, j++) {
                Str[h] = buff[j];
                Str[h + 1] = '\0';
            }
            strcpy(buff, Str);
            break;
        }
    }
    return buff;
}

void MenuManager::ReadFromFile(MenuManager& MM, string Dir, vector<Document*>dv) {
    char buff[100] = {}, tempSTR[100] = {}; int flag = 0, SHcounter = 0, PCounter = 0;

    ifstream f(Dir, ios::in);
    ifstream f1(Dir, ios::in);
    if (!f.is_open()) cout << "File Failed to open!";
    while (!f1.eof()) {
        f1.getline(buff, 100);
        if (buff[1] == '1' && buff[0] != '\0')
            SHcounter++;
        else if (buff[1] == '8' && buff[0] != '\0')
            PCounter++;
    }
    f1.close();

    Passport PS[100]; ShortTravel SH[100];
    Calendar* C = new Calendar[PCounter];
    SHcounter = 0; PCounter = 0;
    while (!f.eof()) {
        f.getline(buff, 100);
        if (buff[1] == '1' || buff[6] == 'S') { //Class type: ShortTravel

            f.getline(buff, 100);
            f.getline(buff, 100);
            SH[SHcounter].setName(FilterString(buff));
            f.getline(buff, 100);
            SH[SHcounter].setId(stol(FilterString(buff)));
            f.getline(buff, 100);
            SH[SHcounter].setWords(stoi(FilterString(buff)));
            f.getline(buff, 100);
            f.getline(buff, 100);
            SH[SHcounter].setVehicleType(FilterString(buff));
            f.getline(buff, 100);
            SH[SHcounter].setCost(stod(FilterString(buff)));
            ShortTravel* Tmp_sh = &SH[SHcounter];
            dv.push_back(Tmp_sh);
            SHcounter++;
        }
        else if (buff[1] == '8' || buff[6] == 'P') { //Class type: Passport
            flag = 0;
            f.getline(buff, 100);
            f.getline(buff, 100);
            PS[PCounter].setName(FilterString(buff));
            f.getline(buff, 100);
            PS[PCounter].setId(stol(FilterString(buff)));
            f.getline(buff, 100);
            PS[PCounter].setWords(stoi(FilterString(buff)));
            f.getline(buff, 100);
            f.getline(buff, 100);
            PS[PCounter].setPersonId(stoi(FilterString(buff)));
            f.getline(buff, 100);
            PS[PCounter].setAirportsName(FilterString(buff));
            f.getline(buff, 100);
            PS[PCounter].setDeparture(FilterString(buff));
            f.getline(buff, 100);
            PS[PCounter].setArrival(FilterString(buff));
            f.getline(buff, 100);
            strcpy(buff, FilterString(buff));

            for (int i = 0; buff[i] != '\0'; i++) {
                if (buff[i] != '/') {
                    for (int j = 0; buff[i] != '/'; j++, i++) {
                        tempSTR[j] = buff[i];
                        tempSTR[j + 1] = '\0';
                    }
                    if (!flag++)
                        C[PCounter].setDay(stoi(tempSTR));
                    else if (flag == 2)
                        C[PCounter].setMonth(tempSTR);
                    else {
                        C[PCounter].setYear(stoi(tempSTR));
                        break;
                    }
                }
            }
            PS[PCounter].setDate(C[PCounter].getDay(), C[PCounter].getMonth(), C[PCounter].getYear());
            f.getline(buff, 100);
            PS[PCounter].setCost(stod(FilterString(buff)));
            f.getline(buff, 100);
            f.getline(buff, 100);
            do {
                PS[PCounter].setCityList(FilterString(buff));
                f.getline(buff, 100);

            } while (buff[3] != '-');
            Passport* Tmp_p = &PS[PCounter];
            dv.push_back(Tmp_p);
            PCounter++;
        }
    }
    MM.setVector(dv);
    f.close();
    StartProgram(MM);
    C = NULL;
    delete[] C;
}


void MenuManager::PrintToFile(MenuManager& MM) {
    ofstream f("OUT.txt", ios::trunc);
    for (int i = 0; i < MM.DV.size(); i++) {
        Passport* tmp_pass = dynamic_cast<Passport*>(MM.DV[i]);
        if (tmp_pass) {
            f << "Class type: \n" << typeid(tmp_pass).name() << endl;
            f << *tmp_pass;
        }
        else {
            ShortTravel* tmp_Short = dynamic_cast<ShortTravel*>(MM.DV[i]);
            f << "Class type: \n" << typeid(tmp_Short).name() << endl;
            f << *tmp_Short;
        }
    }
    f.close();
}

void MenuManager::Print(MenuManager& MM, long id) {
    for (int i = 0; i < MM.DV.size(); i++) {
        if (MM.DV[i]->getID() == id) {


            Passport* tmp_pass = dynamic_cast<Passport*>(MM.DV[i]);
            if (tmp_pass) {
                cout << "Class type: \n" << typeid(tmp_pass).name() << endl;
                cout << *tmp_pass;
            }
            else {
                ShortTravel* tmp_Short = dynamic_cast<ShortTravel*>(MM.DV[i]);
                cout << "Class type: \n" << typeid(tmp_Short).name() << endl;
                cout << *tmp_Short;
            }
        }
    }
}

void MenuManager::FindAndChangeCost(MenuManager& MM, int opt) {
    long id;
    cout << "Enter document id" << endl; cin >> id;
    for (int i = 0; i < MM.DV.size(); i++) {
        if (MM.DV[i]->getID() == id) {
            ShortTravel* tmp_Short = dynamic_cast<ShortTravel*>(MM.DV[i]);
            if (tmp_Short) {
                if (opt == 3) {

                    cout << "Cost before tax: " << (*tmp_Short).getCost() << endl;
                    MM.SH.CostAfterTax(*tmp_Short);
                    cout << "Updated short trip: \n" << *tmp_Short;
                }
                else {
                    cout << "Cost before discount: " << (*tmp_Short).getCost() << endl;
                    MM.SH.CostAfterDiscount(*tmp_Short);
                    cout << "Updated short trip: \n" << *tmp_Short;
                }
            }
        }
    }
}

void MenuManager::DiscountDate(Passport& P, char* month) {
    if (P.isHoliday(month))
        P.setCost(P.getCost() * 0.50);
}

void MenuManager::CalculateDays(MenuManager& MM) {
    long id;
    cout << "Enter document id" << endl; cin >> id;
    char month[L5] = "feb";
    Calendar CCurr; CCurr.setDate(CURRENT_DAY, month, CURRENT_YEAR);
    for (int i = 0; i < MM.DV.size(); i++) {
        if (MM.DV[i]->getID() == id) {
            Passport* tmp_pass = dynamic_cast<Passport*>(MM.DV[i]);
            if (tmp_pass) {
                if (tmp_pass->getDate() > CCurr)
                    cout << "The trip date has passed!" << endl;
                else
                    tmp_pass->operator-(tmp_pass->getDate());
            }
        }
    }
}

void MenuManager::PrintCostlyTrips(MenuManager& MM) {
    double price; cout << "Enter a price" << endl; cin >> price;
    for (int i = 0; i < MM.DV.size(); i++) {
        Passport* tmp_p = dynamic_cast<Passport*>(MM.DV[i]);
        if (tmp_p) {
            if (tmp_p->getCost() > price)
                cout << *tmp_p;
        }
        else {
            ShortTravel* tmp_S = dynamic_cast<ShortTravel*>(MM.DV[i]);
            if (tmp_S) {
                if (tmp_S->getCost() > price)
                    cout << *tmp_S;
            }

        }
    }
}


void MenuManager::StartProgram(MenuManager& MM) {
    MenuManager TmpMM;
    cout << "\t\t\t\t\t\t\t--" << MM.AgencyName << " Traveling Agency--\n";
    cout << "A travelling agency that hold info on 2 kinds of trips\nThe info is held in a document, each document has a name,serial number and number of words\n  1st kind: \n";
    cout << "Short trip(in border trip, using a vehicle i.c bus/train/car.\nthere is a different cost for each vehicle, the workers can change prices,add taxes, apply discounts (15% off!))\n";

    cout << "  2nd kind: \nLong trip/flight (Out of border trip, each trip contains a airports names, departure and arrival codes, the date and the cost\nThe minimum number of days for each trip is 3 days\nAnd if you're lucky on a specific month of each year that our agency chose there is a big discount!!\nOur agency provides a different type of passports that holds the trips info(airports names,departure code,arrival code,cities list, trip date and the cost for each trip))\n";

    while (1) {
        int opt, day, year, Personid, i = 0; long id; int words; double cost;
        string departure, arrival, city, airportName; list<string>CL;
        char ch, month[L5], name[DOCNAMELEN];
        cout << "\nSelect an option: " << endl <<
            "1.Add a trip" << endl <<
            "2.Delete a trip" << endl <<
            "3.Calculate and change cost after tax for a specific short trip" << endl <<
            "4.Calculate and change cost after discount for a specific short trip" << endl <<
            "5.Calculate days away from the trip" << endl <<
            "6.Print trips that cost more than given cost" << endl <<
            "7.Print a specific trip's document" << endl <<
            "8.Print all trips documents" << endl <<
            "9.Save document" << endl <<
            "10.Quit & save" << endl;
        cin >> opt;
        switch (opt) {
        case 1:
            cout << "(long trip (l) / short trip (s))" << endl;
            cin >> ch;
            if (ch == 's') {
                cout << "Enter document name" << endl; cin >> name; TmpMM.SH.setName(name);
                cout << "Enter document serial number" << endl; cin >> id; TmpMM.SH.setId(id);
                cout << "Enter document words count" << endl; cin >> words; TmpMM.SH.setWords(words);
                cout << "Enter trip vehicle type" << endl; cin >> name; TmpMM.SH.setVehicleType(name);
                cout << "Enter trip cost" << endl; cin >> cost; TmpMM.SH.setCost(cost);
                AddDocument(TmpMM.SH);
            }
            else if (ch == 'l') {
                cout << "Enter document name " << endl; cin >> name; TmpMM.P.setName(name);
                cout << "Enter document serial number " << endl; cin >> id; TmpMM.P.setId(id);
                cout << "Enter document words count " << endl; cin >> words; TmpMM.P.setWords(words);
                cout << "Enter trip departure " << endl; cin >> departure; TmpMM.P.setDeparture(departure);
                cout << "Enter trip arrival " << endl; cin >> arrival; TmpMM.P.setArrival(arrival);
                cout << "Enter trip date (D int /M string /Y int ) " << endl; cin >> day; cin >> month; cin >> year;
                TmpMM.P.setDate(day, month, year);
                cout << "Enter trip cost " << endl; cin >> cost; TmpMM.P.setCost(cost);
                cout << "Enter person id " << endl; cin >> Personid; TmpMM.P.setPersonId(Personid);
                cout << "Enter airport's name " << endl; cin >> airportName; TmpMM.P.setAirportsName(airportName);
                cout << "Cities count " << endl; cin >> i;
                for (int j = 0; j < i; j++) {
                    cout << "Enter a city" << endl; cin >> city; TmpMM.P.setCityList(city);
                }
                AddDocument(TmpMM.P);
                DiscountDate(TmpMM.P, month);
            } 
            else
                cout << "Invalid trip type" << endl;
            break;

        case 2:
            cout << "Enter document id" << endl; cin >> id; DeleteDocument(id);
            break;

        case 3:
            FindAndChangeCost(MM, opt);
            break;

        case 4:
            FindAndChangeCost(MM, opt);
            break;

        case 5:
            CalculateDays(MM);
            break;

        case 6:
            PrintCostlyTrips(MM);
            break;

        case 7:
            cout << "Enter document id" << endl; cin >> id;
            Print(MM, id);
            break;
        case 8:
            cout << MM;
            break;

        case 9:
            PrintToFile(MM);
            break;

        case 10:
            PrintToFile(MM);
            return;

        default:
            cout << "Invalid option!" << endl;
            break;
        }
    }
}

MenuManager::~MenuManager() {

}
