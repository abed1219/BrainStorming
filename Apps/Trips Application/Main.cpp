#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Document.h"
#include "ShortTravel.h"
#include "LongTravel.h"
#include "Date.h"
#include "Calendar.h"
#include "Passport.h"
#include "MenuManager.h"

#define LEN 100
#define M 10

using namespace std;

int main() {
    while (1) {
        try {
            MenuManager MM;
            vector<Document*>dv;
            string Dir = "OUT.txt";
            // the commented lines are just make it easier to fill a text file(to read it later)
                    /*char DocName1[LEN] = "aa", DocName2[LEN] = "ab",  DocName3[LEN] = "ac";
                    char DocNamep1[LEN] = "ah", DocNamep2[LEN] = "an";
                    char VehicleType1[M] = "Train", VehicleType2[M] = "bus", VehicleType3[M] = "car";
                    char month1[M] = "feb",month2[M] = "jul";
            
                    list<string>CL1;
                    CL1.push_back("NYC");CL1.push_back("TLV");CL1.push_back("BJS");CL1.push_back("AUH");
                    list<string>CL2;
                    CL2.push_back("NYC");CL2.push_back("AUH");
            
                    Calendar c1(3,month1,CURRENT_YEAR);
                    Calendar c2(10,month2,CURRENT_YEAR);
            
                    ShortTravel sh1(DocName1, 2, 300, VehicleType1, 10.13);
                    ShortTravel sh2(DocName2, 5, 120, VehicleType2, 5.60);
                    ShortTravel sh3(DocName3, 6, 60, VehicleType3, 250.61);
            
                    Passport p1(1,CL1,"NYC","TLV",c1,1000,"AIRPORT1");
                    p1.setName(DocNamep1); p1.setId(1); p1.setWords(230);
            
                    Passport p2(2,CL2,"BJS","AUH",c2,2560,"AIRPORT2");
                    p2.setName(DocNamep2); p2.setId(2); p2.setWords(300);
            
                    MM.setAgencyName("Trips");
                    dv.push_back(&sh1); dv.push_back(&p1); dv.push_back(&sh2);
                    dv.push_back(&p2);dv.push_back(&sh3);

                    MM.setVector(dv);
                    MM.StartProgram(MM);*/

                    MM.ReadFromFile(MM, Dir, dv);
            return 0;
        }
        catch (const char* msg) {
            cout << msg << "\nRestarting..." << endl;
        }
    }

}
