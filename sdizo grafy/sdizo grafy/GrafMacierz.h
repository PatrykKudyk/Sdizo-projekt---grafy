#pragma once

class GrafMacierz
{
	int krawedz, wierzcholek, gestosc;
	short int **graf;
	short int *wagi;
public:
	GrafMacierz();
	~GrafMacierz();
	void createRandom();
	void createGiven();
	void wypisz();
	void clearMacierz();
	void create();
};

