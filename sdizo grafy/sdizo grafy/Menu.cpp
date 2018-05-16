#include "Menu.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::genRand(int wierzcholki, int gestosc)
{
	srand(time(NULL));
	fstream plik;
	int krawedzie = ((gestosc*wierzcholki*(wierzcholki - 1)) / 200); // dzielimy przez 200, bo uwzgledniamy procentowosc gestoci (100) i (2), ktore jest podane we wzorze [2*100 = 200]

	plik.open("randomowe.txt", ios::out);
	for (int i = 0, w1, w2; i <= krawedzie; i++)
	{
		if (i == 0)
			plik << krawedzie << " " << wierzcholki << endl;
		else
		{
			do
			{
				w1 = rand() % wierzcholki;
				w2 = rand() % wierzcholki;
			} while (w1 == w2);

			plik << w1 << " " << w2 << " " << (rand() % 1000) + 1 << endl;
		}
	}
	plik.close();
}

void Menu::menuGlowne()
{
	bool dzialanie = true;
	int wybor, wierzcholki, gestosc;
	do {
		system("cls");
		cout << "[1] Wczytaj dane z pliku." << endl
			<< "[2] Wygeneruj graf losowo." << endl
			<< "[3] Wyswietl graf listowo i macierzowo na ekranie." << endl
			<< "[4] Algorytm 1 (np. Prima) macierzowo i listowo z wyswietleniem wynikow." << endl
			<< "[5] Algorytm 2 (np. Kruskala) macierzowo i listowo z wyswietleniem wynikow." << endl
			<< "[6] Wyjdz z programu." << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			grafM.createGiven();
			grafL.createGiven();
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
			break;
		case 2:
			system("cls");
			cout << "Podaj liczbe wierzcholkow:\t";
			cin >> wierzcholki;
			cout << "Podaj gestosc grafu (w procentach):\t";
			cin >> gestosc;
			genRand(wierzcholki, gestosc);
			grafM.createRandom();
			grafL.createRandom();
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
			break;
		case 3:
			system("cls");
			cout << "Graf na liscie:\n\n";
			grafL.wypisz();
			cout << "Graf na macierzy:\n";
			grafM.wypisz();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			dzialanie = false;
			break;
		default:
			break;
		}
	} while (dzialanie);
}
