#pragma once

class HeapMin
{
	int size;
	int *arr;
public:
	void push(int val);
	void pop();
	bool isEmpty();
	int getRoot();
	void clearHeap();
	HeapMin();
	~HeapMin();
};
