#include "GrafListy.h"
#include <fstream>
#include <iostream>
#include "Heap.h"
#include "HeapMin.h"

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
	/*for (int i = 0; i < wierzcholek; i++)		//przypisuje wszystkim komorkom wartosc poczatkowa 0,0
	{
		grafS[i].push(0, 0);
		grafNS[i].push(0, 0);
	}*/
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
	/*for (int i = 0; i < wierzcholek; i++)		//przypisuje wszystkim komorkom wartosc poczatkowa 0,0
	{
		grafS[i].push(0, 0);
		grafNS[i].push(0, 0);
	}*/
	while (!plik.eof())
	{
		plik >> wp >> wk >> waga;
		grafS[wp].push(wk, waga);
		grafNS[wp].push(wk, waga);
		grafNS[wk].push(wp, waga);
	}

	plik.close();
}

void GrafListy::dijkstra(int podPocz, int podKonc)
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
		Node *p = nullptr;
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
			for (p = grafS[numPom].getHead();;)
			{
				if (QS[p->data] == false)
				{
					if (dojscie[p->data] > (dojscie[numPom] + p->waga))
					{
						dojscie[p->data] = (dojscie[numPom] + p->waga);
						poprzednik[p->data] = numPom;
					}
				}
				if (p->next == nullptr)
					break;
				p = p->next;
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

void GrafListy::prim()
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
		Node *p;
		for (p = grafNS[wPom].getHead(); ; )
		{
			if (odwiedzone[p->data] == false)
				kolejka.push(wPom, p->data, p->waga);
			p = p->next;
			if (p == nullptr)
				break;
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
		delete p;
	}
	kolejka.clearHeap();
	for (int i = 0; i < wierzcholek - 1; i++)
		cout << i + 1 << ") " << zbiorKrawedzi[i].wPocz << "  " << zbiorKrawedzi[i].wKonc << "  " << zbiorKrawedzi[i].waga << endl;
	delete[] odwiedzone;
	delete[] zbiorKrawedzi;
}

void GrafListy::wyswietlSciezke(int *poprzednik, int start, int koniec)
{
	if (poprzednik[start] == koniec)
	{
		cout << poprzednik[start] << "->" << start << "->";
		return;
	}
	wyswietlSciezke(poprzednik, poprzednik[koniec], start);

	cout << koniec << " ";
}

bool GrafListy::czySpojny(int wklStart)
{
	bool *odwiedzone = new bool[wierzcholek];
	for (int i = 0; i < wierzcholek; i++)
		odwiedzone[i] = false;
	Heap kopiec;
	odwiedzone[wklStart] = true;
	kopiec.push(wklStart);
	int licznik = 0;
	while (!kopiec.isEmpty())
	{
		wklStart = kopiec.getRoot();
		kopiec.pop();

		for (Node *p = grafNS[wklStart].getHead(); ;)
		{
			if (odwiedzone[p->data] == false) {
				kopiec.push(p->data);
				odwiedzone[p->data] = true;
			}
			if (p->next == nullptr)
				break;
			p = p->next;
		}

		licznik = 0;
		for (int i = 0; i < wierzcholek; i++)
			if (odwiedzone[i] == true)
				licznik++;

		if (licznik == wierzcholek)
		{
			delete[] odwiedzone;
			return true;
		}
	}

	delete[] odwiedzone;
	return false;
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
			} while (p != nullptr);
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
			} while (p != nullptr);
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
}
