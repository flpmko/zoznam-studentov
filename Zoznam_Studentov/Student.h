#pragma once
#include <cstring>

class Student
{
private:
	char* meno = nullptr;
	char* priezvisko = nullptr;
	char* pohlavie = nullptr;
	char* znamky = nullptr;
public:
	Student();
	Student(char* paPriezvisko, char* paMeno, char* paPohlavie, char* paZnamky);
	Student(const Student& zdroj);
	Student operator = (const Student& zdroj);
	float getPriemer();
	inline char* getMeno() { return this->meno; };
	inline char* getPriezvisko() { return this->priezvisko; };
	inline char* getPohlavie() { return this->pohlavie; };
	inline char* getZnamky() { return this->znamky; };
	void vypis();
	~Student();
};

