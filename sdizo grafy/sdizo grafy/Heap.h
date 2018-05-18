#pragma once

class Heap
{
	int size;
	int *arr;
public:
	void push(int val);
	void pop();
	bool isEmpty();
	int getRoot();
	void find(int val);
	void clearHeap();
	Heap();
	~Heap();
};

