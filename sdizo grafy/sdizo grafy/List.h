#pragma once

//		LISTA JEDNOKIERYNKOWA DO U¯YCIA W GRAFIE SKIEROWANYM
struct Node
{
	Node *next;
	int data;
	int waga;
};

class List
{
	int size;
	Node *head;
public:
	void push(int data, int waga);
	void clearList();
	Node* getHead();
	List();
	~List();
};