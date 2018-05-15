#pragma once
#include <vector>

class GrafMacierz
{
	int krawedz, wierzcholek, gestosc;
	short int **graf;
public:
	GrafMacierz();
	~GrafMacierz();
	void createRandom();
	void createGiven();
	void wypisz();
	void clearMacierz();
};

