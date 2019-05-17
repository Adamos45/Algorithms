#pragma once
#include"kopiec.h"
#include"macierz_sasiedztw.h"
#include<string>

class Kopiec;

class Bellman
{
private:
	Lista* lista=nullptr;
	Tablica* tablica=nullptr;
	int *d;
	int *p;
	int start;
	int En;
public:
	Bellman();
	~Bellman();
	Bellman(Lista* _lista);
	Bellman(Tablica* _tablica);
	bool Execute(bool is_List);
	void show();
};