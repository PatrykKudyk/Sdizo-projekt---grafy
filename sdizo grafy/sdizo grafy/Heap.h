#pragma once

class Heap
{
	int size;
	int *arr;
public:
	void push(int val);
	void pop();
	void find(int val);
	void clearHeap();
	Heap();
	~Heap();
};

