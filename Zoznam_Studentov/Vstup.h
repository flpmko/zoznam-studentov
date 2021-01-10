#pragma once
#include <cstdio>

const int BUF_SIZE = 255;

class Vstup
{
private:
	FILE* fhandle = nullptr;
	char pomBuf[BUF_SIZE];
	int pocetRiadkov = 0;
public:
	Vstup();
	Vstup(char* nazovSuboru);
	Vstup(const Vstup& zdroj);
	Vstup operator=(const Vstup& zdroj);
	int getPocetRiadkov();
	char* citaj();
	char* citajZnamky();
	~Vstup();
};

