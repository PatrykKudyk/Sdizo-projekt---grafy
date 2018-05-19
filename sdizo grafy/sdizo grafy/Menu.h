#pragma once
#include "GrafMacierz.h"
#include "GrafListy.h"

class Menu
{
	GrafMacierz grafM;
	GrafListy grafL;

public:
	Menu();
	~Menu();
	void genRand(int wierzcholki, int gestosc);
	void menuGlowne();
	void menuDijkstra();
};

