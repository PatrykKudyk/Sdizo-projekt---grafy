#pragma once
#include "List.h"

class GrafListy
{
	int krawedz, wierzcholek, gestosc;
	List *grafS;
public:
	GrafListy();
	~GrafListy();
	void createRandom();
	void createGiven();
	void wypisz();
	void clearGraf();
};
