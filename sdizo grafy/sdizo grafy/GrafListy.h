#pragma once
#include "List.h"

class GrafListy
{
	int krawedz, wierzcholek, gestosc;
	List *grafS;
	List *grafNS;
	bool *odwiedzone;
public:
	GrafListy();
	~GrafListy();
	void createRandom();
	void createGiven();
	bool czySpojny();
	void DFS(int wierzcholek);
	void wypisz();
	void clearGraf();
};
