#include"macierz_sasiedztw.h"

Tablica::Tablica()
{
	tab = nullptr;
}
Tablica::~Tablica()
{
	for(int i=0;i<Vn;i++)
		delete[] tab[i];
	delete[] tab;
	Vn = 0;
}
Tablica::Tablica(int _En, int _Vn, int _Vp, int _Vk)
{
	En = _En;
	Vn = _Vn;
	Vp = _Vp;
	Vk = _Vk;
	tab = new int*[Vn];
	for (int i = 0; i < Vn; i++)
		tab[i] = new int[Vn];
	for (int i = 0; i < Vn; i++)
		for (int j = 0; j < Vn; j++)
			tab[i][j] = INT_MAX-1000;
}

void Tablica::LoadEdge(int Vp, int Vk, int w)
{
	tab[Vp][Vk] = w;
}

void Tablica::ShowTab()
{
	for (int i = 0; i < Vn; i++)
	{
		for (int j = 0; j < Vn; j++)
			if (tab[i][j] == INT_MAX-1000)
				std::cout << "oo ";
			else
				std::cout << tab[i][j]<<' ';
		std::cout << std::endl;
	}
}

int Tablica::getRowSize()
{
	return Vn;
}

int Tablica::getValue(int x, int y)
{
	return tab[x][y];
}

int Tablica::getEdgesNumber()
{
	return En;
}

int Tablica::getStart()
{
	return Vp;
}

void Tablica::setEn(int x)
{
	En = x;
}
