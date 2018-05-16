#include "GrafListy.h"
#include <fstream>
#include <iostream>

using namespace std;

GrafListy::GrafListy()
{
}


GrafListy::~GrafListy()
{
	clearGraf();
}

void GrafListy::createRandom()
{
	ifstream plik;
	if (wierzcholek != 0)
		clearGraf();
	plik.open("randomowe.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));

	grafS = new List[wierzcholek];

	for (int i = 0; i < wierzcholek; i++)
	{
		List p;
		grafS[i] = p;
	}
	for (int i = 0; i < wierzcholek; i++)		//przypisuje wszystkim komorkom wartosc poczatkowa 0,0
		grafS[i].push(0,0);			

	int wp, wk, waga;
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp].push(wk, waga);
	}

	plik.close();
}

void GrafListy::createGiven()
{
	ifstream plik;
	if (wierzcholek != 0)
		clearGraf();
	plik.open("podane.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));

	grafS = new List[wierzcholek];

	for (int i = 0; i < wierzcholek; i++)
	{
		List p;
		grafS[i] = p;
	}
	for (int i = 0; i < wierzcholek; i++)		//przypisuje wszystkim komorkom wartosc poczatkowa 0,0
		grafS[i].push(0, 0);

	int wp, wk, waga;
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp].push(wk, waga);
	}

	plik.close();
}

bool GrafListy::czySpojny()
{
	bool spojny = false;



	return spojny;
}

void GrafListy::wypisz()
{
	Node *p;
	cout << "Dane Twojego grafu:" << endl
		<< "Wierzcholki: " << wierzcholek << endl
		<< "Krawedzie: " << krawedz << endl
		<< "Gestosc: " << gestosc << "%" << endl
		<< "Twoj graf w postaci spisu (wierzcholek/waga krawedzi):" << endl;
	for (int i = 0; i < wierzcholek; i++)
	{
		p = grafS[i].getHead();
		cout << "Graf[" << i << "] - ";
		do
		{
			cout << "[" << p->data << " /" << p->waga << "]\t";
			p = p->next;
		} while (p->next);
		cout << endl;
	}
	cout << endl;
}

void GrafListy::clearGraf()
{
	for (int i = 0; i < wierzcholek; i++)
		grafS->clearList();
	delete[] grafS;
}
