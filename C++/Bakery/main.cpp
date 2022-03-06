#include "Bakery.h"
#include "Date.h"
#include "MousseCake.h"
#include "BirthdayCake.h"
#include<iostream>
#define SIZE 3
int main()
{
	Date d1, d2, d3, d4, d5;
	try {
		d1.setDate(18, 12, 2019);
        d3.setDate(26, 8);
		d4.setDate(1, 1, 2019);
		d5.setDate(50, 8, 2021);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	cout << "------------------------------\n";
	Bakery myBakery("MyBakery", d4, SIZE);
	cout << "------------------------------\n";
    
	MousseCake mc1(d3, 18, 9.5, 190, 2, true, "white chocolate");
	cout << "------------------------------\n";
	cout << mc1;
	cout << "------------------------------\n";

	MousseCake mc3(d3, 18, 9.5, 190, 2, true, "ferrero rocher");
	cout << "------------------------------\n";
	cout << "(mc3==mc1): " << (mc3 == mc1 ? "true\n" : "false\n");
	cout << "------------------------------\n";

	BirthdayCake bc1(d1, 24, 9.5, 289.9, 2, true, "mazal tov");
	cout << "------------------------------\n";
	cout << bc1;
	cout << "------------------------------\n";

	BirthdayCake bc2(d1, 22, 9, 270, 1, true, "sweet 30");
	cout << "------------------------------\n";
	cout << bc2;
	cout << "------------------------------\n";

	myBakery.addCake(&mc1);
	cout << "------------------------------\n";
	myBakery.addCake(&bc1);
	cout << "------------------------------\n";
	myBakery.addCake(&bc2);
	cout << "------------------------------\n";

	cout << myBakery;
	cout << "------------------------------\n";

	myBakery.chooseCake(100);
	cout << "------------------------------\n";
	myBakery.chooseCake(270);

	cout << "------------------------------\n";
	myBakery.deleteCake(4);
	cout << "------------------------------\n";
	myBakery.deleteCake(1);
	cout << "------------------------------\n";
	myBakery.deleteExpired(d2);

	cout << "------------------------------\n";
	cout << myBakery;
	cout << "------------------------------\n";
    
    Bakery otherB = myBakery;
	cout << "------------------------------\n";
	cout << "Copy of bakery:\n" << otherB;
	cout << "------------------------------\n";

	Cake* bc3 = new BirthdayCake(d2, 16, 9, 285, 1, true, "sweet 16");
	cout << "------------------------------\n";
	cout << bc3->showRecipe();
	cout << "------------------------------\n";

	delete bc3;
    return 0;
}
