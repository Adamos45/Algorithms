#include"Dijkstra_Kopiec.h"

DijkstraKopiec::DijkstraKopiec()
{
}

DijkstraKopiec::~DijkstraKopiec()
{
	tab = nullptr;
	delete[] SQ;
}

DijkstraKopiec::DijkstraKopiec(Lista* _lista)
{
	lista = _lista;
	En = _lista->getVertexSize();
	tab = new Kopiec(En);
	start = _lista->getStart();
	tab->dodaj(Node{ start,-1,0 });
	for (int i = 0; i < start; i++)
		tab->dodaj(Node{ i,-1,INT_MAX-1000 });
	for (int i = start+1; i < En; i++)
		tab->dodaj(Node{ i,-1,INT_MAX-1000 });
	SQ = new bool[En];
	for (int i = 0; i < En; i++)
		SQ[i] = false;
}

DijkstraKopiec::DijkstraKopiec(Tablica * _tablica)
{
	tablica = _tablica;
	En = _tablica->getRowSize();
	tab = new Kopiec(En);
	start = _tablica->getStart();
	tab->dodaj(Node{ start,-1,0 });
	for (int i = 0; i < start; i++)
		tab->dodaj(Node{ i,-1,INT_MAX-1000 });
	for (int i = start + 1; i < En; i++)
		tab->dodaj(Node{ i,-1,INT_MAX-1000 });
	SQ = new bool[En];
	for (int i = 0; i < En; i++)
		SQ[i] = false;
}

void DijkstraKopiec::Execute(bool is_List)
{
	int x = start;
	SQ[x] = true;
	bool check_complete = false;
	if (is_List)
	{
		while (check_complete == false)
		{
			for (int i = 0; i < lista->getVertexSize(x); i++)
			{
				if (SQ[lista->getNode(x, i)->Vk] == false && (tab->getElem(tab->find(lista->getNode(x, i)->Vk)).w > tab->getElem(tab->find(x)).w + lista->getNode(x, i)->w))
				{
					tab->modifysecond(tab->getElem(tab->find(x)).w + lista->getNode(x, i)->w, tab->find(lista->getNode(x, i)->Vk));
					tab->modifythird(x, tab->find(lista->getNode(x, i)->Vk));
				}
			}
			int temp = INT_MAX-1000;
			bool found = false;
			for (int i = 0; i < En; i++)
			{
				if (tab->getElem(i).w < temp && SQ[tab->getElem(i).Vp] == false)
				{
					x = tab->getElem(i).Vp;
					temp = tab->getElem(tab->find(x)).w;
					found = true;
				}
			}
			if (found == false)
			{
				for (int i = 0; i < En; i++)
					SQ[i] = true;
			}
			SQ[x] = true;
			check_complete = true;
			for (int i = 0; i < En; i++)
			{
				if (SQ[i] == false)
					check_complete = false;
			}
		}
	}
	else
	{
		while (check_complete == false)
		{
			for (int i = 0; i < tablica->getRowSize(); i++)
			{
				if (tablica->getValue(x, i) != INT_MAX-1000 && SQ[i] == false && (tab->getElem(tab->find(i)).w > tab->getElem(tab->find(x)).w + tablica->getValue(x, i)))
				{
					tab->modifysecond(tab->getElem(tab->find(x)).w + tablica->getValue(x, i), tab->find(i));
					tab->modifythird(x, tab->find(i));
				}
			}
			int temp = INT_MAX-1000;
			bool found = false;
			for (int i = 0; i < En; i++)
			{
				if (tab->getElem(i).w < temp && SQ[tab->getElem(i).Vp] == false)
				{
					x = tab->getElem(i).Vp;
					temp = tab->getElem(tab->find(x)).w;
					found = true;
				}
			}
			if (found == false)
			{
				for (int i = 0; i < En; i++)
					SQ[i] = true;
			}
			SQ[x] = true;
			check_complete = true;
			for (int i = 0; i < En; i++)
			{
				if (SQ[i] == false)
					check_complete = false;
			}
		}
	}
}

void DijkstraKopiec::show()
{
	//for (int i = 0; i < En; i++)
	//	std::cout << tab->getElem(i).Vp << tab->getElem(i).w << tab->getElem(i).Vk << std::endl;
	std::cout << "Wierzcholek poczatkowy: " << start << std::endl;
	std::string path;
	for (int i = 0; i < En; i++)
	{
		
		path = std::to_string(i);
		int p = tab->getElem(tab->find(i)).Vk;
		std::cout << "Z " << start << " do " << i << ": ";
		while (p != -1)
		{
			path += " " + std::to_string(p);
			p = tab->getElem(tab->find(p)).Vk;
		}
		std::reverse(path.begin(), path.end());
		std::cout << path << " Koszt: "; 
		if (tab->getElem(tab->find(i)).w == INT_MAX-1000)
			std::cout << "oo" << std::endl;
		else
			std::cout << tab->getElem(tab->find(i)).w << std::endl;
	}
}
