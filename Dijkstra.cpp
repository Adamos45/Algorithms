#include"Dijkstra.h"

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
	delete[] tab;
	delete[] SQ;
}

Dijkstra::Dijkstra(Lista _lista)
{
	lista = _lista;
	En = _lista.getVertexSize();
	tab = new Node[En];
	tab[0] = Node{ 0,0,-1 };
	for (int i = 1; i < En; i++)
		tab[i] = Node{ i,INT_MAX-1000,-1 };
	SQ = new bool[En];
	for (int i = 0; i < En; i++)
		SQ[i] = false;
	start = _lista.getStart();
}

Dijkstra::Dijkstra(Tablica * _tablica)
{
}

void Dijkstra::Execute()
{
	int x = start;
	bool check_complete = false;
	while (check_complete == false)
	{
		SQ[x] = true;
		for (int i = 0; i < lista.getVertexSize(x); i++)
		{
			if (SQ[lista.getNode(x, i)->Vk] == false && (tab[lista.getNode(x, i)->Vk].Vk > tab[x].Vk + lista.getNode(x, i)->w))
			{
				tab[lista.getNode(x, i)->Vk].Vk = tab[x].Vk + lista.getNode(x, i)->w;
				tab[lista.getNode(x, i)->Vk].w = x;
			}
		}
		int temp = INT_MAX-1000;
		for (int i = 0; i < En; i++)
		{
			if (SQ[i] == false && tab[i].Vk < temp)
			{
				x = i;
				temp = tab[x].Vk;
			}
		}
		SQ[x] = true;

		check_complete = true;
		for (int i = 0; i < En; i++)
		{
			if (SQ[i] == false)
				check_complete = false;
			continue;
		}
	}
}

void Dijkstra::show()
{
	for (int i = 0; i < En; i++)
		std::cout << tab[i].Vp << tab[i].Vk << tab[i].w << std::endl;
	std::string path = "";
	for (int i = 0; i < En; i++)
	{
		std::cout << "Z 0 do " << i << ": ";
		int p = tab[i].w;
		path = std::to_string(tab[i].Vp);
		while (p != -1)
		{
			path += " " + std::to_string(tab[p].Vp);
			p = tab[p].w;
		}
		std::reverse(path.begin(), path.end());
		std::cout << path << " Koszt: " << tab[i].Vk<< std::endl;
	}
}
