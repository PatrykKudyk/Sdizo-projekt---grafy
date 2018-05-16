#include "GrafMacierz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

GrafMacierz::GrafMacierz()
{
}


GrafMacierz::~GrafMacierz()
{
	clearMacierz();
}

void GrafMacierz::createRandom()
{
	ifstream plik;
	plik.open("randomowe.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));
	graf = new short int *[wierzcholek];	//tworze tablice wskaznikow, ktorej wielkosc jest rowna ilosci wierzcholkow

	for (int i = 0; i < wierzcholek; i++)	//tworze wiersze w tablicy wskaznikow, wiersze dlugosci odpowiadajacej ilosci krawedzi
		graf[i] = new short int[krawedz];

	for (int i = 0; i < wierzcholek; i++)
		for (int j = 0; j < krawedz; j++)
			graf[i][j] = 0;		//przypisuje wszystkim komorkom wartosc poczatkowa 0

	wagi = new short int[krawedz];

	int licznik = 0, wp, wk, waga;

	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		graf[wp][licznik] = 1;
		graf[wk][licznik] = -1;
		wagi[licznik] = waga;
		licznik++;
	}
	
	plik.close();
}

void GrafMacierz::createGiven()
{
	ifstream plik;
	plik.open("podane.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));
	graf = new short int *[wierzcholek];	//tworze tablice wskaznikow, ktorej wielkosc jest rowna ilosci wierzcholkow

	for (int i = 0; i < wierzcholek; i++)	//tworze wiersze w tablicy wskaznikow, wiersze dlugosci odpowiadajacej ilosci krawedzi
		graf[i] = new short int[krawedz];

	for (int i = 0; i < wierzcholek; i++)
		for (int j = 0; j < krawedz; j++)
			graf[i][j] = 0;		//przypisuje wszystkim komorkom wartosc poczatkowa 0

	wagi = new short int[krawedz];

	int licznik = 0;
	while (!plik.eof())
	{
		int wp, wk, waga;
		plik >> wp >> wk >> waga;
		graf[wp][licznik] = 1;
		graf[wk][licznik] = -1;
		wagi[licznik] = waga;
		licznik++;
	}

	plik.close();
}

void GrafMacierz::wypisz()
{
	cout << "Dane Twojego grafu:" << endl
		<< "Wierzcholki: " << wierzcholek << endl
		<< "Krawedzie: " << krawedz << endl
		<< "Gestosc: " << gestosc << "%" << endl
		<< "Twoj graf w postaci tabeli:" << endl;
	for(int i = 0; i < wierzcholek; i++)
	{
		if (i == 0)
		{
			cout << "\t";
			for (int m = 0; m < krawedz ; m++)
			{
				cout << m << "\t";
			}
			cout << endl;
			for (int ilosc = 0; ilosc < krawedz * 8; ilosc++)	//wypisanie wiersza skladajacego sie z ciagu: "----(...)--"
				cout << "-";
			cout << endl;
		}
		cout << i << "\t";
		for (int j = 0; j < krawedz; j++)
		{
			cout << graf[i][j] << "\t";					//wypisywanie wartosci z macierzy
		}
		cout << endl;
		if(i%2 == 1)
			for(int ilosc = 0; ilosc < krawedz*8 ; ilosc++)		//co drugi wiersz oddzielony jest ciagiem: "----(...)--"
				cout << "-";
		else
			for (int ilosc = 0; ilosc < krawedz * 8; ilosc++)	//co drugi wiersz oddzielony jest ciagiem: "~~~~(...)~~"
				cout << "~";
		cout << endl;
	}
	cout << "Wagi krawedzi:\n";
	for (int i = 0; i < krawedz; i++)
		cout << i << "\t";
	cout << endl;
	for (int i = 0; i < krawedz; i++)
		cout << wagi[i] << "\t";
	cout << endl;
	
	cin.get();
	cin.get();
}

void GrafMacierz::clearMacierz()
{
	for (int i = 0; i < krawedz; i++) 
			delete[] graf[i];
	delete[] graf;
	delete[] wagi;
}
