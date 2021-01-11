#include "Student.h"
#include "Vstup.h"
#include "Zoznam.h"
#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Zoznam zoznam(argv[1]);
	cout << "-----------------------STUDENTI----------------------" << endl;
	zoznam.vypis();
	zoznam.exportujAckarov();
	cout << "-----------------------ACKARI----------------------" << endl;
	cout << "vyexporotvani do suboru ackari.out" << endl;
	cout << "-----------------------NAJHORSI----------------------" << endl;
	zoznam.vypisNajhorsich();

	return 0;
}