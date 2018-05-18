#include "GrafMacierz.h"
#include <iostream>
#include <fstream>

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
	int licznik = 0, wp, wk, waga;
	if (wierzcholek != 0)
	{
		clearMacierz();
		short int **temp1 = nullptr;
		short int **temp2 = nullptr;
		short int *temp3 = nullptr;
		wagi = temp3;
		grafS = temp1;
		grafNS = temp2;
	}
	plik.open("randomowe.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));
	grafS = new short int *[wierzcholek];	//tworze tablice wskaznikow, ktorej wielkosc jest rowna ilosci wierzcholkow
	grafNS = new short int *[wierzcholek];
	for (int i = 0; i < wierzcholek; i++)	//tworze wiersze w tablicy wskaznikow, wiersze dlugosci odpowiadajacej ilosci krawedzi
	{
		grafS[i] = new short int[krawedz];
		grafNS[i] = new short int[krawedz];
	}
	for (int i = 0; i < wierzcholek; i++)
		for (int j = 0; j < krawedz; j++)
		{
			grafS[i][j] = 0;		//przypisuje wszystkim komorkom wartosc poczatkowa 0
			grafNS[i][j] = 0;
		}
	wagi = new short int[krawedz];
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp][licznik] = 1;
		grafS[wk][licznik] = -1;
		grafNS[wp][licznik] = 1;
		grafNS[wk][licznik] = 1;
		wagi[licznik] = waga;
		licznik++;
	}
	plik.close();
}

void GrafMacierz::createGiven()
{
	ifstream plik;
	int licznik = 0, wp, wk, waga;
	if (wierzcholek != 0)
	{
		clearMacierz();
		short int **temp1 = nullptr;
		short int **temp2 = nullptr;
		short int *temp3 = nullptr;
		wagi = temp3;
		grafS = temp1;
		grafNS = temp2;
	}
	plik.open("podane.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));
	grafS = new short int *[wierzcholek];	//tworze tablice wskaznikow, ktorej wielkosc jest rowna ilosci wierzcholkow
	grafNS = new short int *[wierzcholek];
	for (int i = 0; i < wierzcholek; i++)	//tworze wiersze w tablicy wskaznikow, wiersze dlugosci odpowiadajacej ilosci krawedzi
	{
		grafS[i] = new short int[krawedz];
		grafNS[i] = new short int[krawedz];
	}
	for (int i = 0; i < wierzcholek; i++)
		for (int j = 0; j < krawedz; j++)
		{
			grafS[i][j] = 0;		//przypisuje wszystkim komorkom wartosc poczatkowa 0
			grafNS[i][j] = 0;
		}
	wagi = new short int[krawedz];
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp][licznik] = 1;
		grafS[wk][licznik] = -1;
		grafNS[wp][licznik] = 1;
		grafNS[wk][licznik] = 1;
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
		<< "Twoj graf w postaci tabeli:" << endl
		<< "----------SKIEROWANY----------" << endl;
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
			cout << grafS[i][j] << "\t";					//wypisywanie wartosci z macierzy
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
	cout << "\t\t\tWAGI KRAWEDZI\n";
	for (int i = 0; i < krawedz; i++)
	{
		if (i == 0)
			cout << "Numer Krawedzi:\t";
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < krawedz; i++)
	{
		if (i == 0)
			cout << "Waga Krawedzi:\t";
		cout << wagi[i] << "\t";
	}
	cout << "\n\n----------NIESKIEROWANY----------" << endl;

	for (int i = 0; i < wierzcholek; i++)
	{
		if (i == 0)
		{
			cout << "\t";
			for (int m = 0; m < krawedz; m++)
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
			cout << grafNS[i][j] << "\t";					//wypisywanie wartosci z macierzy
		}
		cout << endl;
		if (i % 2 == 1)
			for (int ilosc = 0; ilosc < krawedz * 8; ilosc++)		//co drugi wiersz oddzielony jest ciagiem: "----(...)--"
				cout << "-";
		else
			for (int ilosc = 0; ilosc < krawedz * 8; ilosc++)	//co drugi wiersz oddzielony jest ciagiem: "~~~~(...)~~"
				cout << "~";
		cout << endl;
	}
	cout << "\t\t\tWAGI KRAWEDZI\n";
	for (int i = 0; i < krawedz; i++)
	{
		if (i == 0)
			cout << "Numer Krawedzi:\t";
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < krawedz; i++)
	{
		if (i == 0)
			cout << "Waga Krawedzi:\t";
		cout << wagi[i] << "\t";
	}
	cout << endl;
	cin.get();
	cin.get();
}

void GrafMacierz::clearMacierz()
{
	for (int i = 0; i < wierzcholek; i++) 
			delete[] grafS[i];
	delete[] grafS;
	for (int i = 0; i < wierzcholek; i++)
		delete[] grafNS[i];
	delete[] grafNS;
	delete[] wagi;
}
