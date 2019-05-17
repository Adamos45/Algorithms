#pragma once
#include"kopiec.h"
#include"lista_sasiedztw.h"
#include"macierz_sasiedztw.h"


class Kruskal
{
private:
	struct RankNode
	{
		int number;
		RankNode* father;
		int Rank;
	};
	Kopiec* kopiec=nullptr;
	RankNode** tab=nullptr;
	int En;
	Node* results=nullptr;
	int results_Sum=0;
	int LTSize;
public:
	~Kruskal();
	Kruskal();
	Kruskal(Lista *_lista);
	Kruskal(Tablica* _tablica);
	void Execute();
	void show();
};