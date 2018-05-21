#include <iostream>
#include <ctime>
#include "Menu.h"
#include "TimeMeasure.h"

using namespace std;

int main()
{
	Menu menu;
	menu.menuGlowne();
	/*GrafMacierz lista;
	TimeMeasure time;
	
	vector<double> czasy;

	int vertices = 50;

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 25);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "25% - " << i+1 << " - 50 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "50Wierzcholkowtime25.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 50);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "50% - " << i + 1 << " - 50 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "50Wierzcholkowtime50.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 75);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "75% - " << i + 1 << " - 50 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "50Wierzcholkowtime75.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 99);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "99% - " << i + 1 << " - 50 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "50Wierzcholkowtime99.txt");
	czasy.clear();

	vertices = 25;

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 25);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "25% - " << i + 1 << " - 25 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "25Wierzcholkowtime25.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 50);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "50% - " << i + 1 << " - 25 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "25Wierzcholkowtime50.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 75);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "75% - " << i + 1 << " - 25 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "25Wierzcholkowtime75.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 99);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "99% - " << i + 1 << " - 25 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "25Wierzcholkowtime99.txt");
	czasy.clear();

	vertices = 75;

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 25);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "25% - " << i + 1 << " - 75 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "75Wierzcholkowtime25.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 50);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "50% - " << i + 1 << " - 75 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "75Wierzcholkowtime50.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 75);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "75% - " << i + 1 << " - 75 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "75Wierzcholkowtime75.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 99);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "99% - " << i + 1 << " - 75 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "75Wierzcholkowtime99.txt");
	czasy.clear();

	vertices = 100;

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 25);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "25% - " << i + 1 << " - 100 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "100Wierzcholkowtime25.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 50);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "50% - " << i + 1 << " - 100 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "100Wierzcholkowtime50.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 75);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "75% - " << i + 1 << " - 100 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "100Wierzcholkowtime75.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 99);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "99% - " << i + 1 << " - 100 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "100Wierzcholkowtime99.txt");
	czasy.clear();

	vertices = 125;

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 25);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "25% - " << i + 1 << " - 125 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "125Wierzcholkowtime25.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 50);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "50% - " << i + 1 << " - 125 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "125Wierzcholkowtime50.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 75);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "75% - " << i + 1 << " - 125 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "125Wierzcholkowtime75.txt");
	czasy.clear();

	for (int i = 0; i < 100; i++)
	{
		int vertex1 = rand() % vertices;
		int vertex2 = rand() % vertices;
		menu.genRand(vertices, 99);
		lista.createRandom();
		time.startCounting();
		lista.prim();
		double czas = time.getCounter();
		czasy.push_back(czas);
		cout << "99% - " << i + 1 << " - 125 wierzcholkow" << endl;
	}
	time.saveToFile(czasy, "125Wierzcholkowtime99.txt");
	czasy.clear();

	cin.get();
	cin.get();*/
	exit(EXIT_SUCCESS);
}
