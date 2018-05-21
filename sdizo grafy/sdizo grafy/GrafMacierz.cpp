#include "GrafMacierz.h"
#include <iostream>
#include <fstream>
#include "HeapMin.h"

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

void GrafMacierz::dijkstra(int podPocz, int podKonc)
{
	bool niepustyQ;
	int najmniejszeD, numPom;
	int *dojscie = new int[wierzcholek];		//tablica z kosztami dojscia
	int *poprzednik = new int[wierzcholek];		//tablica poprzednikow na sciezkach
	bool *QS = new bool[wierzcholek];			//tablica logiczna okreslajaca polozenie wierzcholka false ----> Q    true ----> S

	for (int i = 0; i < wierzcholek; i++)
		QS[i] = false;							//wrzucamy wszystkie wierzcholki do tablicy Q (ustawiamy false)

	for (int i = 0; i < wierzcholek; i++)
		dojscie[i] = INT_MAX;					//ustawiamy wszystkie wartosci dojscia na maksymalna wartosc dla inta
	dojscie[podPocz] = 0;						//dla naszego wierzcholka poczatkowego ustawiamy wartosc 0

	for (int i = 0; i < wierzcholek; i++)
		poprzednik[i] = -1;						//tablice poprzednikow wypelniamy wartosciami -1

	do
	{
		numPom = -200;
		niepustyQ = false;
		najmniejszeD = INT_MAX;

		for (int i = 0; i < wierzcholek; i++)
			if (QS[i] == false)
				if (dojscie[i] < najmniejszeD)
				{
					najmniejszeD = dojscie[i];
					numPom = i;
				}
		if (numPom != -200)
		{
			QS[numPom] = true;						//przeniesienie wierzcholka o najmniejszym koszcie dojscia do zbioru S
			for (int i = 0; i < krawedz; i++)
			{
				if (grafS[numPom][i] == 1)
				{
					for (int j = 0; j < wierzcholek; j++)
					{
						if (grafS[j][i] == -1)
						{
							if (QS[j] == false)
							{
								if (dojscie[j] > (dojscie[numPom] + wagi[i]))
								{
									dojscie[j] = (dojscie[numPom] + wagi[i]);
									poprzednik[j] = numPom;
								}
							}
						}
					}
				}
			}

			for (int i = 0; i < wierzcholek; i++)	//sprawdzamy czy zbior Q posiada jakies elementy
			{
				if (QS[i] == false)
					niepustyQ = true;
			}
		}
		else
			break;
	} while (niepustyQ);

	if (podPocz == podKonc)
		cout << "Sciezka pusta, koszt 0" << endl;
	else if (dojscie[podKonc] == INT_MAX)
		cout << "Dojscie do wierzcholka " << podKonc << " jest niemozliwe.";
	else
	{
		numPom = podKonc;
		cout << "Sciezka z wierzcholka " << podPocz << " do wierzcholka " << podKonc << " wyglada nastepujaco:" << endl << numPom << " ";
		do
		{
			numPom = poprzednik[numPom];
			cout << " <-- " << numPom;
		} while (poprzednik[numPom] != -1);
		cout << endl << "Koszt tego przejscia to: " << dojscie[podKonc] << endl;
	}
	delete[] dojscie;
	delete[] poprzednik;
	delete[] QS;

}

void GrafMacierz::prim()
{
	HeapMin	kolejka;			//kolejka priorytetowa
	bool *odwiedzone = new bool[wierzcholek];
	for (int i = 0; i < wierzcholek; i++)
		odwiedzone[i] = false;
	Krawedz *zbiorKrawedzi = new Krawedz[wierzcholek - 1];
	int wPom = 0;
	odwiedzone[wPom] = true;		//0-wy wierzcholek odwiedzony
	Krawedz kPom;
	for (int i = 0; i < wierzcholek - 1; i++)
	{
		for (int j = 0; j < krawedz; j++)
		{
			if (grafNS[wPom][j] == 1)
			{
				for (int k = 0; k < wierzcholek; k++)
				{
					if (k != wPom && grafNS[k][j] == 1)
					{
						if (odwiedzone[k] == false)
							kolejka.push(wPom, k, wagi[j]);
					}
				}
			}

		}
		if (!kolejka.isEmpty()) {
			do {
				kPom.waga = kolejka.getRoot().waga;
				kPom.wPocz = kolejka.getRoot().wPocz;
				kPom.wKonc = kolejka.getRoot().wKonc;
				kolejka.pop();
			} while (odwiedzone[kPom.wKonc]);

			zbiorKrawedzi[i].waga = kPom.waga;
			zbiorKrawedzi[i].wPocz = kPom.wPocz;
			zbiorKrawedzi[i].wKonc = kPom.wKonc;
			odwiedzone[kPom.wKonc] = true;
			wPom = kPom.wKonc;
		}
	}
	for (int i = 0; i < wierzcholek - 1; i++)
		cout << i+1 << ") " << zbiorKrawedzi[i].wPocz << "  " << zbiorKrawedzi[i].wKonc << "  " << zbiorKrawedzi[i].waga << endl;
	delete[] odwiedzone;
	delete[] zbiorKrawedzi;
}

void GrafMacierz::wypisz()
{
	cout << "Dane Twojego grafu:" << endl
		<< "Wierzcholki: " << wierzcholek << endl
		<< "Krawedzie: " << krawedz << endl
		<< "Gestosc: " << gestosc << "%" << endl
		<< "Twoj graf w postaci tabeli:" << endl
		<< "----------SKIEROWANY----------" << endl;
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
			cout << grafS[i][j] << "\t";					//wypisywanie wartosci z macierzy
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
