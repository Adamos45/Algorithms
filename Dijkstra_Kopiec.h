#pragma once
#include"kopiec.h"
#include"macierz_sasiedztw.h"
#include<string>

class Kopiec;

class DijkstraKopiec
{
private:
	Kopiec*tab;
	int En;
	Lista* lista;
	Tablica* tablica;
	bool *SQ;
	int start;
public:
	DijkstraKopiec();
	~DijkstraKopiec();
	DijkstraKopiec(Lista* _lista);
	DijkstraKopiec(Tablica* _tablica);
	void Execute(bool is_List);
	void show();
};