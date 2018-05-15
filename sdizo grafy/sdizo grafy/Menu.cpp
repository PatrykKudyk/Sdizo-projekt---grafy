#include "Menu.h"
#include <iostream>

using namespace std;


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::menuGlowne()
{
	int wybor;
	cout << "[1] Wczytaj dane z pliku." << endl
		<< "[2] Wygeneruj graf losowo." << endl
		<< "[3] Wyœwietl graf listowo i macierzowo na ekranie." << endl
		<< "[4] Algorytm 1 (np. Prima) macierzowo i listowo z wyœwietleniem wyników." << endl
		<< "[5] Algorytm 2 (np. Kruskala) macierzowo i listowo z wyœwietleniem wyników." << endl;
	cin >> wybor;
	switch(wybor)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;  
	}
}
