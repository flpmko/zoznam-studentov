#pragma once
#include "Student.h"

class Zoznam
{
private:
	Student** zoznam = nullptr;
	int pocetStudentov = 0;
public:
	Zoznam();
	Zoznam(char* paNazovSuboru);
	Zoznam(const Zoznam& zdroj);
	Zoznam operator=(const Zoznam& zdroj);
	void zorad();
	void vypis();
	void exportujAckarov();
	void vypisNajhorsich();
	~Zoznam();
};

