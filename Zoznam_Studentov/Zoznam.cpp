#include "Zoznam.h"
#include "Vstup.h"

Zoznam::Zoznam()
{
}

Zoznam::Zoznam(char* paNazovSuboru)
{
	if (paNazovSuboru != nullptr)
	{
		Vstup vstup(paNazovSuboru);
		this->pocetStudentov = vstup.getPocetRiadkov();
		this->zoznam = new Student * [pocetStudentov];
		char priezvisko[255];
		char meno[255];
		char pohlavie[255];
		char znamky[255];
		for (int i = 0; i < pocetStudentov; i++)
		{
			strcpy(priezvisko, vstup.citaj());
			strcpy(meno, vstup.citaj());
			strcpy(pohlavie, vstup.citaj());
			for (int j = 0; j < 5; j++)
			{
				strcpy(znamky, vstup.citaj());
			}
			this->zoznam[i] = new Student(priezvisko, meno, pohlavie, znamky);
		}
	}
}

Zoznam::Zoznam(const Zoznam& zdroj)
{
	if (this != &zdroj)
	{
		this->zoznam = new Student * [zdroj.pocetStudentov];
		for (int i = 0; i < zdroj.pocetStudentov; i++)
		{
			this->zoznam[i] = new Student(zdroj.zoznam[i]->getPriezvisko(),
				zdroj.zoznam[i]->getMeno(),
				zdroj.zoznam[i]->getPohlavie(),
				zdroj.zoznam[i]->getZnamky());
		}
	}
}

Zoznam Zoznam::operator=(const Zoznam& zdroj)
{
	if (this != &zdroj)
	{
		Zoznam::~Zoznam();
		this->zoznam = new Student * [zdroj.pocetStudentov];
		for (int i = 0; i < zdroj.pocetStudentov; i++)
		{
			this->zoznam[i] = new Student(zdroj.zoznam[i]->getPriezvisko(),
				zdroj.zoznam[i]->getMeno(),
				zdroj.zoznam[i]->getPohlavie(),
				zdroj.zoznam[i]->getZnamky());
		}
	}
	return *this;
}

void Zoznam::zorad()
{
}

void Zoznam::vypis()
{
	if (this->zoznam != nullptr)
	{
		for (int i = 0; i < this->pocetStudentov; i++)
		{
			this->zoznam[i]->vypis();
		}
	}
}

void Zoznam::exportujAckarov()
{
}

void Zoznam::vypisNajhorsich()
{
}

Zoznam::~Zoznam()
{
	for (int i = 0; i < this->pocetStudentov; i++)
	{
		delete this->zoznam[i];
	}
	delete[] this->zoznam;
	this->zoznam = nullptr;
	this->pocetStudentov = 0;
}
