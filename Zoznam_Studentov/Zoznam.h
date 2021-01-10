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
	void zoradVzostupne();
	void zoradZostupne();
	void vymen(Student& a, Student& b);
	void vypis();
	void exportujAckarov();
	void vypisNajhorsich();
	~Zoznam();
};

