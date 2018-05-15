#include "GrafMacierz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
	
	cout << "Podaj liczbe wierzcholkow:" << endl;
	cin >> wierzcholek;
	cout << "Podaj gestosc (w procentach):" << endl;
	cin >> gestosc;
	krawedz = ((gestosc*wierzcholek*(wierzcholek - 1)) / 200); // dzielimy przez 200, bo uwzgledniamy procentowosc gestoci (100) i (2), ktore jest podane we wzorze [2*100 = 200]
	if(graf != nullptr)
		clearMacierz();
	graf = new short int *[wierzcholek];	//tworze tablice wskaznikow, ktorej wielkosc jest rowna ilosci wierzcholkow
	for(int i = 0; i < wierzcholek; i++)	//tworze wiersze w tablicy wskaznikow, wiersze dlugosci odpowiadajacej ilosci krawedzi
	{
		graf[i] = new short int[krawedz];
	}
	for(int i = 0; i < wierzcholek; i++)
	{
		for (int j = 0; j < krawedz; j++)
		{
			graf[i][j] = 0;		//przypisuje wszystkim komorkom wartosc poczatkowa 0
		}
	}





}

void GrafMacierz::createGiven()
{
	/*int temp;
	string bufor;
	fstream file;

	file.open("data.txt", ios::in);
	if (file.good() == true)
		cout << "Odczyt udany!" << endl;
	else
	{
		cout << "Nieudane wczytywanie pliku!" << endl;
		cin.get();
		cin.get();
	}
	int licznik = 0;
	while (file.eof() == NULL)
	{
		getline(file, bufor);
		istringstream iss(bufor);
		iss >> temp;
		if (licznik == 0)
		{
			
		} else
		{
			
		}
		push(temp);
		this->size++;
		licznik++;
	}
	file.close();*/
}

void GrafMacierz::wypisz()
{
	system("cls");
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
	cin.get();
	cin.get();
}

void GrafMacierz::clearMacierz()
{
	for (int i = 0; i < wierzcholek; i++) 
		delete[] graf[i];
	delete[] graf;
}
