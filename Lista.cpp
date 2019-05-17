#include "Lista.h"

ListaOneDirect::~ListaOneDirect()
{
	if (head != nullptr)
	{
		smallNode *p = head;
		smallNode *next = head->next;
		while(next!=nullptr)
		{
			delete p;
			p = next;
			next = p->next;
		}
		delete p;
	}
}

void ListaOneDirect::dodajkon(int x)
{
	if (tail == nullptr)
	{
		smallNode *p = new smallNode{ nullptr,nullptr,x };
		head = tail = p;
	}
	else
	{
		smallNode *p = new smallNode{ tail,nullptr,x };
		tail->next = p;
		tail = p;
	}
	length++;
}

void ListaOneDirect::odejmijpocz()
{
	if (head != nullptr)
	{
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
		length--;
	}
}

int ListaOneDirect::getNode()
{
	return head->val;
}

int ListaOneDirect::getLength()
{
	return length;
}

bool ListaOneDirect::wyszukiwanie(int y)
{
	smallNode *p = head;
	while (p != nullptr)
	{
		if (p->val == y)
			return true;
		p = p->next;
	}
	return false;
}