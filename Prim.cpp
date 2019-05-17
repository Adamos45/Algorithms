#include"Prim.h"

Prim::Prim()
{
}

Prim::~Prim()
{
	delete[]results;
}

Prim::Prim(Lista * _lista)
{
	lista = _lista;
	En = _lista->getVertexSize();
	results = new Node[En];
	kopiec = new Kopiec();
	seen = new int[1];
	seenSize = 1;
}

Prim::Prim(Tablica * _tablica)
{
	tablica = _tablica;
	En = _tablica->getRowSize();
	results = new Node[En];
	kopiec = new Kopiec();
	seen = new int[1];
	seenSize = 1;
}

void Prim::Execute(bool is_list)
{
	int x = 0;
	seen[0] = 0;
	if (is_list)
	{
		for (int z = 0; z < En-1; z++)
		{
			for (int j = 0; j < lista->getVertexSize(x); j++)
			{
				for (int b = 0; b < seenSize; b++)
				{
					if (lista->getNode(x, j)->Vk == seen[b])
					{
						goto nextJL;
					}
				}
				kopiec->addMemory(1);
				kopiec->dodaj(*lista->getNode(x, j));
			nextJL: {}
			}
			Node p;
			bool check1 = false,check2=false,check=true;
			while (check)
			{
				check = false;
				check1 = false;
				check2 = false;
				p = kopiec->usun();
				for (int i = 0; i < seenSize; i++)
				{
					if (p.Vp == seen[i])
					{
						check1 = true;
					}
					if (p.Vk == seen[i])
					{
						check2 = true;
					}
				}
				if (check1 == true && check2 == true)
					check = true;
			}
			results[z] = p;
			resultsSize++;
			x = results[z].Vk;
			int *temp = new int[seenSize + 1];
			for (int i = 0; i < seenSize; i++)
				temp[i] = seen[i];
			if (seenSize)
				delete[]seen;
			seen = temp;
			seen[seenSize] = x;
			seenSize++;
		}
	}
	else
	{
		for (int z = 0; z < En - 1; z++)
		{
			for (int j = 0; j < En; j++)
			{
				if (tablica->getValue(x, j) == INT_MAX - 1000)
					continue;
				for (int b = 0; b < seenSize; b++)
				{
					if (j == seen[b])
					{
						goto nextJT;
					}
				}
				kopiec->addMemory(1);
				kopiec->dodaj(Node{ x,j,tablica->getValue(x,j) });
				nextJT: {}
			}
			Node p;
			bool check1 = false, check2 = false, check = true;
			while (check)
			{
				check = false;
				check1 = false;
				check2 = false;
				p = kopiec->usun();
				for (int i = 0; i < seenSize; i++)
				{
					if (p.Vp == seen[i])
					{
						check1 = true;
					}
					if (p.Vk == seen[i])
					{
						check2 = true;
					}
				}
				if (check1 == true && check2 == true)
					check = true;
			}
			results[z] = p;
			resultsSize++;
			x = results[z].Vk;
			int *temp = new int[seenSize + 1];
			for (int i = 0; i < seenSize; i++)
				temp[i] = seen[i];
			if (seenSize)
				delete[]seen;
			seen = temp;
			seen[seenSize] = x;
			seenSize++;
		}
	}
}

void Prim::show()
{
	int x = 0;
	for (int i = 0; i < resultsSize; i++)
	{
		std::cout <<results[i].Vp << ':' << results[i].Vk <<' '<< results[i].w<<std::endl;
		x += results[i].w;
	}
	std::cout << "Koszt: " << x << std::endl;
}
