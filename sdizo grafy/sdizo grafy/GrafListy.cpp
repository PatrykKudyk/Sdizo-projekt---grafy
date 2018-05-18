#include "GrafListy.h"
#include <fstream>
#include <iostream>
#include "Heap.h"

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
	int wp, wk, waga;
	ifstream plik;
	if (wierzcholek != 0)
		clearGraf();
	plik.open("randomowe.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));

	grafS = new List[wierzcholek];
	grafNS = new List[wierzcholek];

	for (int i = 0; i < wierzcholek; i++)
	{
		List p1, p2;
		grafS[i] = p1;
		grafNS[i] = p2;
	}
	for (int i = 0; i < wierzcholek; i++)		//przypisuje wszystkim komorkom wartosc poczatkowa 0,0
	{
		grafS[i].push(0, 0);
		grafNS[i].push(0, 0);
	}
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp].push(wk, waga);
		grafNS[wp].push(wk, waga);
		grafNS[wk].push(wp, waga);
	}

	plik.close();
}

void GrafListy::createGiven()
{
	int wp, wk, waga;
	ifstream plik;
	if (wierzcholek != 0)
		clearGraf();
	plik.open("podane.txt", ios::in);
	plik >> krawedz >> wierzcholek;
	gestosc = ((200 * krawedz) / (wierzcholek*(wierzcholek - 1)));

	grafS = new List[wierzcholek];
	grafNS = new List[wierzcholek];

	for (int i = 0; i < wierzcholek; i++)
	{
		List p1, p2;
		grafS[i] = p1;
		grafNS[i] = p2;
	}
	for (int i = 0; i < wierzcholek; i++)		//przypisuje wszystkim komorkom wartosc poczatkowa 0,0
	{
		grafS[i].push(0, 0);
		grafNS[i].push(0, 0);
	}
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp].push(wk, waga);
		grafNS[wp].push(wk, waga);
		grafNS[wk].push(wp, waga);
	}

	plik.close();
}

bool GrafListy::czySpojny()
{
	bool spojny = false;
	Heap kopiec;


	return spojny;
}

void GrafListy::DFS(int wierzcholek)
{

}

void GrafListy::wypisz()
{
	Node *p;
	cout << "Dane Twojego grafu:" << endl
		<< "Wierzcholki: " << wierzcholek << endl
		<< "Krawedzie: " << krawedz << endl
		<< "Gestosc: " << gestosc << "%" << endl
		<< "Twoj graf w postaci spisu (wierzcholek/waga krawedzi):" << endl
		<< "----------SKIEROWANY----------" << endl;
	for (int i = 0; i < wierzcholek; i++)
	{
		p = grafS[i].getHead();
		cout << "Graf[" << i << "] - ";
		if (p == 0)
			cout << "brak krawedzi" << endl;
		else
		{
			do
			{
				cout << "[" << p->data << " /" << p->waga << "]\t";
				p = p->next;
			} while (p->next);
			cout << endl;
		}
	}
	cout << endl << "----------NIESKIEROWANY----------" << endl;

	for (int i = 0; i < wierzcholek; i++)
	{
		p = grafNS[i].getHead();
		cout << "Graf[" << i << "] - ";
		if (p == 0)
			cout << "brak krawedzi" << endl;
		else
		{
			do
			{
				cout << "[" << p->data << " /" << p->waga << "]\t";
				p = p->next;
			} while (p->next);
			cout << endl;
		}
	}
}

void GrafListy::clearGraf()
{
	for (int i = 0; i < wierzcholek; i++)
		grafS->clearList();
	delete[] grafS;

	for (int i = 0; i < wierzcholek; i++)
		grafNS->clearList();
	delete[] grafNS;
	//delete[] odwiedzone;
}
