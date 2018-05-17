#include "Heap.h"
#include <iostream>


using namespace std;

void Heap::push(int val)
{
	int *pom = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
		pom[i] = this->arr[i];

	if (this->size == 0)
		delete this->arr;
	else
		delete[] this->arr;
	this->arr = pom;

	int i = this->size;
	int j = (i - 1) / 2;
	while (i > 0 && this->arr[j] < val)
	{
		this->arr[i] = this->arr[j];
		i = j;
		j = (i - 1) / 2;
	}
	this->arr[i] = val;
	this->size++;
}

void Heap::pop()
{
	if (this->size == 1)
	{
		int *pom = new int;
		delete[] this->arr;
		this->arr = pom;
		this->size = 0;
	}
	else
	{
		this->arr[0] = this->arr[this->size - 1]; // ustawiam wartosc pierwszego elementu na wartosc ostatniego
		int *pom = new int[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
			pom[i] = this->arr[i];
		delete[] this->arr;
		this->arr = pom;
		this->size--;
	}

	if (this->size - 1)
	{
		int v = this->arr[0];
		int i = 0, j = 1;
		while (j < this->size)
		{
			if (j + 1 < this->size && this->arr[j + 1] > this->arr[j])
				j++;
			if (v >= this->arr[j])
				break;
			this->arr[i] = this->arr[j];
			i = j;
			j = 2 * j + 1;
		}
		this->arr[i] = v;
	}
	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Heap::find(int val)
{
	int index;
	bool found = false;

	for (int i = 0; i < this->size; i++)
		if (this->arr[i] == val)
		{
			found = true;
			index = i;
			break;
		}
	if (found)
		cout << "Znalazlem zadana liczbe! (" << val << ")" << endl
		<< "Znajduje sie ona pod indeksem : " << index << " z zakresu <0," << this->size - 1 << ">" << endl;
	else
		cout << "Niestety, ale nie udalo sie znalezc zadanej przez Ciebie liczby. (" << val << ")" << endl;

	cin.get();
	cin.get();
	system("cls");
}

void Heap::clearHeap()
{
	if (this->size > 0)
	{
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
	else
		return;
}

Heap::Heap()
{
}

Heap::~Heap()
{
	clearHeap();
}
