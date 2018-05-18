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
	bool czySpojny(int wklStart);
	void DFS(int wierzcholek);
	void wypisz();
	void clearGraf();
};
