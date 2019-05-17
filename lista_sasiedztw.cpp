#include"lista_sasiedztw.h"

Lista::Lista()
{
}

Lista::~Lista()
{
	for (int i = 0; i < Vn; i++)
		if (listArray[i] != nullptr)
			delete listArray[i];
	if (listArray != nullptr)
		delete[]listArray;
	if(listArraySizes!=nullptr)
		delete listArraySizes;
}

Lista::Lista(int _En, int _Vn, int _Vp, int _Vk)
{
	En=_En;
	Vn=_Vn;
	Vp=_Vp;
	Vk=_Vk;
	listArray = new Node*[Vn];
	for (int i = 0; i < Vn; i++)
		listArray[i] = nullptr;
	listArraySizes = new int[Vn];
	for (int i = 0; i < Vn; i++)
		listArraySizes[i] = 0;
}

void Lista::add(int Vp,int Vk,int w)
{
	Node *p = new Node{ Vp,Vk,w };
	Node *i = listArray[Vp];
	Node *j = nullptr;
	while (i != nullptr)
	{
		j = i;
		i = i->next;
	}
	if (j == nullptr)
		listArray[Vp] = p;
	else
	{
		j->next = p;
		p->prev = j;
		i = nullptr;
	}
	listArraySizes[Vp]++;
	listSize++;
}

void Lista::show()
{
	Node *a, *b;
	for (int i = 0; i < Vn; i++)
	{
		std::cout << i << "| ";
		a = listArray[i];
		while (a != nullptr)
		{
			b = a;
			std::cout << b->Vk << ':' << b->w << ' ';
			a = a->next;
		}
		std::cout << std::endl;
	}
}
Node* Lista::getNode(int x, int y)
{
	Node* p;
	p = listArray[x];
	for (int i = 0; i < y; i++)
		p = p->next;
	return p;
}

int Lista::getVertexSize(int V)
{
	return listArraySizes[V];
}

int Lista::getListSize()
{
	return listSize;
}

int Lista::getVertexSize()
{
	return Vn;
}

int Lista::getStart()
{
	return Vp;
}

void Lista::setEn(int x)
{
	En = x;
}
