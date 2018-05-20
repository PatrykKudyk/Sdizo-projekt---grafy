#include "HeapMin.h"
#include <iostream>


using namespace std;

void HeapMin::push(int wP, int wK, int waga)
{
	Krawedz *pom = new Krawedz[size + 1];
	for (int i = 0; i < size; i++)
	{
		pom[i].wPocz = arr[i].wPocz;
		pom[i].wKonc = arr[i].wKonc;
		pom[i].waga = arr[i].waga;
	}
		
	if (size == 0)
		delete arr;
	else
		delete[] arr;
	arr = pom;

	int i = size;
	int j = (i - 1) / 2;
	while (i > 0 && arr[j].waga > waga)
	{
		arr[i].wPocz = arr[j].wPocz;
		arr[i].wKonc = arr[j].wKonc;
		arr[i].waga = arr[j].waga;
		i = j;
		j = (i - 1) / 2;
	}
	arr[i].waga = waga;
	arr[i].wKonc = wK;
	arr[i].wPocz = wP;
	size++;
}

void HeapMin::pop()
{
	if (size == 1)
	{
		Krawedz *pom = new Krawedz;
		delete[] arr;
		arr = pom;
		size = 0;
	}
	else if(size > 1)
	{
		arr[0].waga = arr[size - 1].waga;
		arr[0].wPocz = arr[size - 1].wPocz;
		arr[0].wKonc = arr[size - 1].wKonc;
		Krawedz *pom = new Krawedz[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			pom[i].waga = arr[i].waga;
			pom[i].wPocz = arr[i].wPocz;
			pom[i].wKonc = arr[i].wKonc;
		}
		delete[] arr;
		arr = pom;
		size--;
	}

	if (size - 1)
	{
		Krawedz v;
		v.waga = arr[0].waga;
		v.wKonc = arr[0].wKonc;
		v.wPocz = arr[0].wPocz;
		int i = 0, j = 1;
		while (j < size)
		{
			if (j + 1 < size && arr[j + 1].waga < arr[j].waga)
				j++;
			if (v.waga <= arr[j].waga)
				break;
			arr[i].waga = arr[j].waga;
			arr[i].wPocz = arr[j].wPocz;
			arr[i].wKonc = arr[j].wKonc;
			i = j;
			j = 2 * j + 1;
		}
		arr[i].waga = v.waga;
		arr[i].wPocz = v.wPocz;
		arr[i].wKonc = v.wKonc;
	}
}

bool HeapMin::isEmpty()
{
	if (size == 0)
		return true;

	return false;
}

Krawedz HeapMin::getRoot()
{
	return arr[0];
}

void HeapMin::clearHeap()
{
	if (size > 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
	else
		return;
}

HeapMin::HeapMin()
{
}

HeapMin::~HeapMin()
{
	clearHeap();
}
