#include"Bellman.h"

Bellman::Bellman()
{
}

Bellman::~Bellman()
{}

Bellman::Bellman(Lista* _lista)
{
	En = _lista->getVertexSize();
	lista = _lista;
	start = _lista->getStart();
	d = new int[En];
	p = new int[En];
	for (int i = 0; i < start; i++)
		d[i] = INT_MAX-1000;
	for (int i = start+1; i < En; i++)
		d[i] = INT_MAX - 1000;
	d[start] = 0;
	for (int i = 0; i < En; i++)
		p[i] = -1;
}

Bellman::Bellman(Tablica * _tablica)
{
	tablica = _tablica;
	En = _tablica->getRowSize();
	start = _tablica->getStart();
	d = new int[En];
	p = new int[En];
	for (int i = 0; i < start; i++)
		d[i] = INT_MAX - 1000;
	for (int i = start + 1; i < En; i++)
		d[i] = INT_MAX - 1000;
	d[start] = 0;
	for (int i = 0; i < En; i++)
		p[i] = -1;
}

bool Bellman::Execute(bool is_List)
{
	bool check_changes = false;
	if (is_List)
	{
		for (int z = 0; z < En; z++)
		{
			for (int j = 0; j < En; j++)
			{
				for (int i = 0; i < lista->getVertexSize(j); i++)
				{
					if (d[lista->getNode(j, i)->Vk] > lista->getNode(j, i)->w + d[lista->getNode(j, i)->Vp])
					{
						d[lista->getNode(j, i)->Vk] = lista->getNode(j, i)->w + d[lista->getNode(j, i)->Vp];
						p[lista->getNode(j, i)->Vk] = lista->getNode(j, i)->Vp;
						check_changes = true;
					}
				}
			}
			if (check_changes == false)
			{
				for (int j = 0; j < En; j++)
				{
					for (int i = 0; i < lista->getVertexSize(j); i++)
					{
						if (d[lista->getNode(j, i)->Vk] > lista->getNode(j, i)->w + d[lista->getNode(j, i)->Vp])
						{
							d[lista->getNode(j, i)->Vk] = lista->getNode(j, i)->w + d[lista->getNode(j, i)->Vp];
							p[lista->getNode(j, i)->Vk] = lista->getNode(j, i)->Vp;
							check_changes = true;
						}
					}
				}
				if (check_changes == true)
					return false;
				else
					return true;
			}
		}
	}
	else
	{
		{
			for (int z = 0; z < En; z++)
			{
				for (int i = 0; i < En; i++)
				{
					for (int j = 0; j < En; j++)
					{
						if (tablica->getValue(i, j) != INT_MAX - 1000 && d[j] > tablica->getValue(i, j) + d[i])
						{
							d[j] = tablica->getValue(i, j) + d[i];
							p[j] = i;
							check_changes = true;
						}
					}
				}
				if (check_changes == false)
				{
					for (int i = 0; i < En; i++)
					{
						for (int j = 0; j < En; j++)
						{
							if (tablica->getValue(i, j) != INT_MAX - 1000 && d[j] > tablica->getValue(i, j) + d[i])
							{
								d[j] = tablica->getValue(i, j) + d[i];
								p[j] = i;
								check_changes = true;
							}
						}
					}
					if (check_changes == true)
						return false;
					else
						return true;
				}
			}
		}
	}
	return true;
}

void Bellman::show()
{
	//for (int i = 0; i < En; i++)
	//	std::cout << tab->getElem(i).Vp << tab->getElem(i).w << tab->getElem(i).Vk << std::endl;
	std::cout << "Wierzcholek poczatkowy: " << start << std::endl;
	std::string path;
	for (int i = 0; i < En; i++)
	{
		path = std::to_string(i);
		int p = i;
		std::cout << "Z " << start << " do " << i << ": ";
		p = p[this->p];
		while (p != -1)
		{
			path += " " + std::to_string(p);
			p = p[this->p];
		}
		std::reverse(path.begin(), path.end());
		std::cout << path << " Koszt: ";
		if (d[i] == INT_MAX-1000)
			std::cout << "oo" << std::endl;
		else
			std::cout << d[i] << std::endl;
	}
}