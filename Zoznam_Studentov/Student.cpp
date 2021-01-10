#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student()
{
}

Student::Student(char* paPriezvisko, char* paMeno, char* paPohlavie, char* paZnamky)
{
	if (paMeno && paPriezvisko && paZnamky && paPohlavie != nullptr)
	{
		//priezvisko
		this->priezvisko = new char[strlen(paPriezvisko) + 1];
		strcpy(this->priezvisko, paPriezvisko);
		//meno
		this->meno = new char[strlen(paMeno) + 1];
		strcpy(this->meno, paMeno);
		//pohlavie
		this->pohlavie = new char[strlen(paPohlavie) + 1];
		strcpy(this->pohlavie, paPohlavie);
		//znamky
		this->znamky = new char[strlen(paZnamky) + 1];
		strcpy(this->znamky, paZnamky);
	}
}

Student::Student(const Student& zdroj)
{
	if (this != &zdroj)
	{
		//priezvisko
		this->priezvisko = new char[strlen(zdroj.priezvisko) + 1];
		strcpy(this->priezvisko, zdroj.priezvisko);
		//meno
		this->meno = new char[strlen(zdroj.meno) + 1];
		strcpy(this->meno, zdroj.meno);
		//pohlavie
		this->pohlavie = new char[strlen(zdroj.pohlavie) + 1];
		strcpy(this->pohlavie, zdroj.pohlavie);
		//znamky
		this->znamky = new char[strlen(zdroj.znamky) + 1];
		strcpy(this->znamky, zdroj.znamky);
	}
}

Student Student::operator=(const Student& zdroj)
{
	if (this != &zdroj)
	{
		Student::~Student();
		//priezvisko
		this->priezvisko = new char[strlen(zdroj.priezvisko) + 1];
		strcpy(this->priezvisko, zdroj.priezvisko);
		//meno
		this->meno = new char[strlen(zdroj.meno) + 1];
		strcpy(this->meno, zdroj.meno);
		//pohlavie
		this->pohlavie = new char[strlen(zdroj.pohlavie) + 1];
		strcpy(this->pohlavie, zdroj.pohlavie);
		//znamky
		this->znamky = new char[strlen(zdroj.znamky) + 1];
		strcpy(this->znamky, zdroj.znamky);
	}
	return *this;
}

float Student::getPriemer()
{
	float priemer = 0;
	if (this->znamky != nullptr)
	{
		float sucet = 0;
		float pocet = (strlen(this->znamky)) % 6;
		for (int i = 0; i < strlen(this->znamky) - 1; i++)
		{
			switch (this->znamky[i])
			{
			case 'A':
				sucet++;
				this->pocetA++;
				if (!this->mamA)
				{
					this->mamA = true;
				}
				break;
			case 'B':
				sucet += 2;
				break;
			case 'C':
				sucet += 3;
				break;
			case 'D':
				sucet += 4;
				break;
			case 'E':
				sucet += 5;
				break;
			default:
				break;
			} 
		}
		priemer = sucet / pocet;
	}
	else
		cout << "ziadne znamky" << endl;
	return priemer;
}

void Student::vypis()
{
	//cout << this->priezvisko << " " << this->meno << " " << fixed << setprecision(2) << this->getPriemer() << endl;
	printf("%s %s %.2f\n", this->priezvisko, this->meno, this->getPriemer());
}

Student::~Student()
{
	delete[] this->meno;
	delete[] this->priezvisko;
	delete[] this->pohlavie;
	delete[] this->znamky;
}
