#include "Vstup.h"

Vstup::Vstup()
{
}

Vstup::Vstup(char* nazovSuboru)
{
	if (nazovSuboru != nullptr)
	{
		this->fhandle = fopen(nazovSuboru, "rt");
	}
}

Vstup::Vstup(const Vstup& zdroj)
{
	if (this != &zdroj)
	{
		this->fhandle = zdroj.fhandle;
		this->pocetRiadkov = zdroj.pocetRiadkov;
		for (int i = 0; i < BUF_SIZE; i++)
		{
			this->pomBuf[i] = zdroj.pomBuf[i];
		}
	}
}

Vstup Vstup::operator=(const Vstup& zdroj)
{
	if (this != &zdroj)
	{
		Vstup::~Vstup();
		this->fhandle = zdroj.fhandle;
		this->pocetRiadkov = zdroj.pocetRiadkov;
		for (int i = 0; i < BUF_SIZE; i++)
		{
			this->pomBuf[i] = zdroj.pomBuf[i];
		}
	}
	return *this;
}

int Vstup::getPocetRiadkov()
{
	while (!feof(this->fhandle))
	{
		fgets(this->pomBuf, BUF_SIZE, this->fhandle);
		this->pocetRiadkov++;
	}
	rewind(this->fhandle);
	return this->pocetRiadkov;
}

char* Vstup::citaj()
{
	if (this->fhandle != nullptr)
	{
		if (!feof(this->fhandle))
		{
			fscanf(this->fhandle, "%s", this->pomBuf);
			return this->pomBuf;
		}
		/*else
		{
			rewind(this->fhandle);
			this->citaj();
		}*/
	}
	return nullptr;
}

char* Vstup::citajZnamky()
{
	fgets(this->pomBuf, BUF_SIZE, this->fhandle);
	return this->pomBuf;
}

Vstup::~Vstup()
{
	if (this->fhandle != nullptr)
	{
		fclose(this->fhandle);
	}
}
