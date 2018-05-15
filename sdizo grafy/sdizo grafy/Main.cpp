#include <iostream>
#include <ctime>
#include "Menu.h"

int main()
{
//	srand(time(NULL));

	GrafMacierz graf;
	graf.createRandom();
	graf.wypisz();
	
	return 0;
}
