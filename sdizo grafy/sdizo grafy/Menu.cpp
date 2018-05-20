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
	ofstream plik;
	int krawedzie = ((gestosc*wierzcholki*(wierzcholki - 1)) / 200); // dzielimy przez 200, bo uwzgledniamy procentowosc gestoci (100) i (2), ktore jest podane we wzorze [2*100 = 200]

	plik.open("randomowe.txt", ios::out| ios::trunc);
	for (int i = 0, w1, w2; i <= krawedzie; i++)
	{
		if (i == 0)
			plik << krawedzie << " " << wierzcholki << endl;
		else if (i > 0 && i <= wierzcholki)
		{
			do
			{
				w1 = i - 1;
				w2 = rand() % wierzcholki;
			} while (w1 == w2);

			if (i == krawedzie)
				plik << w1 << " " << w2 << " " << (rand() % 5000) + 1;
			else
				plik << w1 << " " << w2 << " " << (rand() % 5000) + 1 << endl;
		}
		else
		{
			do
			{
				w1 = rand() % wierzcholki;
				w2 = rand() % wierzcholki;
			} while (w1 == w2);

			if(i == krawedzie)
				plik << w1 << " " << w2 << " " << (rand() % 5000) + 1;
			else 
				plik << w1 << " " << w2 << " " << (rand() % 5000) + 1 << endl;
		}
	}
	plik.close();
}

void Menu::menuGlowne()
{
	bool dzialanie = true;
	bool spojnosc;
	int wybor, wierzcholki, gestosc;
	do {
		system("cls");
		cout << "[1] Wczytaj dane z pliku." << endl
			<< "[2] Wygeneruj graf losowo." << endl
			<< "[3] Wyswietl graf listowo i macierzowo na ekranie." << endl
			<< "[4] Algorytm 1 - Dijkstry" << endl
			<< "[5] Algorytm 2 - Prima" << endl
			<< "[6] Wyjdz z programu." << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			do
			{
				grafL.createGiven();
				spojnosc = grafL.czySpojny(0);
				if(!spojnosc)
				{
					cout << "Podany przez ciebie graf jest niespojny!" << endl
						<< "Podaj nowy, a nastepnie nacisnij dowolny przycisk." << endl;
					cin.get();
					cin.get();
				}
			} while (!spojnosc);
			grafM.createGiven();
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
			do 
			{
				genRand(wierzcholki, gestosc);
				grafL.createRandom();
				spojnosc = grafL.czySpojny(0);
			} while (!spojnosc);
			grafM.createRandom();
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
			menuDijkstra();
			break;
		case 5:
			menuPrim();
			break;
		case 6:
			dzialanie = false;
			break;
		default:
			break;
		}
	} while (dzialanie);
}

void Menu::menuDijkstra()
{
	int w1, w2, wybor;
	bool dzialanie = true;
	do {
		system("cls");
		cout << "\t\t\tAlgorytm Dijkstry" << endl
			<< "\t\tCo chcialbys teraz zrobic?" << endl
			<< "[1] Sprawdzic Najkrotsza sciezke pomiedzy dwoma wierzcholkami." << endl
			<< "[2] Wrocic do menu glownego." << endl;
		cin >> wybor;
		switch(wybor)
		{
		case 1:
			cout << "Podaj wierzcholek poczatkowy:\t";
			cin >> w1;
			cout << "Podaj wierzcholek koncowy:\t";
			cin >> w2;
			cout << endl << "Listowo:" << endl;
			grafL.dijkstra(w1, w2);
			cout << endl << "Macierzowo:" << endl;
			grafM.dijkstra(w1, w2);
			cin.get();
			cin.get();
			break;
		case 2:
			dzialanie = false;
			break;
		default:
			cout << "Wprowadziles liczbe z poza zakresu!" << endl;
			cin.get();
			cin.get();
			break;
		}
	} while (dzialanie);
}

void Menu::menuPrim()
{
	int wybor;
	bool dzialanie = true;
	do {
		system("cls");
		cout << "\t\t\tAlgorytm Prima" << endl
			<< "\t\tCo chcialbys teraz zrobic?" << endl
			<< "[1] Wyznaczyc Minimalne Drzewo Rozpinajace dla grafu." << endl
			<< "[2] Wrocic do menu glownego." << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Minimalne drzewo rozpinajace dla Twojego grafu to: " << endl
				<< "(Wierzcholek Poczatkowy)    (Wierzcholek Koncowy)    (Waga)" << endl;
			cout << endl << "Listowo:" << endl;
			grafL.prim();
			cout << endl << "Macierzowo:" << endl;

			cin.get();
			cin.get();
			break;
		case 2:
			dzialanie = false;
			break;
		default:
			cout << "Wprowadziles liczbe z poza zakresu!" << endl;
			cin.get();
			cin.get();
			break;
		}
	} while (dzialanie);
}
