#include "Student.h"
#include "Vstup.h"
#include "Zoznam.h"
#include <iostream>

using namespace std;

int main()
{
	//Student student;
	//Vstup vstup;
	Zoznam zoznam((char*)"data.txt");
	//zoznam.zorad();
	zoznam.vypis();
	zoznam.exportujAckarov();
	cout << "-----------------------NAJHORSI----------------------" << endl;
	zoznam.vypisNajhorsich();

	return 0;
}