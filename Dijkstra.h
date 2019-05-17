#pragma once
#include"kopiec.h"
#include"macierz_sasiedztw.h"
#include<string>

class Kopiec;

class Dijkstra
{
private:
	Node*tab;
	int En;
	Lista lista;
	bool *SQ;
	int start;
public:
	Dijkstra();
	~Dijkstra();
	Dijkstra(Lista _lista);
	Dijkstra(Tablica* _tablica);
	void Execute();
	void show();
};