#pragma once
#include"lista_sasiedztw.h"
#include"macierz_sasiedztw.h"
#include"kopiec.h"

class Prim
{
private:
	Lista* lista;
	Tablica* tablica;
	Kopiec* kopiec;
	Node* results;
	int* seen;
	int seenSize;
	int resultsSize = 0;
	int En;
public:
	Prim();
	~Prim();
	Prim(Lista *_lista);
	Prim(Tablica *_tablica);
	void Execute(bool is_list);
	void show();
};