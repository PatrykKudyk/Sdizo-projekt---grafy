#pragma once

struct Krawedz
{
	int wPocz;
	int wKonc;
	int waga;
};


class HeapMin
{
	int size;
	Krawedz *arr;
public:
	void push(int wP, int wK, int waga);
	void pop();
	bool isEmpty();
	Krawedz getRoot();
	void clearHeap();
	HeapMin();
	~HeapMin();
};
