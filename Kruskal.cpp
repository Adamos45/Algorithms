#include"Kruskal.h"

Kruskal::~Kruskal()
{
	
	for (int i = 0; i < LTSize; i++)
		if (tab[i] != nullptr)
			delete tab[i];

	if (tab != nullptr)
		delete[] tab;
	
	if (results != nullptr)
		delete results;

}

Kruskal::Kruskal()
{
}

Kruskal::Kruskal(Lista *_lista)
{
	LTSize = _lista->getVertexSize();
	En = _lista->getListSize();
	kopiec = new Kopiec(En);
	for (int i = 0; i < LTSize; i++)
		for (int j = 0; j < _lista->getVertexSize(i); j++)
			kopiec->dodaj(*_lista->getNode(i, j));
	
	tab = new RankNode*[_lista->getVertexSize()];
	for (int i = 0; i < LTSize; i++)
		tab[i] = new RankNode{ i,nullptr,0 };
}

Kruskal::Kruskal(Tablica* _tablica)
{
	LTSize = _tablica->getRowSize();
	En = _tablica->getEdgesNumber();
	En *= 2;
	kopiec = new Kopiec(En);
	for (int i = 0; i < LTSize; i++)
		for (int j = 0; j < LTSize; j++)
			if (_tablica->getValue(i, j) != INT_MAX - 1000)
				kopiec->dodaj(Node{ i,j,_tablica->getValue(i,j) });
	
	tab = new RankNode*[LTSize];
	for (int i = 0; i < LTSize; i++)
		tab[i] = new RankNode{ i,nullptr,0 };
}

void Kruskal::Execute()
{
	for (int i = 0; i < En-1; i++)
	{
		Node p = kopiec->usun();
		int x = p.Vp;
		int y = p.Vk;
		while (tab[x]->father != nullptr)
		{
			x = tab[x]->father->number;
		}
		while (tab[y]->father != nullptr)
		{
			y = tab[y]->father->number;
		}
		if (x != y)
		{
			if (results == nullptr)
			{
				results = new Node{ p.Vp,p.Vk,p.w };
				results_Sum += p.w;
			}
			else
			{
				Node *temp=results;
				Node *temp2;
				while (temp != nullptr)
				{
					temp2 = temp;
					temp = temp->next;
				}
				temp2->next = new Node{ p.Vp,p.Vk,p.w };
				results_Sum += p.w;
			}
			if (tab[x]->Rank >= tab[y]->Rank)
			{
				tab[y]->father = tab[x];
				tab[x]->Rank++;
			}
			else
			{
				tab[x]->father = tab[y];
				tab[y]->Rank++;
			}
		}
	}
}

void Kruskal::show()
{
	if (results != nullptr)
	{
		Node *temp = results;
		Node *temp2;
		while (temp != nullptr)
		{
			temp2 = temp;
			std::cout << temp2->Vp << ":" << temp2->Vk << " " << temp2->w << std::endl;
			temp = temp->next;
		}
		std::cout << "Waga minimalnego drzewa: "<<results_Sum << std::endl;
	}
}
