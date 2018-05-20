#pragma once
#include "List.h"

class GrafListy
{
	int krawedz, wierzcholek, gestosc;
	List *grafS;
	List *grafNS;
public:
	GrafListy();
	~GrafListy();
	void createRandom();
	void createGiven();
	void dijkstra(int podPocz, int podKonc);
	void prim();
	void wyswietlSciezke(int *poprzednik, int start, int koniec);
	bool czySpojny(int wklStart);
	void wypisz();
	void clearGraf();
};
