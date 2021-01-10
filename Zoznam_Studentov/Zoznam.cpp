#include "Zoznam.h"
#include "Vstup.h"
#include <fstream>

using namespace std;

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
			strcpy(meno, vstup.citaj());
			strcpy(priezvisko, vstup.citaj());
			strcpy(pohlavie, vstup.citaj());
			strcpy(znamky, vstup.citajZnamky());
			
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

void Zoznam::zoradVzostupne()
{
	for (int i = 0; i < this->pocetStudentov - 1; i++)
	{
		for (int j = 0; j < this->pocetStudentov - i - 1; j++)
		{
			if (this->zoznam[j]->getPriemer() > this->zoznam[j + 1]->getPriemer())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void Zoznam::zoradZostupne()
{
	for (int i = 0; i < this->pocetStudentov - 1; i++)
	{
		for (int j = 0; j < this->pocetStudentov - i - 1; j++)
		{
			if (this->zoznam[j]->getPriemer() < this->zoznam[j + 1]->getPriemer())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void Zoznam::vymen(Student& a, Student& b)
{
	Student c = a;
	a = b;
	b = c;
}

void Zoznam::vypis()
{
	if (this->zoznam != nullptr)
	{
		this->zoradVzostupne();
		for (int i = 0; i < this->pocetStudentov; i++)
		{
			this->zoznam[i]->vypis();
		}
	}
}

void Zoznam::exportujAckarov()
{
	ofstream output;
	output.open("ackari.out");
	if (output.is_open())
	{
		for (int i = 0; i < this->pocetStudentov; i++)
		{
			if (this->zoznam[i]->getMamA())
			{
				output << this->zoznam[i]->getMeno() << " " << this->zoznam[i]->getPriezvisko() << ", pocet A: " << this->zoznam[i]->getPocetA() << endl;
			}
		}
	}
	output.close();
}

void Zoznam::vypisNajhorsich()
{
	if (this->zoznam != nullptr)
	{
		for (int i = 0; i < this->pocetStudentov; i++)
		{
			switch (this->zoznam[i]->getPohlavie())
			{
			default:
				break;
			}
		}
	}
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
