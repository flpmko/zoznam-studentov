#include "Student.h"
#include "Vstup.h"
#include "Zoznam.h"

int main()
{
	//Student student;
	//Vstup vstup;
	Zoznam zoznam((char*)"data.txt");
	//zoznam.zorad();
	zoznam.vypis();
	zoznam.exportujAckarov();

	return 0;
}