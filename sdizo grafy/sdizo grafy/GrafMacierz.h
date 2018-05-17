#pragma once

class GrafMacierz
{
	int krawedz, wierzcholek, gestosc;
	short int **grafS;
	short int **grafNS;
	short int *wagi;
public:
	GrafMacierz();
	~GrafMacierz();
	void createRandom();
	void createGiven();
	void wypisz();
	void clearMacierz();
};

